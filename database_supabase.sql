create table cv_uploads (
  id uuid primary key default gen_random_uuid(),
  nama_pengguna text not null,
  email text not null,
  cv_url text not null,
  tanggal_upload timestamp default now()
);
