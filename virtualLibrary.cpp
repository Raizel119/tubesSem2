#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm> //for erase
using namespace std;

struct Book{
    string title;
    int qty;
    //untuk proses penghapusan buku dari vector menggunakan erase()
    bool operator==(const Book& other) const {
        return title == other.title;
    }
};

string enter;

void displayMessage(string msg){
    cout << msg << endl;
    cin.ignore(10000, '\n'); getline(cin, enter);
}

class Library{
private:
    vector<Book> books;
    vector<Book> borrowed;     //buku yang sedang dipinjam
    stack<string> returned;     //riwayat pengembalian buku
public:
    void addBook(){
        Book newBook;
        cin.ignore(10000, '\n');
        cout << "Masukkan judul buku: "; getline(cin, newBook.title);
        if(newBook.title == "") {
            displayMessage("Judul buku tidak boleh kosong");
            return;
        }
        cout << "Masukkan stock buku: "; cin >> newBook.qty;
        if(newBook.qty < 1) {
            displayMessage("Stock buku yang mau ditambahkan tidak boleh kurang dari 1");
            return;
        }
        if(books.empty()){
            books.push_back(newBook);
        } else {
            // cek jika ada judul buku yang sama
            // jika ada, tambah stocknya
            // jika tidak ada, tambahkan ke list buku
            for(int i = 0; i < books.size(); i++){
                if(books[i].title == newBook.title){
                    books[i].qty += newBook.qty;
                    return;
                }
            }
            books.push_back(newBook);
        }
        displayMessage("Buku berhasil ditambahkan");
    }
    void sortByName(){
        for(int i = 0; i < books.size(); i++){
            for(int j = i + 1; j < books.size(); j++){
                if(books[i].title > books[j].title){
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }
    void sortByStock(){
        for(int i = 0; i < books.size(); i++){
            for(int j = i + 1; j < books.size(); j++){
                if(books[i].qty < books[j].qty){
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }
    void displayBook(){
        if(books.empty()){
            displayMessage("Tidak ada buku yang tersedia saat ini");
            return;
        }
        while (true){
            system("cls");
            int choice;
            cout << "Tampilkan berdasarkan:" << endl;
            cout << "1. Judul" << endl;
            cout << "2. Jumlah stock" << endl;
            cout << "Pilihan (1-2): "; cin >> choice;
            if(cin.fail()){
                cin.clear();
                displayMessage("Input harus angka!");
                continue;
            }
            if(choice == 1){
                sortByName(); break;
            } else if(choice == 2){
                sortByStock(); break;
            } else {
                displayMessage("Pilihan harus dari 1-2!");
                continue;
            }
        }
        system("cls");
        for(int i = 0; i < books.size(); i++){
            cout << i+1 << ". Judul: \"" << books[i].title << "\", Stock: "<< books[i].qty << endl;
        } cin.ignore(10000, '\n'); getline(cin, enter);
    }
    void searchBook(){
        sortByName();
        //tampilkan daftar buku yang tersedia berdasarkan nama
        for(int i = 0; i < books.size(); i++){
            cout << i+1 << ". Judul: " << books[i].title << ", Stock: "<< books[i].qty << endl;
        }
        string searchTitle;
        cout << "Masukkan judul buku yang ingin dicari: "; cin >> searchTitle;
        if(books.empty()){
            displayMessage("Tidak ada buku yang tersedia saat ini");
            return;
        }
        for(int i = 0; i < books.size(); i++){
            if(books[i].title == searchTitle){
                cout << "Judul: " << books[i].title << endl;
                cout << "Stock: " << books[i].qty << endl;
                cin.ignore(10000, '\n'); getline(cin, enter);
                return;
            }
        }
        displayMessage("Buku tidak ditemukan");
    }
    void borrowBook(){
        if(books.empty()){
            displayMessage("Tidak ada buku yang tersedia saat ini");
            return;
        }
        string title;
        sortByName();
        //tampilkan daftar buku yang tersedia berdasarkan nama
        for(int i = 0; i < books.size(); i++){
            cout << i+1 << ". Judul: " << books[i].title << ", Stock: "<< books[i].qty << endl;
        }
        cout << "Masukkan judul buku yang ingin dipinjam: "; cin >> title;
        for(int i = 0; i < books.size(); i++){
            if(books[i].title == title){
                // jika stock ada, buku dpinjam
                // jika tidak ada, stock habis
                if(books[i].qty > 0){
                    displayMessage("Berhasil meminjam buku " + books[i].title);
                    books[i].qty--;

                    borrowed.push_back({books[i].title, 1});
                } else {
                    displayMessage("Stock buku habis, silahkan pinjam buku lain");
                }
                return;
            }
        }
        displayMessage("Buku tidak ditemukan");
    }
    void displayBorrowed(){
        if(borrowed.empty()){
            displayMessage("Tidak ada buku yang sedang dipinjam saat ini");
            return;
        }
        cout << "Buku yang sedang dipinjam: " << endl;
        for (int i = 0; i < borrowed.size(); i++){
            if(borrowed[i].qty == 0) continue;
            cout << i+1 << ". " << borrowed[i].title << ", Jumlah: " << borrowed[i].qty << endl;
        }
    }
    void returnBook(){
        if (borrowed.empty()){
            displayMessage("Tidak ada buku yang sedang dipinjam saat ini");
            return;
        }
        displayBorrowed();
        string title;
        cout << "Masukkan judul buku yang ingin dikembalikan: "; cin >> title;
        for(int i = 0; i < borrowed.size(); i++){
            //cari buku yang ingin dikembalikan
            if(borrowed[i].title == title){
                //jika ada, tambahkan ke stock buku & hapus buku dari daftar buku yang dipinjam
                for(int j = 0; j < books.size(); j++){
                    if(books[j].title == title){
                        books[j].qty+= borrowed[i].qty; 
                        borrowed.erase(remove(borrowed.begin(), borrowed.end(), borrowed[i]), borrowed.end());
                        returned.push(title);        
                        displayMessage("Buku berhasil dikembalikan");
                        break;
                    }
                }
                return;
            } else {
                displayMessage("Buku tidak ditemukan"); return;
            }
        }
        displayMessage("Buku tidak ditemukan");
    }
    void returnedHistory(){
        if(returned.empty()){
            displayMessage("Daftar pengembalian buku masih kosong");
            return;
        }
        stack<string> temp = returned;
        cout << "Riwayat pengembalian buku terakhir: " << endl;
        while(!returned.empty()){
            cout << returned.top() << endl;
            returned.pop();
        }
        returned = temp;
        cin.ignore(10000, '\n'); getline(cin, enter);
    }
};

int main(){
    Library library;
    int pilihan, stock;
    string title;
    while(true){
        system("cls");
        cout << "Selamat datang di Virtual Library" << endl;
        cout << "1. Tambahkan buku" << endl;
        cout << "2. Lihat buku" << endl;
        cout << "3. Cari buku" << endl;
        cout << "4. Pinjam buku" << endl;
        cout << "5. Buku yang sedang dipinjam" << endl;
        cout << "6. Balikkan buku" << endl;
        cout << "7. Riwayat pengembalian buku" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilihan: "; cin >> pilihan;
        if(cin.fail()){
            cin.clear();
            displayMessage("Input harus angka!");
            continue;
        } else if(pilihan < 1 || pilihan > 8){
            displayMessage("Pilihan harus dari 1-8!");
            continue;
        } else {
            system("cls");
            switch(pilihan){
                case 1: library.addBook(); break;
                case 2: library.displayBook(); break;
                case 3: library.searchBook(); break;
                case 4: library.borrowBook(); break;
                case 5: library.displayBorrowed(); break;
                case 6: library.returnBook(); break;
                case 7: library.returnedHistory(); break;
                case 8: return 0;
            }
        }
    }
    cout << "Terima kasih telah menggunakan Virtual Library";

    return 0;
}