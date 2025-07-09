#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Buku {
    string nomor;
    string judul;
    string penulis;
    int stok;
};

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void bacaFile(Buku buku[], int& n) {
    ifstream file("buku.txt");
    if (file.is_open()) {
        n = 0;
        while (getline(file, buku[n].nomor, '|') &&
               getline(file, buku[n].judul, '|') &&
               getline(file, buku[n].penulis, '|') &&
               file >> buku[n].stok) {
            file.ignore(); // untuk newline
            n++;
        }
        file.close();
    } else {
        cout << "File buku.txt tidak ditemukan, masukkan data secara manual.\n";
        n = 0;
    }
}

void simpanFile(Buku buku[], int n) {
    ofstream file("buku.txt");
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file << buku[i].nomor << "|" << buku[i].judul << "|" << buku[i].penulis << "|" << buku[i].stok << endl;
        }
        file.close();
    }
}

void simpanHasil(Buku buku[], int n) {
    ofstream file("hasil_pencarian.txt");
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file << buku[i].nomor << " " << buku[i].judul << " " << buku[i].penulis << " " << buku[i].stok << endl;
        }
        file.close();
        cout << "Hasil pencarian disimpan ke hasil_pencarian.txt\n";
    }
}

int cariJudul(Buku buku[], int n, string judul) {
    ofstream file("hasil_cari_judul.txt");
    int jumlahCocok = 0;
    string input = toLower(judul);
    for (int i = 0; i < n; i++) {
        if (toLower(buku[i].judul).find(input) != string::npos) {
            cout << buku[i].nomor << " " << buku[i].judul << " " << buku[i].penulis << " " << buku[i].stok << endl;
            if (file.is_open()) {
                file << buku[i].nomor << " " << buku[i].judul << " " << buku[i].penulis << " " << buku[i].stok << endl;
            }
            jumlahCocok++;
        }
    }
    file.close();
    if (jumlahCocok > 0)
        cout << "Hasil disimpan ke hasil_cari_judul.txt\n";
    return jumlahCocok;
}

int cariPenulis(Buku buku[], int n, string penulis) {
    ofstream file("hasil_cari_penulis.txt");
    int jumlahCocok = 0;
    string input = toLower(penulis);
    for (int i = 0; i < n; i++) {
        if (toLower(buku[i].penulis).find(input) != string::npos) {
            cout << buku[i].nomor << " " << buku[i].judul << " " << buku[i].penulis << " " << buku[i].stok << endl;
            if (file.is_open()) {
                file << buku[i].nomor << " " << buku[i].judul << " " << buku[i].penulis << " " << buku[i].stok << endl;
            }
            jumlahCocok++;
        }
    }
    file.close();
    if (jumlahCocok > 0)
        cout << "Hasil disimpan ke hasil_cari_penulis.txt\n";
    return jumlahCocok;
}

int cariStok(Buku buku[], int n, int stok, char mode) {
    int jumlahCocok = 0;
    for (int i = 0; i < n; i++) {
        bool cocok = false;
        if (mode == '=') cocok = (buku[i].stok == stok);
        else if (mode == '<') cocok = (buku[i].stok < stok);
        else if (mode == '>') cocok = (buku[i].stok > stok);

        if (cocok) {
            cout << buku[i].nomor << " " << buku[i].judul << " " << buku[i].penulis << " " << buku[i].stok << endl;
            jumlahCocok++;
        }
    }
    return jumlahCocok;
}

void cariMaksimum(Buku buku[], int n) {
    int maxStok = 0, idx = 0;
    for (int i = 0; i < n; i++) {
        if (buku[i].stok > maxStok) {
            maxStok = buku[i].stok;
            idx = i;
        }
    }
    cout << "Buku dengan stok terbanyak: " << buku[idx].nomor << " " << buku[idx].judul << " " << buku[idx].penulis << " " << buku[idx].stok << endl;
}

void urutkanJudul(Buku buku[], int n, bool ascending = true) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ascending ? buku[j].judul > buku[j + 1].judul : buku[j].judul < buku[j + 1].judul) {
                swap(buku[j], buku[j + 1]);
            }
        }
    }
}

int main() {
    Buku buku[100];
    int n = 0;
    int pilihan;

    bacaFile(buku, n);

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Cari Berdasarkan Judul\n";
        cout << "3. Cari Berdasarkan Penulis\n";
        cout << "4. Cari Berdasarkan Stok (==, <, >)\n";
        cout << "5. Tampilkan Buku dengan Stok Terbanyak\n";
        cout << "6. Urutkan Judul A-Z\n";
        cout << "7. Urutkan Judul Z-A\n";
        cout << "8. Simpan Semua ke hasil_pencarian.txt\n";
        cout << "9. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                cout << "Nomor: ";
                cin >> buku[n].nomor;
                cout << "Judul: ";
                cin.ignore();
                getline(cin, buku[n].judul);
                cout << "Penulis: ";
                getline(cin, buku[n].penulis);
                cout << "Stok: ";
                cin >> buku[n].stok;
                n++;
                simpanFile(buku, n);
                break;
            }
            case 2: {
                string judul;
                cout << "Masukkan judul : ";
                cin.ignore();
                getline(cin, judul);
                if (cariJudul(buku, n, judul) == 0) cout << "Tidak ditemukan\n";
                break;
            }
            case 3: {
                string penulis;
                cout << "Masukkan penulis : ";
                cin.ignore();
                getline(cin, penulis);
                if (cariPenulis(buku, n, penulis) == 0) cout << "Tidak ditemukan\n";
                break;
            }
            case 4: {
                int stok;
                char mode;
                cout << "Cari stok dengan mode (=, <, >): ";
                cin >> mode;
                cout << "Masukkan nilai stok: ";
                cin >> stok;
                if (cariStok(buku, n, stok, mode) == 0)
                    cout << "Tidak ditemukan\n";
                break;
            }
            case 5:
                cariMaksimum(buku, n);
                break;
            case 6:
                urutkanJudul(buku, n, true);
                for (int i = 0; i < n; i++) {
                    cout << buku[i].nomor << " " << buku[i].judul << " " << buku[i].penulis << " " << buku[i].stok << endl;
                }
                break;
            case 7:
                urutkanJudul(buku, n, false);
                for (int i = 0; i < n; i++) {
                    cout << buku[i].nomor << " " << buku[i].judul << " " << buku[i].penulis << " " << buku[i].stok << endl;
                }
                break;
            case 8:
                simpanHasil(buku, n);
                break;
        }
    } while (pilihan != 9);

    simpanFile(buku, n);
    return 0;
}

