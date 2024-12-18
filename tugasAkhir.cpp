/*Aplikasi Toko Kelontong Canggih, Kelompok 3 :
- Amrullah Azzaky         (2407051027)
- Zulfa Riana             (2407051006)
- Mohamad Farrel Pratama  (2477051014)
- Farida Agil Rahmadani   (2407051018)
- Defina Rahmayanti       (2407051023)
*/ 

#include <conio.h>
#include <bits\stdc++.h>

using namespace std;

int getIncrementBarang(string kode_barang);
int getLengthArray();
int autoIncrementKodeBarang();
int autoIncrement();
void menuKasir();
void menuAdmin();
void login();
void changePassword(char password[50]);
void tambahDataBarang();
void updateDataBarang();
void hapusDataBarang();
void hanyaTampilkanData();
void tampilDataBarang();
void struk(string jumlah_barang[6][6], int bayar, int kembalian, int jumlah, int total);
void transaksi();
void getCart(string jumlah_beli[6][6], int jumlah);
// char getch(void);

// data barang
string barang[10][5] = {
    {"1 ", "22001", "Beras_Bulog", "KG", "25000 "},
    {"2 ", "22002", "Gula_Pasir", "KG", "5000 "},
    {"3 ", "22003", "Minyak_Goreng", "Liter", "15000 "},
    {"4 ", "22004", "Susu_Dancow", "Gram", "20000 "},
    {"5 ", "22005", "Telur_Ayam", "KG", "20000 "}};

int main(int jumlahArgumen, char const *menyimpanArgumen[])
{

  login();

  return 0;
}

int getLengthArray()
{
  int i = 0;
  int nomor;
  for (i = 0; i < end(barang) - begin(barang); i++) //begin(barang) memberikan pointer ke elemen pertama, sedangkan end(barang) memberikan pointer ke elemen setelah elemen terakhir.
{
    if (barang[i][0] != "") // Mengecek jika elemen pertama tidak kosong
    {
      nomor = stoi(barang[i][0]); // Mengkonversi nilai string menjadi integer
    }
  }

  return nomor; // Mengembalikan nilai function
}

int autoIncrementKodeBarang()
{
  int i = 0;
  int kode_barang;
  for (i = 0; i < getLengthArray(); i++)
  {
    // get last kode_barang dalam array barang
    if (barang[i][0] != "")
    {
      kode_barang = stoi(barang[i][1]); // Mengkonversi nilai string menjadi integer
    }
  }
  kode_barang = kode_barang + 1;

  return kode_barang;
}

int autoIncrement()
{
  int i = 0;
  int nomor;
  for (i = 0; i < getLengthArray(); i++)
  {
    if (barang[i][0] != "")
    {
      nomor = stoi(barang[i][0]); // Mengkonversi nilai string menjadi integer
    }
  }

  return nomor;
}

// proses enkripsi password menjadi bintang
void changePassword(int ch, string &password)
{
  while (ch != 13) // 13 sebagai enter key
  {
    while (ch == 8) // 8 sebagai backspace key
    {
      cout << "\b \b";
      password.pop_back(); 
      ch = getch(); // membaca karakter per karakter sehingga kata sandi tidak terlihat.
    }
    password.push_back(ch);
    cout << '*';
    ch = getch();
  }
}

void menuKasir() // void, prosedure menu Kasir, Farel
{
  int pilihan;

  system("cls"); // membersihkan layar terminal
  cout << "|===============================|" << endl;
  cout << "|            -MENU-             |" << endl;
  cout << "|          -Interface-          |" << endl;
  cout << "|===============================|" << endl;
  cout << "| 1. Point Of Sale              |" << endl;
  cout << "| 2. Logout                     |" << endl;
  cout << "|===============================|" << endl;
  cout << "| Pilihan : ";
  cin >> pilihan;
  cout << "|===============================|" << endl;

  switch (pilihan) // penukaran atau switch case
  {
  case 1:
    transaksi();
    break;
  case 2:
    cin.ignore(); // Menghindari masalah karakter newline yang tertinggal
    login();
    break;
  default:
    cout << "| Pilihan tidak ada" << endl;
    cout << "|===============================|" << endl;
    menuKasir();
    break;
  }
}

// pilihan menu admin, Zulfa
void menuAdmin() // prosedur
{
  int pilihan;

  system("cls");
  cout << "|===============================|" << endl;
  cout << "|            -MENU-             |" << endl;
  cout << "|          -Interface-          |" << endl;
  cout << "|===============================|" << endl;
  cout << "| 1. Lihat Barang               |" << endl;
  cout << "| 2. Tambah Barang              |" << endl;
  cout << "| 3. Edit Barang                |" << endl;
  cout << "| 4. Hapus Barang               |" << endl;
  cout << "| 5. Logout                     |" << endl;
  cout << "|===============================|" << endl;
  cout << "| Pilihan : ";
  cin >> pilihan;
  cout << "|===============================|" << endl;

  switch (pilihan) // int pilihan;
  {
  case 1:
    tampilDataBarang(); // kita memanggil void data barang,  1. Lihat Barang     
    break; // wajib ada, jika ada switch case
  case 2:
    tambahDataBarang();
    break;
  case 3:
    updateDataBarang();
    break;
  case 4:
    hapusDataBarang();
    break;
  case 5:
    cin.ignore(); // Menghindari masalah karakter newline yang tertinggal
    login();
    break;
  default: // wajib ada
    cout << "| Pilihan tidak ada" << endl;
    cout << "|===============================|" << endl;
    menuAdmin();
    break;
  }
}

// Untuk melakukan login.
void login() // prosedur, farida. nama voidnya login.
{
  int ch;
  string username, password;

  system("cls"); // membersihkan layar ketika output berjalan.
  cout << "|===============================|" << endl;
  cout << "|             -LOGIN-           |" << endl;
  cout << "|           -Interface-         |" << endl;
  cout << "|                               |" << endl;
  cout << "|      TOKO KELONTONG CANGGIH   |" << endl;
  cout << "|           KELOMPOK 3          |" << endl;
  cout << "|                               |" << endl;
  cout << "|           KELOMPOK 3 :        |" << endl;
  cout << "|         Amrullah Azzaky       |" << endl;
  cout << "|           Zulfa Riana         |" << endl;
  cout << "|        Defina Rahmayanti      |" << endl;
  cout << "|      Farida Agil Rahmadani    |" << endl;
  cout << "|      Mohamad Farrel Pratama   |" << endl;
  cout << "|===============================|" << endl;
  cout << "| Username : ";
  cin >> username;
  cout << "| Password : ";
  ch = getch(); // membaca karakter per karakter sehingga kata sandi tidak terlihat.
  changePassword (ch, password); // menyimpan karakter variabel ke prosedure password dan mengubahnya ke bintang-bintang.
  cout << "|===============================|" << endl;

  if (username == "adminkelompok3" && password == "admin0000")
  {
    cout << "| Login Berhasil" << endl;
    cout << "|===============================|" << endl;
    menuAdmin();
  }
  else if (username == "kasirkelompok3" && password == "kasir1111")
  {
    cout << "| Login Berhasil" << endl;
    cout << "|===============================|" << endl;
    menuKasir();
  }
  else
  {
    cout << "| Login Gagal" << endl;
    cout << "|===============================|" << endl;
    login();
  }
}

void tambahDataBarang()
{
  char kembali;
  int nomor = autoIncrement();
  int kode_barang = autoIncrementKodeBarang();
  string namaBarang, hargaBarang, satuanBarang;

  hanyaTampilkanData();

  cout << "\nMasukkan nama barang : ";
  cin >> namaBarang;
  cout << "Masukkan harga barang : ";
  cin >> hargaBarang;
  cout << "Masukkan satuan barang : ";
  cin >> satuanBarang;

  barang[nomor][0] = to_string(nomor + 1); // Menyimpan Data ke Array
  barang[nomor][1] = to_string(kode_barang);    /*barang[nomor][2] = namaBarang; barang[nomor][3] = satuanBarang ; barang[nomor][4] = hargaBarang;*/
  barang[nomor][2] = namaBarang;
  barang[nomor][3] = satuanBarang;
  barang[nomor][4] = hargaBarang;

  cout << "\n\nTambah barang berhasil" << endl;
  ;

  cout << "\n\nanda ingin kembali? (y/n) : ";
  cin >> kembali;
  if (kembali == 'y' || kembali == 'Y')
  {
    menuAdmin();
  }
  else
  {
    login();
  }
}

void updateDataBarang()
{
  char kembali;
  int nomor, kode_barang;

  hanyaTampilkanData();

  cout << "\nMasukan kode barang yang ingin di ubah :";
  cin >> kode_barang;

  char namaBarang[50], hargaBarang[50], satuanBarang[50];
  cin.ignore(); // // Menghindari masalah karakter newline yang tertinggal
  login();

  cout << "Masukkan nama barang : ";
  cin.getline(namaBarang, 50);
  cout << "Masukkan harga barang : ";
  cin.getline(hargaBarang, 50);
  cout << "Masukkan satuan barang : ";
  cin.getline(satuanBarang, 50);

  if (strlen(namaBarang) == 0)
  {
    cout << "Nama barang tidak boleh kosong" << endl;
  }
  else if (strlen(hargaBarang) == 0)
  {
    cout << "Harga barang tidak boleh kosong" << endl;
  }
  else if (strlen(satuanBarang) == 0)
  {
    cout << "Satuan barang tidak boleh kosong" << endl;
  }
  else
  {

    for (int i = 0; i < getLengthArray(); i++)
    {
      if (barang[i][0] != "")
      {
        if (stoi(barang[i][1]) == kode_barang) // Mengkonversi nilai string menjadi integer
        {
          kode_barang = stoi(barang[i][1]);
          nomor = stoi(barang[i][0]);
        }
      }
    }

    nomor = nomor - 1;

    barang[nomor][0] = to_string(nomor + 1);
    barang[nomor][1] = to_string(kode_barang);
    barang[nomor][2] = namaBarang;
    barang[nomor][3] = satuanBarang;
    barang[nomor][4] = hargaBarang;
  }

  cout << "\n\nUpdate Barang berhasil" << endl;

  cout << "\n\nanda ingin kembali? (y/n) : ";
  cin >> kembali;
  if (kembali == 'y' || kembali == 'Y')
  {
    menuAdmin();
  }
  else
  {
    login();
  }
}

void hapusDataBarang()
{
  int nomor;
  char pilihan, kode_barang;

  hanyaTampilkanData();

  cout << "Masukkan nomor yang akan dihapus : ";
  cin >> nomor;
  nomor = nomor - 1;
  barang[nomor][0] = "";
  barang[nomor][1] = "";
  barang[nomor][2] = "";
  barang[nomor][3] = "";
  barang[nomor][4] = "";

  cout << "\n\nHapus Barang berhasil" << endl;

  cout << "\n\nAnda ingin kembali? (y/n) : ";
  cin >> pilihan;
  if (pilihan == 'y' || pilihan == 'Y')
  {
    menuAdmin();
  }
  else
  {
    login();
  }
}

void hanyaTampilkanData()
{
  cout << "No. \t| Kode Barang \t| Nama Barang \t\t| Satuan \t| Harga" << endl;
  cout << "========================================================================" << endl;
  for (int i = 0; i < getLengthArray(); i++)
  {
    if (barang[i][0] != "")
    {
      cout << barang[i][0] << "\t| " << barang[i][1] << "\t\t| " << barang[i][2] << "\t\t| " << barang[i][3] << "\t\t| " << barang[i][4] << endl;
    }
  }
}

void tampilDataBarang()
{
  char pilihan;

  cout << "No. \t| Kode Barang \t| Nama Barang \t\t| Satuan \t| Harga" << endl;
  cout << "========================================================================" << endl;
  for (int i = 0; i < getLengthArray(); i++)
  {
    if (barang[i][0] != "")
    {
      cout << barang[i][0] << "\t| " << barang[i][1] << "\t\t| " << barang[i][2] << "\t\t| " << barang[i][3] << "\t\t| " << barang[i][4] << endl;
    }
  }
  
  cout << "\n\nanda ingin kembali? (y/n) : ";
  cin >> pilihan;
  if (pilihan == 'y' || pilihan == 'Y')
  {
    menuAdmin();
  }
  else
  {
    login();
  }
}

// Print function struct pembayaran
void struk(string jumlah_beli[6][6], int bayar, int kembalian, int jumlah, int total)
{

  system("cls");
  cout << "               KELOMPOK 3              " << endl;
  cout << "         TOKO KELONTONG CANGGIH        " << endl;
  cout << "=======================================" << endl;
  for (int i = 0; i < jumlah; i++)
  {
    cout << "   \t" << jumlah_beli[i][1] << " -" << jumlah_beli[i][0] << "("
         << jumlah_beli[i][2] << ")"
         << "\t\t" << endl;
    cout << " \t\t" << jumlah_beli[i][3] << " x " << jumlah_beli[i][4] << " : "
         << jumlah_beli[i][5] << "\t" << endl;
  }
  cout << "=======================================" << endl;
  cout << " Total              : " << total << "\t\t" << endl;
  cout << " Bayar              : " << bayar << "\t\t" << endl;
  cout << " Kembalian          : " << kembalian << "\t\t" << endl;
  cout << "=======================================" << endl;
  cout << " Terima Kasih Telah Berbelanja di TOKO " << endl;
  cout << "        KELONTONG CANGGIH KAMI         " << endl;
  cout << "=======================================" << endl;
  cout << endl;
}

void transaksi()
{
  string jawab, jumlah_beli[6][6];
  int pilihan, jumlah = 1, qty, total = 0, bayar, kembalian, total_harga;
  bool repeat = true;
  char re;
  while (repeat != false)
  {
    system("cls");
    cout << "==================================" << endl;
    cout << "             Kasir TOKO           " << endl;
    cout << "         KELONTONG CANGGIH        " << endl;
    cout << "            Kelompok 3            " << endl;
    cout << "==================================" << endl;
    cout << "ketik 13 untuk kembali menu kasir" << endl;
    cout << "==================================" << endl;
    cout << "\n========DAFTAR BARANG ======" << endl;
    for (int i = 0; i < getLengthArray(); i++)
    {
      if (barang[i][0] != "")
      {
        cout << barang[i][0] << ". " << barang[i][1] << " - " << barang[i][2] << " Rp. " << barang[i][4] << endl;
      }
    }

    for (int i = 0; i < jumlah; i++)
    {
      // input barang yang ingin dibeli
      cout << "==============================" << endl;
      cout << "Masukkan kode barang : ";
      cin >> jawab;

      if (jawab == "13")
      {
        menuKasir();
        break;
      }

      // pilihan = pilihan - 1;
      pilihan = getIncrementBarang(jawab);

      if (barang[pilihan][0] == "")
      {
        cout << "Tidak ada barang" << endl;
        cout << "Apakah anda ingin mengulang? (y/n) : ";
        cin >> re;
        if (re == 'y' || re == 'Y')
        {
          transaksi();
        }
        else if (re == 'n' || re == 'N')
        {
          repeat = false;
        }
        else
        {
          cout << "Inputan salah, silahkan melakukan transaksi kembali" << endl;
        }
      }
      else
      {
        cout << "Anda memilih " << barang[pilihan][2] << endl;
        cout << "Masukkan " << barang[pilihan][3] << " : ";
        cin >> qty;
        int harga = stoi(barang[pilihan][4]);
        total = qty * harga;
        // input jumlah barang yang ingin dibeli
        jumlah_beli[i][0] = barang[pilihan][2]; // nama barang
        jumlah_beli[i][1] = barang[pilihan][1]; // kode barang
        jumlah_beli[i][2] = barang[pilihan][3]; // satuan barang
        jumlah_beli[i][3] = to_string(qty);     // qty barang
        jumlah_beli[i][4] = to_string(harga);   // harga barang persatuan
        jumlah_beli[i][5] = to_string(total);   // total harga barang

        // tambah barang (y/n)
        cout << "Apakah anda ingin menambah barang? (y/n) : ";
        cin >> jawab;
        if (jawab == "y" || jawab == "Y")
        {
          jumlah++;
        }
        else
        {
          break;
        }
      }
    }

    // mengkalkulasikan semua jumlah_beli
    total_harga = 0;
    for (int i = 0; i < jumlah; i++)
    {
      total_harga += stoi(jumlah_beli[i][5]);
    }

    system("cls");
    cout << "\n==============CART================" << endl;
    getCart(jumlah_beli, jumlah); // Menampilkan isi keranjang belanja
    cout << "\nTotal Harga : Rp. " << total_harga << endl;
    cout << "Masukkan Uang Anda : Rp. ";
    cin >> bayar;

    while (bayar < total_harga)
    {
      cout << "Uang tidak mencukupi, silahkan masukan ulang dengan nominal yang benar..." << endl;
      cout << "Masukkan Uang Anda : Rp. ";
      cin >> bayar;
    }
    kembalian = bayar - total_harga;

    // memanggil function struk
    struk(jumlah_beli, bayar, kembalian, jumlah, total_harga);
    cout << "Klik enter untuk melanjutkan...";
    cin.ignore(); // Menghindari masalah karakter newline yang tertinggal
    cin.get(); //  menunggu pengguna menekan tombol Enter sebelum melanjutkan eksekusi program. 
  }
}

int getIncrementBarang(string kode_barang)
{
  int nomor = 0;
  for (int i = 0; i < getLengthArray(); i++)
  {
    if (barang[i][1] == kode_barang)
    {
      nomor = stoi(barang[i][0]);
    }
  }

  return nomor - 1;
}

void getCart(string jumlah_beli[6][6], int jumlah)
{
  for (int i = 0; i < jumlah; i++)
  {
    if (jumlah_beli[i][0] != "")
    {
      cout << jumlah_beli[i][0] << " - " << jumlah_beli[i][3] << " " << jumlah_beli[i][2] << " - Rp. " << jumlah_beli[i][5] << endl;
    }
  }
}