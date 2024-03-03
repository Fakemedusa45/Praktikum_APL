#include <iostream>
using namespace std;


void rupiah (){
    cin.sync();
    double nominal;
    cout << "silahkan masukkan nominal uangnya (Rupiah) : ";
    cin >> nominal;
    cout << "Rupiah : " << nominal << "\n";
    cout << "Dollar : " << nominal/15700 << "\n";
    cout << "Euro : " << nominal/17000 << "\n";
    cout << "Yen : " << nominal/104 << "\n\n";

}

void dollar (){
    cin.sync();
    double nominal;
    cout << "silahkan masukkan nominal uangnya (dollar) : ";
    cin >> nominal;
    cout << "Rupiah : " << nominal*15700 << "\n";
    cout << "Dollar : " << nominal << "\n";
    cout << "Euro : " << nominal*0.92 << "\n";
    cout << "Yen : " << nominal*150 << "\n\n";

}

void euro (){
    cin.sync();
    double nominal;
    cout << "silahkan masukkan nominal uangnya (Euro) : ";
    cin >> nominal;
    cout << "Rupiah : " << nominal*17000 << "\n";
    cout << "Dollar : " << nominal*1.08 << "\n";
    cout << "Euro : " << nominal << "\n";
    cout << "Yen : " << nominal*162 << "\n\n";

}

void yen (){
    cin.sync();
    double nominal;
    cout << "silahkan masukkan nominal uangnya (Yen) : ";
    cin >> nominal;
    cout << "Rupiah : " << nominal *104 << "\n";
    cout << "Dollar : " << nominal/150 << "\n";
    cout << "Euro : " << nominal/162 << "\n";
    cout << "Yen : " << nominal << "\n\n";

}

int pilih_mata_uang(){
    int pilihan;
    cin.sync();
    while (true){
    cout << "1. Rupiah\n";
    cout << "2. Dollar\n";
    cout << "3. Euro\n";
    cout << "4. Yen\n";
    cout << "0. exit\n";
    cout << "silahkan masukkan pilihan mata uang anda, dan pilih 0 untuk keluar dari program : ";
    cin >> pilihan;
     if (pilihan == 1){
        rupiah();
    }
    else if (pilihan == 2){
        dollar();
    }
    else if (pilihan == 3){
        euro();
    }
    else if (pilihan == 4){
        yen();
    }
    else if (pilihan == 0){
        break;
    }
    else {
        cout << "Pilihan anda tidak valid\n\n";
    }
    }
    return 0;
}

int main() {
    string input_nama, input_nim;

    cout << "Silahkan login menggunakan nama dan nim anda\n\n";
    string nama = "Rifqi";
    string nim = "2309106007";
    int coba = 1;

    while (coba <= 3) {
        cout << "Silahkan masukkan nama anda : ";
        cin >>input_nama;
        cout << "silahkan masukkan nim anda : ";
        cin >> input_nim;
        if (input_nama == nama && input_nim == nim){
            cout << "login berhasil\n\n";
            coba = 4;
            pilih_mata_uang();
        }else if (coba == 3){
            cout << endl;
            cout << "anda telah 3X gagal login, silahkan jalakan ulang program";
            break;
        }
        else {
            cout << "username yang anda masukkan salah, percobaan ke " << coba <<"x\n\n";
            coba += 1;
        }
    }
    return 0;
}

