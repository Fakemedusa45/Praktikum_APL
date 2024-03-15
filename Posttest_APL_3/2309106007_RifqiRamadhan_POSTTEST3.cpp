#include <iostream>
using namespace std;

#define max 10
string mobil[max] = {"Ford Capri", "Nissan 300ZX", "Lexus RC", "Toyota 2000GT", "Mercedes-Benz SLR McLaren"};
string ulang = "y";
int pos = 5;

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
    system("cls");
    if (pos > 0){
        cout << "Daftar Mobil GT\n\n";
        for (int i = 1; i <= pos; i++){
            cout << penomoran(1, i) << "." << mobil[i - 1] << "\n";}
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
    do{
        tampilMobil();
        if (pos < max){
            cout << "Tambah Data : ";
            getline(cin, mobil[pos]);
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
        cout << "Silahkan masukkan data baru : ";
        getline(cin, mobil[edit-1]);
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
