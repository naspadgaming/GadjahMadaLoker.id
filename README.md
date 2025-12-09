# GadjahMadaLoker.id 
Sistem Informasi Lowongan dan Pengelolaan CV

## **1. Tentang Proyek**

GadjahmadaLoker adalah sebuah aplikasi web yang dirancang untuk menyediakan informasi lowongan pekerjaan sekaligus memfasilitasi pengelolaan berkas CV pengguna. Sistem ini dibangun menggunakan kombinasi antara frontend berbasis HTML/CSS/JavaScript dan backend REST API berbasis C++.

Aplikasi ini mendukung proses unggah CV, penyimpanan berkas ke server, serta integrasi dengan layanan database pihak ketiga. Dengan demikian, data yang dikirimkan pengguna dapat diolah, disimpan, dan diakses oleh admin atau pihak ketiga secara aman dan terstruktur.

Tujuan utama proyek ini adalah menyediakan platform lowongan kerja yang ringkas, cepat, mudah diakses, serta memiliki alur manajemen berkas yang jelas dan terintegrasi.

---

## **2. Fitur Utama**

### **a. Pencarian dan Informasi Lowongan**

* Menyediakan daftar lowongan pekerjaan yang dapat diperbarui oleh admin.
* Tampilan responsif, ringan, dan mudah dinavigasi.
* Filter pencarian dapat ditambahkan pada pengembangan berikutnya.

### **b. Upload Curriculum Vitae (CV)**

* Pengguna dapat mengunggah CV dalam format file tertentu (misalnya PDF atau DOCX).
* File yang diunggah akan diteruskan ke server melalui REST API.
* File disimpan pada direktori server dan informasinya dicatat di database pihak ketiga.

### **c. REST API Backend (C++)**

* Backend dibangun menggunakan C++ dengan pustaka HTTP server (misalnya cpp-httplib).
* Mendukung permintaan HTTP GET, POST, dan pengiriman berkas.
* Mengolah request dari frontend dan menghubungkannya dengan database.

### **d. Integrasi Database Pihak Ketiga**

* Basis data tidak disimpan secara lokal pada hosting server C++.
* Sistem menggunakan layanan database pihak ketiga (seperti Supabase, Firebase, PlanetScale, dsb.).
* API bertugas mengirim data metadata file (nama, path, waktu upload, user ID) ke database tersebut.

---

## **3. Alur Penggunaan Sistem**

1. **Pengguna membuka halaman utama** dan melihat daftar lowongan pekerjaan.
2. Ketika ingin melamar, pengguna dapat **mengisi data dan mengunggah CV** melalui form yang tersedia.
3. Berkas CV dikirim oleh browser ke REST API backend.
4. **Server C++ menerima file**, menyimpannya ke folder server, dan mencatat datanya ke database pihak ketiga.
5. Admin atau pihak ketiga dapat **mengakses data lowongan dan daftar CV** melalui dashboard atau endpoint API.
6. Sistem dapat dikembangkan lebih lanjut sehingga file CV dapat dianalisis, diproses, atau diunduh kembali.

---

## **4. Rancangan dan Arah Pengembangan**

Proyek ini masih dapat dikembangkan lebih lanjut dengan beberapa rencana berikut:

### **a. Pengembangan Fitur**

* Penambahan sistem login untuk pelamar dan admin.
* Menambahkan fitur rekomendasi lowongan.
* Menampilkan status lamaran pengguna.
* Dashboard admin untuk melihat dan mengelola CV.

### **b. Penguatan Keamanan**

* Validasi file upload (ukuran, ekstensi, konten).
* Rate limiting pada REST API.
* Token authentication (JWT atau API key).

### **c. Optimalisasi Backend**

* Implementasi struktur folder backend yang lebih modular.
* Penggunaan thread pool atau async I/O untuk menambah performa.
* Logging server yang lebih lengkap.

### **d. Pengembangan Infrastruktur**

* Integrasi CDN untuk penyimpanan file.
* Deployment REST API dalam container (Docker).
* CI/CD untuk otomatisasi build dan deployment.

Backend Program pada web ini masih bersifat simulasi, hanya memperlihatkan cara kerjanya saja. Bisa direalisasikan dengan pengembangan lanjutan.

## **5. Tujuan Jangka Panjang**

Proyek ini diharapkan menjadi platform lowongan kerja yang:

* Stabil dan mudah digunakan oleh pelamar.
* Fleksibel untuk dikembangkan lebih jauh oleh developer.
* Terintegrasi sepenuhnya dengan layanan database dan file storage modern.
* Dapat berkembang menuju layanan karir profesional yang lebih komprehensif.



