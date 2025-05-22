#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class BangunRuang{
protected:
    double volume;
    string nama;
public:
    BangunRuang(string nama){
        this->nama = nama;
    }
    virtual void hitungVolume() = 0;
    double getVolume(){                 //enkapsulasi
        return volume;
    }
    string getNama(){
        return nama;
    }
    void tampilVolume(){
        cout << "Bangun ruang " << getNama() << " memiliki volume: " << getVolume() << endl;
    }
    virtual ~BangunRuang(){};
};
class Kubus : public BangunRuang{
private:
    double sisi;
public:
    Kubus(double sisi) : BangunRuang("Kubus"){
        this->sisi = sisi;
    }
    void hitungVolume() override{       //abstraksi
        volume = sisi * sisi * sisi;
    }
    ~Kubus(){}
};
class Balok : public BangunRuang{
private:
    double panjang, lebar, tinggi;
public:
    Balok(double panjang, double lebar, double tinggi) : BangunRuang("Balok"){
        this->panjang = panjang;
        this->lebar = lebar;
        this->tinggi = tinggi;
    }
    void hitungVolume() override{
        volume = panjang * lebar * tinggi;
    }
    ~Balok(){}
};
class Tabung : public BangunRuang{
private:
    double jari_jari, tinggi;
public:
    Tabung(double jari_jari, double tinggi) : BangunRuang("Tabung"){
        this->jari_jari = jari_jari;
        this->tinggi = tinggi;
    }
    void hitungVolume() override{
        volume = 3.14 * jari_jari * jari_jari * tinggi;
    }
    ~Tabung(){}
};
class Bola : public BangunRuang{
private:
    double jari_jari;
public:
    Bola(double jari_jari) : BangunRuang("Bola"){
        this->jari_jari = jari_jari;
    }
    void hitungVolume() override{
        volume = 4/3 * 3.14 * jari_jari * jari_jari * jari_jari;
    }
    ~Bola(){}
};
class PrismaSegitiga : public BangunRuang{
private:
    double panjang, lebar, tinggi;
public:
    PrismaSegitiga(double panjang, double lebar, double tinggi) : BangunRuang("Prisma Segitiga"){
        this->panjang = panjang;    //tinggi prisma
        this->lebar = lebar;    //alas segitiga
        this->tinggi = tinggi;      //tinggi segitiga
    }
    void hitungVolume() override{
        volume = panjang * lebar * tinggi / 2;
    }
    ~PrismaSegitiga(){}
};

int main(){
    string bangunRuang[] = {"Kubus", "Balok", "Tabung", "Bola", "Prisma Segitiga"};
    int n = sizeof(bangunRuang) / sizeof(bangunRuang[0]);   //hitung jumlah bangun ruang
    int pilihan;    //input pilihan user
    string confirm; //input konfirmasi user
    BangunRuang *bangun;
    double sisi, panjang, lebar, tinggi, jari_jari;
    string enter;
    while(true){
        // loop untuk meminta input pilihan user
        while (true){
            system("cls");
            //tampilkan pilihan bangun ruang yang tersedia
            cout << "Menghitung volume bangun ruang" << endl;
            for (int i = 0; i < n; i++){
                cout << i + 1 << ". " << bangunRuang[i] << endl;
            }
            cout << "Pilihan: "; cin >> pilihan;
            if(cin.fail()){
                cin.clear();
                cout << ">> Pilihan harus angka";
                cin.ignore(10000, '\n');    //clear buffer
                getline(cin, enter);
                continue;
            }
            if(pilihan > 0 && pilihan <= n) break;
            else {
                cout << ">> Pilihan harus dari 1-"<< n <<endl;
                cin.ignore(10000, '\n');
                getline(cin, enter);
            }
        }

        switch(pilihan){
            case 1:
                cout << "Masukkan sisi: "; cin >> sisi;
                bangun = new Kubus(sisi);
                bangun->hitungVolume();
                bangun->tampilVolume();
                break;
            case 2:
                cout << "Masukkan panjang: "; cin >> panjang;
                cout << "Masukkan lebar: "; cin >> lebar;
                cout << "Masukkan tinggi: "; cin >> tinggi;
                bangun = new Balok(panjang, lebar, tinggi);
                bangun->hitungVolume();
                bangun->tampilVolume();
                break;
            case 3:
                cout << "Masukkan jari-jari: "; cin >> jari_jari;
                cout << "Masukkan tinggi: "; cin >> tinggi;
                bangun = new Tabung(jari_jari, tinggi);
                bangun->hitungVolume();
                bangun->tampilVolume();
                break;
            case 4:
                cout << "Masukkan jari-jari: "; cin >> jari_jari;
                bangun = new Bola(jari_jari);
                bangun->hitungVolume();
                bangun->tampilVolume();
                break;
            case 5:
                double panjang, lebar, tinggi;
                cout << "Masukkan alas segitiga: "; cin >> lebar;
                cout << "Masukkan tinggi segitiga: "; cin >> tinggi;
                cout << "Masukkan tinggi prisma: "; cin >> panjang;
                bangun = new PrismaSegitiga(panjang, lebar, tinggi);
                bangun->hitungVolume();
                bangun->tampilVolume();
                break;
            default:
                break;
        }

        cout << "Apakah anda ingin menghitung luas bangun ruang lainnya? (y/n): "; cin >> confirm;
        if(confirm == "n" || confirm == "N") {
            delete bangun;
            break;
        }
        else if(confirm == "y" || confirm == "Y"){
            continue;
        }
        else{
            cout << ">> Input tidak valid" << endl;
            cin.ignore(10000, '\n');
            getline(cin, enter);
        }
    }
    cout << ">> Terima kasih telah menggunakan program ini" << endl;
    
    return 0 ;
}