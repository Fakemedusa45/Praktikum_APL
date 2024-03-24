#include <iostream>
using namespace std;

#define max 10
string ulang = "y";
int pos = 0;

struct harga{
    string harga_mobil;
};

struct mobil{
    string merk;
    string tahunRilis;
    harga harga;
};

mobil mobil[max];

int penomoran(int no, int iterasi){
    if (no > pos){
        return 0;
    }else if(no == iterasi){
        return iterasi;
    }else {
        return penomoran(no + 1, iterasi);
    }
}

void tampilMobil(){
    int i = 0;
    system("cls");
    if (pos > 0){
        cout << "Daftar Mobil GT\n\n";
        do{
            cout << penomoran(1, i)+1 << "." << mobil[i].merk << endl;
            cout << "Harga Mobil : " << mobil[i].harga.harga_mobil << endl;
            cout << "Tahun dibuat : " << mobil[i].tahunRilis << endl;
            i++;
        }while (i < pos);

    }else {
        cout << "data kosong. . ." << endl;
    }
        cin.sync();
    cout << "\n";
}


void hapusMobil(){
    int del;
    do{
        tampilMobil();
        if(pos > 0){
            cout << "\nHapus Data" << endl;
            cout << "Hapus data ke : ";
            cin >> del;
            for(int i = del; i < pos; i++){
                mobil[i-1] = mobil[i];
            }pos--;
            tampilMobil();
        cout << "Apakah anda ingin menghapus mobil lagi? (y/n) : ";
        cin >> ulang;
        }else {
            cout << "data tidak ada, silahkan inputkan n : ";
            cin >> ulang;
        }
    }while (ulang == "y");
}

string tambahMobil(){
    string merkBaru = "";
    string hargaBaru = "";
    string tahunBaru = "";

    do{
        tampilMobil();
        if (pos < max){
            cout << "\nTambah Data" << endl;
            cout << "Masukkan nama mobil : ";
            getline(cin, merkBaru);
            cout << "Masukkan harga mobil : ";
            getline(cin, hargaBaru);
            cout << "Masukkan tahun rilis mobil : ";
            getline(cin, tahunBaru);
            mobil[pos].merk = merkBaru;
            mobil[pos].harga.harga_mobil = hargaBaru;
            mobil[pos].tahunRilis = tahunBaru;
            pos++;
            tampilMobil();
            cout << "Ingin memasukkan data lagi?(y/n) : ";
            cin >> ulang;
            cin.ignore();
        }else {
            cout << "Daftar Mobil sudah penuh";
            cout << "Inputkan n untuk kembali : ";
            cin >> ulang;
            cin.ignore();
        }
    }while (ulang == "y");
return ulang;
}

void ubahMobil(){
    int edit;
    do{
        tampilMobil();
        cout << "Ubah data ke : ";
        cin >> edit;
        cin.ignore();
        cout << "Silahkan masukkan data baru" << endl;
        cout << "Ubah Data";
        cout << "Masukkan nama mobil : ";
        getline(cin, mobil[edit-1].merk);
        cout << "Masukkan harga mobil : ";
        getline(cin, mobil[edit-1].harga.harga_mobil);
        cout << "Masukkan tahun rilis mobil : ";
        getline(cin, mobil[edit-1].tahunRilis);
        tampilMobil();
        cout << "ingin merubah data lagi? (y/n) : ";
        cin >> ulang;

    }while (ulang == "y");
}

int menu(){
    int pilihan;
    string kosong;
    cin.sync();
    while (true){
    system("cls");
    cout << "Selamat datang di menu utama\n     Mobil-mobil GT\n\n";
    cout << "1. Tampilkan daftar mobil\n";
    cout << "2. Tambahkan mobil\n";
    cout << "3. Hapus mobil\n";
    cout << "4. Ubah Mobil\n";
    cout << "0. Keluar\n\n";
    cout << "Silahkan masukkan pilihan menu anda : ";
    cin >> pilihan;
    if (pilihan == 1){
        do{
            tampilMobil();
            cout << "Inputkan n untuk kembali : ";
            cin >> ulang;
        }while (ulang == "y");

    }else if (pilihan == 2){
        tambahMobil();

    }else if (pilihan == 3){
        do{
            hapusMobil();
        }while (ulang == "y");

    }else if (pilihan == 4){
        ubahMobil();

    }else if (pilihan == 0){
        break;

    }else {
        cout << "Input invalid";
    }
}
return 0;
}

int main() {
    string input_nama, input_nim;

    cout << "Silahkan login menggunakan nama dan nim anda\n\n";
    string nama = "Rifqi Ramadhan";
    string nim = "2309106007";
    int coba = 1;

    while (coba <= 3) {
        cout << "Silahkan masukkan nama anda : ";
        cin.sync();
        getline (cin, input_nama);
        cout << "silahkan masukkan nim anda : ";
        cin.sync();
        cin >> input_nim;
        if (input_nama == nama && input_nim == nim){
            cout << "login berhasil\n\n";
            coba = 4;
            menu();
        }else if (coba == 3){
            cout << endl;
            cout << "anda telah 3X gagal login, silahkan jalakan ulang program";
            break;
        }
        else {
            system("cls");
            cout << "username yang anda masukkan salah, percobaan ke " << coba <<"x\n\n";
            coba += 1;
        }
    }
    return 0;
}
