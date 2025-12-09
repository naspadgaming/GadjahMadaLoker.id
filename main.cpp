#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <cpprest/filestream.h>
#include <fstream>

using namespace web;
using namespace http;
using namespace http::experimental::listener;

// ================================
// KONFIGURASI SUPABASE
// ================================
string SUPABASE_URL = "https://xxx.supabase.co";
string SUPABASE_KEY = "service_role_key";

string STORAGE_URL = SUPABASE_URL + "/storage/v1/object/cv/";
string DB_URL = SUPABASE_URL + "/rest/v1/cv_uploads";


// ================================
// FUNGSI: Upload file ke Supabase
// ================================
string uploadToSupabase(const string& filename, const string& filepath) {
    http_client client(U(STORAGE_URL + filename));

    std::ifstream file(filepath, ios::binary);
    std::vector<uint8_t> fileData((std::istreambuf_iterator<char>(file)), {});

    http_request req(methods::PUT);
    req.headers().add(U("apikey"), U(SUPABASE_KEY));
    req.headers().add(U("Content-Type"), U("application/pdf"));
    req.set_body(fileData);

    auto response = client.request(req).get();

    if (response.status_code() != 200 && response.status_code() != 201) {
        return "";
    }

    return SUPABASE_URL + "/storage/v1/object/public/cv/" + filename;
}


// ================================
// FUNGSI: Simpan URL ke database
// ================================
void saveToDatabase(string nama, string email, string url) {
    http_client client(U(DB_URL));

    json::value body;
    body[U("nama_pengguna")] = json::value::string(nama);
    body[U("email")] = json::value::string(email);
    body[U("cv_url")] = json::value::string(url);

    http_request req(methods::POST);
    req.headers().add(U("apikey"), U(SUPABASE_KEY));
    req.headers().add(U("Content-Type"), U("application/json"));
    req.set_body(body);

    client.request(req).get();
}


// ================================
// API HANDLER
// ================================
void handlePost(http_request request) {
    auto queries = uri::split_query(request.request_uri().query());

    string nama = conversions::to_utf8string(queries[U("nama")]);
    string email = conversions::to_utf8string(queries[U("email")]);

    string filePath = "uploaded.pdf";
    ofstream out(filePath, ios::binary);
    out << request.extract_vector().get();
    out.close();

    string fileName = email + "_cv.pdf";

    // Upload
    string url = uploadToSupabase(fileName, filePath);

    // Simpan ke database
    saveToDatabase(nama, email, url);

    json::value response;
    response[U("status")] = json::value::string("OK");
    response[U("url")] = json::value::string(url);

    request.reply(status_codes::OK, response);
}


// ================================
// API: GET CV BY EMAIL
// ================================
void handleGet(http_request request) {
    auto queries = uri::split_query(request.request_uri().query());
    string email = conversions::to_utf8string(queries[U("email")]);

    http_client client(U(DB_URL + "?email=eq." + email));

    http_request req(methods::GET);
    req.headers().add(U("apikey"), U(SUPABASE_KEY));

    auto response = client.request(req).get();
    auto data = response.extract_json().get();

    request.reply(status_codes::OK, data);
}


// ================================
// MAIN API SERVER
// ================================
int main() {
    http_listener listener(U("http://0.0.0.0:8080"));

    listener.support(methods::POST, handlePost);
    listener.support(methods::GET, handleGet);

    listener.open().wait();
    std::cout << "API berjalan di port 8080\n";

    while (true);
    return 0;
}
