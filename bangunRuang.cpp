#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;

class BangunRuang{
protected:
    double volume, luas_permukaan;
    string nama;
public:
    BangunRuang(string nama){
        this->nama = nama;
    }
    virtual void hitungVolume() = 0;
    double getVolume(){                 //enkapsulasi
        return volume;
    }
    virtual void hitungLuasPermukaan() = 0;
    double getLuasPermukaan(){          //enkapsulasi
        return luas_permukaan;
    }
    string getNama(){
        return nama;
    }
    void tampilVolume(){
        cout << "Bangun ruang " << getNama() << " memiliki volume: " << getVolume() << endl;
    }
    void tampilLuasPermukaan(){
        cout << "Bangun ruang " << getNama() << " memiliki luas permukaan: " << getLuasPermukaan() << endl;
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
    void hitungLuasPermukaan() override{       //abstraksi
        luas_permukaan = 6*sisi * sisi;
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
    void hitungLuasPermukaan() override{
        luas_permukaan = 2*(panjang * lebar + panjang * tinggi + lebar* tinggi);
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
    void hitungLuasPermukaan() override{
        luas_permukaan = 2 * 3.14 * jari_jari * (jari_jari + tinggi);
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
        volume = (4.0/3.0) * 3.14 * jari_jari * jari_jari * jari_jari;
    }
    void hitungLuasPermukaan() override{
        luas_permukaan = 4* 3.14* jari_jari*jari_jari;
    }
    ~Bola(){}
};
class PrismaSegitiga : public BangunRuang{
private:
    double panjang, lebar, tinggi, luas_alas, sisi_miring, keliling_alas, luas_sisi;
public:
    PrismaSegitiga(double panjang, double lebar, double tinggi) : BangunRuang("Prisma Segitiga"){
        this->panjang = panjang;    //tinggi prisma
        this->lebar = lebar;    //alas segitiga
        this->tinggi = tinggi;      //tinggi segitiga
    }
    void hitungVolume() override{
        volume = panjang * lebar * tinggi / 2;
    }
    void hitungLuasPermukaan() override{
        luas_alas = 0.5 * lebar * tinggi;  // luas segitiga
        sisi_miring = sqrt(lebar * lebar + tinggi * tinggi);  // sisi miring segitiga (teorema pythagoras)
        keliling_alas = lebar + tinggi + sisi_miring;  // keliling segitiga
        luas_sisi = keliling_alas * panjang;  // luas sisi tegak
        
        luas_permukaan = 2 * luas_alas + luas_sisi;
    }
    ~PrismaSegitiga(){}
};

int main(){
    string bangunRuang[] = {"Kubus", "Balok", "Tabung", "Bola", "Prisma Segitiga"};
    string jenisHitung[] = {"Volume", "Luas Permukaan"};
    int n = sizeof(bangunRuang) / sizeof(bangunRuang[0]);   //hitung jumlah bangun ruang
    int jenis = sizeof(jenisHitung) / sizeof(jenisHitung[0]);  //hitung berapa jenis perhitungan
    int pilihanBangun, pilihanJenis;    //input pilihan user
    string confirm; //input konfirmasi user
    BangunRuang *bangun;
    double sisi, panjang, lebar, tinggi, jari_jari;
    string enter;
    while(true){
        // loop untuk meminta input pilihan jenis perhitungan
        while (true){
            system("cls");
            //tampilkan pilihan jenis perhitungan
            cout << "=== KALKULATOR BANGUN RUANG ===" << endl;
            cout << "Pilih jenis perhitungan:" << endl;
            for (int i = 0; i < jenis; i++){
                cout << i + 1 << ". " << jenisHitung[i] << endl;
            }
            cout << "Pilihan: "; cin >> pilihanJenis;
            if(cin.fail()){
                cin.clear();
                cout << ">> Pilihan harus angka";
                cin.ignore(10000, '\n');    //clear buffer
                getline(cin, enter);
                continue;
            }
            if(pilihanJenis > 0 && pilihanJenis <= jenis) break;
            else {
                cout << ">> Pilihan harus dari 1-"<< jenis <<endl;
                cin.ignore(10000, '\n');
                getline(cin, enter);
            }
        }

        // loop untuk meminta input pilihan jenis bangun ruang
        while (true){
            system("cls");
            //tampilkan pilihan bangun ruang yang tersedia
            cout << "=== MENGHITUNG " << jenisHitung[pilihanJenis-1] << " BANGUN RUANG ===" << endl;
            cout << "Pilih bangun ruang:" << endl;
            for (int i = 0; i < n; i++){
                cout << i + 1 << ". " << bangunRuang[i] << endl;
            }
            cout << "Pilihan: "; cin >> pilihanBangun;
            if(cin.fail()){
                cin.clear();
                cout << ">> Pilihan harus angka";
                cin.ignore(10000, '\n');    //clear buffer
                getline(cin, enter);
                continue;
            }
            if(pilihanBangun > 0 && pilihanBangun <= n) break;
            else {
                cout << ">> Pilihan harus dari 1-"<< n <<endl;
                cin.ignore(10000, '\n');
                getline(cin, enter);
            }
        }

        // 
        switch(pilihanBangun){
            case 1:
                cout << "Masukkan sisi: "; cin >> sisi;
                bangun = new Kubus(sisi);
                break;
            case 2:
                cout << "Masukkan panjang: "; cin >> panjang;
                cout << "Masukkan lebar: "; cin >> lebar;
                cout << "Masukkan tinggi: "; cin >> tinggi;
                bangun = new Balok(panjang, lebar, tinggi);
                break;
            case 3:
                cout << "Masukkan jari-jari: "; cin >> jari_jari;
                cout << "Masukkan tinggi: "; cin >> tinggi;
                bangun = new Tabung(jari_jari, tinggi);
                break;
            case 4:
                cout << "Masukkan jari-jari: "; cin >> jari_jari;
                bangun = new Bola(jari_jari);
                break;
            case 5:
                double panjang, lebar, tinggi;
                cout << "Masukkan alas segitiga: "; cin >> lebar;
                cout << "Masukkan tinggi segitiga: "; cin >> tinggi;
                cout << "Masukkan tinggi prisma: "; cin >> panjang;
                bangun = new PrismaSegitiga(panjang, lebar, tinggi);
                break;
            default:
                break;
        }

        // Hitung dan tampilkan hasil berdasarkan pilihan jenis
            if(pilihanJenis == 1){ // Volume
                bangun->hitungVolume();
                bangun->tampilVolume();
            }
            else{ // Luas Permukaan
                bangun->hitungLuasPermukaan();
                bangun->tampilLuasPermukaan();
            }

        cout << "Apakah anda ingin menghitung bangun ruang lainnya? (y/n): "; cin >> confirm;
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
