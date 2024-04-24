#include <iostream>
using namespace std;

#define max 10
string ulang = "y";
int *pos_ptr = nullptr;

struct harga{
    double harga_mobil;
};

struct mobil{
    string merk;
    int tahunRilis;
    harga harga;
};

mobil mob[max];

int penomoran (int no, int iterasi){
    if (no > *pos_ptr){
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
    if (*pos_ptr > 0){
        cout << "Daftar Mobil GT\n\n";
        do{
            cout << penomoran(1, i)+1 << "." << mob[i].merk << endl;
            cout << "Harga Mobil : " << mob[i].harga.harga_mobil << endl;
            cout << "Tahun dibuat : " << mob[i].tahunRilis << endl;
            i++;
        }while (i < *pos_ptr);

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
        if(*pos_ptr > 0){
            cout << "Hapus data ke : " << endl;
            cin >> del;
            for(int i = del; i < *pos_ptr; i++){
                mob[i-1] = mob[i];
            }(*pos_ptr)--;
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
    double hargaBaru;
    int tahunBaru = 0;

    do{
        tampilMobil();
        if (*pos_ptr < max){
            cout << "\nTambah Data" << endl;
            cout << "Masukkan nama mobil : ";
            getline(cin, merkBaru);
            cout << "Masukkan harga mobil : ";
            cin >> hargaBaru;
            cout << "Masukkan tahun rilis mobil : ";
            cin >> tahunBaru;
            cin.clear();
            mob[*pos_ptr].merk = merkBaru;
            mob[*pos_ptr].harga.harga_mobil = hargaBaru;
            mob[*pos_ptr].tahunRilis = tahunBaru;
            (*pos_ptr)++;
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
        int ubahtahun = 0;
        tampilMobil();
        cout << "Ubah data ke : ";
        cin >> edit;
        cin.ignore();
        cout << "Silahkan masukkan data baru" << endl;
        cout << "Ubah Data";
        cout << "Masukkan nama mobil : ";
        getline(cin, mob[edit-1].merk);
        cout << "Masukkan harga mobil : ";
        cin >> mob[edit-1].harga.harga_mobil;
        cout << "Masukkan harga mobil : ";
        cin >> ubahtahun;
        mob[edit-1].tahunRilis = ubahtahun;
        tampilMobil();
        cout << "ingin merubah data lagi? (y/n) : ";
        cin >> ulang;

    }while (ulang == "y");
}

//harga mobil secara ascending
void bubbleSort(mobil mob[], int *pos_ptr)
{
    int i = 0, j = 0;
    for (i = 0; i < *pos_ptr; i++) {
        for (j = 0; j < *pos_ptr-i-1; j++) {
            if(mob[j].harga.harga_mobil > mob[j+1].harga.harga_mobil) {
                mobil swap = mob[j];
                mob[j] = mob[j+1];
                mob[j+1] = swap;
                }
            }
    }
}

//merk mobil secara ascending
void selectionSort(mobil mob[], int *pos_ptr) {
    int i, j, min_idx;
    for (i = 0; i < *pos_ptr - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < *pos_ptr; j++) {
            if (mob[j].merk < mob[min_idx].merk) {
                min_idx = j;
            }
        }
        if (min_idx != i){
            mobil swap = mob[min_idx];
            mob[min_idx] = mob[i];
            mob[i] = swap;
        }
    }
}

//tahun rilis mobil secara descending
void shellSort (mobil mob[], int *pos_ptr){
    for (int gap = *pos_ptr/2; gap > 0; gap /= 2){
        for (int i = gap; i < *pos_ptr; i++){
            mobil temp = mob[i];
            int j;
            for (j = i; j >= gap && mob[j - gap].tahunRilis < temp.tahunRilis; j-= gap){
                mob[j] = mob[j - gap];
            }
            mob[j] = temp;
        }
    }
}

//mencari data berdasarkan pada merk (ascending)
int binarySearch (mobil mob[], int *pos_ptr){

    //selection sort
    selectionSort(mob, pos_ptr);


    string cariMerk;
    cout << "Masukkan merk mobil yang dicari: ";
    getline(cin, cariMerk);
    cin.clear();

    int awal = 0;
    int akhir = *pos_ptr;

    // Binary search
    while (awal <= akhir) {
        int tengah = (awal + akhir) / 2;
        if (cariMerk == mob[tengah].merk) {
            cout << mob[tengah].merk << endl;
            cout << "Harga Mobil : " << mob[tengah].harga.harga_mobil << endl;
            cout << "Tahun dibuat : " << mob[tengah].tahunRilis << endl;
            return 0;
        } else if (cariMerk < mob[tengah].merk) {
            akhir = tengah - 1;
        } else {
            awal = tengah + 1;
        }
    }
    if (awal == akhir && *pos_ptr == 1){
    cout << "Nama tidak ditemukan" << endl;
    return 0;
    }
    return 0;
}


//mencari data berdasarkan pada tahun rilis (descending)
void interpolationSearch (mobil mob[], int *pos_ptr){
    shellSort(mob, pos_ptr);

    cout << "Masukkan tahun mobil yang dicari: ";
    int cariTahun;
    cin >> cariTahun;
    cout << endl;

    //interpolation search
    int awal = 0;
    int akhir = *pos_ptr;
    int posisi = ((cariTahun - mob[awal].tahunRilis) / (mob[akhir].tahunRilis - mob[awal].tahunRilis) * (akhir - awal)) + awal;

    while (true) {
        if (cariTahun != mob[posisi].tahunRilis) {
            break;
        } else if (cariTahun > mob[posisi].tahunRilis) {
            awal = posisi + 1;
            posisi = ((cariTahun - mob[awal].tahunRilis) / (mob[akhir].tahunRilis - mob[awal].tahunRilis) * (akhir - awal)) + awal;
        } else if (cariTahun < mob[posisi].tahunRilis) {
            akhir = posisi - 1;
            posisi = ((cariTahun - mob[awal].tahunRilis) / (mob[akhir].tahunRilis - mob[awal].tahunRilis) * (akhir - awal)) + awal;
        } else {
            cout << "Data berada di array ke " << posisi << endl;
            cout << mob[posisi].merk << endl;
            cout << "Harga Mobil : " << mob[posisi].harga.harga_mobil << endl;
            cout << "Tahun dibuat : " << mob[posisi].tahunRilis << endl;
            break;
        }
    }
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
    cout << "5. Cari data Mobil\n";
    cout << "0. Keluar\n\n";
    cout << "Silahkan masukkan pilihan menu anda : ";
    cin.clear();
    cin >> pilihan;
    if (pilihan == 1){
        cin.clear();
        int pilihanUrut;
        system("cls");
        cout << "Lihat daftar berdasarkan apa?" << endl;
        cout << "1. Merk" << endl;
        cout << "2. Harga" << endl;
        cout << "3. tahun Rilis" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihanUrut;
        if (pilihanUrut == 1) {
            selectionSort(mob, pos_ptr);
            tampilMobil();
            cout << "Tekan Enter untuk kembali...";
            cin.ignore();
            cin.get();

        }else if (pilihanUrut == 2){
            bubbleSort(mob, pos_ptr);
            tampilMobil();
            cout << "Tekan Enter untuk kembali...";
            cin.ignore();
            cin.get();

        }else if (pilihanUrut == 3){
            shellSort(mob, pos_ptr);
            tampilMobil();
            cout << "Tekan Enter untuk kembali...";
            cin.ignore();
            cin.get();

        }

    }else if (pilihan == 2){
        tambahMobil();

    }else if (pilihan == 3){
        do{
            hapusMobil();
        }while (ulang == "y");

    }else if (pilihan == 4){
        ubahMobil();

    }else if (pilihan == 5){
        cin.clear();
        int pilihanCari;
        system("cls");
        cout << "cari data berdasarkan apa?" << endl;
        cout << "1. Merk" << endl;
        cout << "2. Tahun Rilis" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihanCari;
        cin.ignore();
        if (pilihanCari == 1) {
            binarySearch(mob, pos_ptr);
            cout << "Tekan Enter untuk kembali...";
            cin.ignore();
            cin.get();

        }else if (pilihanCari == 2){
            interpolationSearch(mob, pos_ptr);
            cout << "Tekan Enter untuk kembali...";
            cin.ignore();
            cin.get();
        }

    }else if (pilihan == 0){
        break;

    }else {
        cout << "Input invalid";
    }
}
return 0;
}


int main() {
    int pos;
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
            pos_ptr = &pos;
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

