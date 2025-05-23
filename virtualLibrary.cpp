#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

struct Book{
    string title;
    int stock;
};

string enter;

void error(string msg){
    cout << msg << endl;
    cin.ignore(10000, '\n'); getline(cin, enter);
}

class Library{
private:
    vector<Book> books;
    queue<string> toBorrow;     //antrean meminjam jika buku kosong
    queue<string> borrowed;     //buku yang sedang dipinjam
    stack<string> returned;     //riwayat pengembalian buku
public:
    void addBook(string title, int stock){
        Book newBook;
        newBook.title = title;
        newBook.stock = stock;
        if(books.empty()){
            books.push_back(newBook);
        } else {
            // cek jika ada judul buku yang sama
            // jika ada, tambah stocknya
            // jika tidak ada, tambahkan ke list buku
            for(int i = 0; i < books.size(); i++){
                if(books[i].title == title){
                    books[i].stock += stock;
                    return;
                }
            }
            books.push_back(newBook);
        }
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
                if(books[i].stock < books[j].stock){
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
            }
        }
    }
    void displayBook(){
        while (true){
            system("cls");
            int choice;
            cout << "Tampilkan berdasarkan:" << endl;
            cout << "1. Judul" << endl;
            cout << "2. Jumlah stock" << endl;
            cout << "Pilihan (1-2): "; cin >> choice;
            if(cin.fail()){
                cin.clear();
                error("Input harus angka!");
                continue;
            }
            if(choice == 1){
                sortByName();
            } else if(choice == 2){
                sortByStock();
            } else {
                error("Pilihan harus dari 1-2!");
                continue;
            }
        }
        for(int i = 0; i < books.size(); i++){
            cout << "Judul: " << books[i].title << endl;
            cout << "Stock: " << books[i].stock << endl;
        } cin.ignore(10000, '\n'); getline(cin, enter);
    }
    void searchBook(string searchTitle){
        if(books.empty()){
            error("Tidak ada buku yang tersedia saat ini");
            return;
        }
        for(int i = 0; i < books.size(); i++){
            if(books[i].title == searchTitle){
                cout << "Judul: " << books[i].title << endl;
                cout << "Stock: " << books[i].stock << endl;
                return;
            }
        }
        error("Buku tidak ditemukan");
    }
    void borrowBook(string title){
        if(books.empty()){
            error("Tidak ada buku yang tersedia saat ini");
            return;
        }
        for(int i = 0; i < books.size(); i++){
            if(books[i].title == title){
                // jika stock ada, dipinjam
                // jika tidak ada, tambahkan ke antrean
                if(books[i].stock > 0){
                    error("Anda meminjam buku " + books[i].title);
                    books[i].stock--;
                    borrowed.push(title);
                } else {
                    error("Stock buku habis, berhasil ditambahkan ke antrean menunggu");
                    toBorrow.push(title);
                }
                return;
            }
        }
        error("Buku tidak ditemukan");
    }
    void returnBook(string title){
        if (borrowed.empty()){
            error("Tidak ada buku yang sedang dipinjam saat ini");
            return;
        }
        for(int i = 0; i < books.size(); i++){
            if(books[i].title == title){
                cout << "Anda mengembalikan buku " << books[i].title << endl;
                books[i].stock++;
                returned.push(title);
                return;
            }
        }
        error("Buku digigit agnes");
    }
    void returnedHistory(){
        if(returned.empty()){
            error("Tidak ada buku yang dapat dikembalikan");
            return;
        }
        // cout << "Riwayat pengembalian buku terakhir: " << endl;
        // while(!returned.empty()){
        //     cout << returned.top() << endl;
        //     returned.pop();
        // }
    }
};


void menuUser(Library &library){
    system("cls");
    cout << "Selamat datang di Virtual Library";
    cout << "1. Lihat buku";
    cout << "2. Cari buku";
    cout << "3. Pinjam buku";
    cout << "4. Buku yang sedang dipinjam";
    cout << "5. Balikkan buku";
}

void menuAdmin(){

}

int main(){
    

    return 0;
}