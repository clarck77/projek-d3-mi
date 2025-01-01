/*Aplikasi Toko Kelontong Canggih, Kelompok 3 :
- Amrullah Azzaky         (2407051027)
- Zulfa Riana             (2407051006)
- Mohamad Farrel Pratama  (2477051014)
- Farida Agil Rahmadani   (2407051018)
- Defina Rahmayanti       (2407051023)
*/ 

#include <iostream>
#include <vector>
#include <string>
#include <limits> 

using namespace std;

struct Barang {
    string kode;
    string nama;
    string satuan;
    int harga;
};

vector<Barang> barang = {
    {"22001", "Beras_Bulog", "KG", 25000},
    {"22002", "Gula_Pasir", "KG", 5000},
    {"22003", "Minyak_Goreng", "Liter", 15000},
    {"22004", "Susu_Dancow", "Gram", 20000},
    {"22005", "Telur_Ayam", "KG", 20000}
};

void tampilDataBarang() {
    cout << "|=============================================|" << endl;
    cout << "| No | Kode  | Nama Barang   | Satuan | Harga |" << endl;
    cout << "|=============================================|" << endl;
    for (size_t i = 0; i < barang.size(); ++i) {
        cout << "| " << i + 1 << "  | " << barang[i].kode << " | " << barang[i].nama << " | "
             << barang[i].satuan << "   | " << barang[i].harga << " |" << endl;
    }
    cout << "|===========================================|" << endl;
}

void tambahDataBarang() {
    Barang baru;
    cout << "Masukkan Kode Barang: ";
    cin >> baru.kode;
    cout << "Masukkan Nama Barang: ";
    cin >> baru.nama;
    cout << "Masukkan Satuan Barang: ";
    cin >> baru.satuan;
    cout << "Masukkan Harga Barang: ";
    while (!(cin >> baru.harga)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Gunakan <limits>
        cout << "Input harus berupa angka. Masukkan Harga Barang: ";
    }
    barang.push_back(baru);
    cout << "Barang berhasil ditambahkan!" << endl;
}

void updateDataBarang() {
    string kode;
    cout << "Masukkan Kode Barang yang akan diupdate: ";
    cin >> kode;
    for (auto &b : barang) {
        if (b.kode == kode) {
            cout << "Masukkan Nama Barang baru: ";
            cin >> b.nama;
            cout << "Masukkan Satuan Barang baru: ";
            cin >> b.satuan;
            cout << "Masukkan Harga Barang baru: ";
            while (!(cin >> b.harga)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Gunakan <limits>
                cout << "Input harus berupa angka. Masukkan Harga Barang baru: ";
            }
            cout << "Barang berhasil diperbarui!" << endl;
            return;
        }
    }
    cout << "Barang tidak ditemukan!" << endl;
}

void hapusDataBarang() {
    string kode;
    cout << "Masukkan Kode Barang yang akan dihapus: ";
    cin >> kode;
    for (size_t i = 0; i < barang.size(); ++i) {
        if (barang[i].kode == kode) {
            barang.erase(barang.begin() + i);
            cout << "Barang berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Barang tidak ditemukan!" << endl;
}

void menuAdmin() {
    int pilihan;
    do {
        cout << "|===============================|" << endl;
        cout << "|            -MENU-             |" << endl;
        cout << "|===============================|" << endl;
        cout << "| 1. Lihat Barang               |" << endl;
        cout << "| 2. Tambah Barang              |" << endl;
        cout << "| 3. Edit Barang                |" << endl;
        cout << "| 4. Hapus Barang               |" << endl;
        cout << "| 5. Logout                     |" << endl;
        cout << "|===============================|" << endl;
        cout << "| Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tampilDataBarang();
            break;
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
            cout << "Logout berhasil!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
}

void login() {
    string username, password;
    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;
    if (username == "admin" && password == "admin") {
        menuAdmin();
    } else {
        cout << "Username atau Password salah!" << endl;
        login();
    }
}

int main() {
    login();
    return 0;
}
