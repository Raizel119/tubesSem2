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
};
class PrismaSegitiga : public BangunRuang{
private:
    double aSegitiga, tSegitiga, tinggiPrisma;
public:
    PrismaSegitiga(double aSegitiga, double tSegitiga, double tinggiPrisma) : BangunRuang("Prisma Segitiga"){
        this->aSegitiga = aSegitiga;    //alas segitiga
        this->tSegitiga = tSegitiga;    //tinggi segitiga
        this->tinggiPrisma = tinggiPrisma;
    }
    void hitungVolume() override{
        volume = aSegitiga * tSegitiga * tinggiPrisma / 2;
    }
};

int main(){
    string bangunRuang[] = {"Kubus", "Balok", "Tabung", "Bola", "Prisma Segitiga"};
    int n = sizeof(bangunRuang) / sizeof(bangunRuang[0]);   //menghitung jumlah bangun ruang
    int pilihan;    //input pilihan user
    string enter;

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
        if(pilihan > 0 && pilihan < n) break;
        else {
            cout << ">> Pilihan harus dari 1-"<< n <<endl;
            cin.ignore(10000, '\n');
            getline(cin, enter);
        }
    }
    
    return 0 ;
}