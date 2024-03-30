#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n = 0;

struct Book {
    string title;
    string author;
    int year;
    int pages;
};

vector<Book> library;

void addBook() {
    cout << endl;
    Book newBook;
    cin.ignore();  
    cout << "Masukkan judul buku: ";
    getline(cin, newBook.title);
    cout << "Masukkan penulis buku: ";
    getline(cin, newBook.author);
    cout << "Masukkan tahun terbit: ";
    cin >> newBook.year;
    cin.ignore();  
    cout << "Masukkan jumlah halaman: ";
    cin >> newBook.pages;
    cin.ignore();  
    library.push_back(newBook);
    cout << endl;
    n++;
}

void displayBooks() {
    int count = 1;
    if(n == 0){
        cout << "\n\nDaftar buku masih kosong. Silahkan tambah buku!\n";
    } else { 
        cout << "DAFTAR BUKU\n";
        for (const auto &book : library) {
            cout << count << ". ";
            cout << "Judul: " << book.title << ", Penulis: " << book.author << ", Tahun: " << book.year << ", Halaman: " << book.pages << endl;
            count++;
        }
    }
    cout << endl;
}

void deleteBook() {
    string title;
    if (n == 0){
        cout << "\nDaftar buku masih kosong. Silahkan tambah buku!\n";
    } else {
        displayBooks();
        cout << "Masukkan judul buku yang ingin dihapus: ";
        cin.ignore();  // ignore the newline in the buffer
        getline(cin, title);
        auto it = remove_if(library.begin(), library.end(), [&title](const Book &book) {
            return book.title == title;
        });
        if (it != library.end()) {
            library.erase(it, library.end());
            cout << "Buku \"" << title << "\" telah dihapus!" << endl;
        } else {
            cout << "Buku \"" << title << "\" tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

void searchBook() {
    if (n == 0){
        cout << "\nDaftar buku masih kosong. Silahkan tambah buku!\n";
    } else {
        cout << endl;
        int choice;
        cout << "Cari buku berdasarkan:\n1. Judul\n2. Penulis\n\nPilihan: ";
        cin >> choice;
        cin.ignore();  
        string query;
        bool bookFound = false;
        if (choice == 1) {
            cout << "Masukkan judul buku yang ingin dicari: ";
            getline(cin, query);
            int count = 1;
            for (const auto &book : library) {
                if (book.title == query) {
                    cout << count << ". " << "Judul: " << book.title << ", Penulis: " << book.author << ", Tahun: " << book.year << ", Halaman: " << book.pages << endl;
                    bookFound = true;
                    count++;
                }
            }
        } else if (choice == 2) {
            cout << "Masukkan penulis buku yang ingin dicari: ";
            getline(cin, query);
            int count = 1;
            for (const auto &book : library) {
                if (book.author == query) {
                    cout << count << ". " << "Judul: " << book.title << ", Penulis: " << book.author << ", Tahun: " << book.year << ", Halaman: " << book.pages << endl;
                    bookFound = true;
                    count++;
                }
            }
        } else {
            cout << "Pilihan tidak valid!" << endl;
            return;
        }
        if (!bookFound) {
            cout << "Buku atau penulis \"" << query << "\" tidak ditemukan!" << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void countPages() {
    if (n == 0){
        cout << "\nDaftar buku masih kosong. Total halaman adalah 0!\n";
    } else {
        cout << endl;
        int total = 0;
        for (const auto &book : library) {
            total += book.pages;
        }
        cout << "Total halaman: " << total << endl << endl;
    }  
    cout << endl;

}

void updateBook() {
    if (n == 0){
        cout << "\nDaftar buku masih kosong. Silahkan tambah buku!\n";
    } else {
        cout << endl;
        displayBooks();
        string title;
        cout << "Masukkan judul buku yang ingin diperbarui: ";
        cin.ignore(); 
        getline(cin, title);
        for (auto &book : library) {
            if (book.title == title) {
                cout << "Masukkan judul buku baru: ";
                getline(cin, book.title);
                cout << "Masukkan penulis buku baru: ";
                getline(cin, book.author);
                cout << "Masukkan tahun terbit baru: ";
                cin >> book.year;
                cin.ignore();  
                cout << "Masukkan jumlah halaman baru: ";
                cin >> book.pages;
                cin.ignore(); 
                cout << "Buku \"" << title << "\" telah diperbarui!" << endl << endl;
                return;
            }
        }
        cout << "Buku \"" << title << "\" tidak ditemukan!" << endl;
    }
    cout << endl;
}

void sortBooks() {
    if (n == 0){
        cout << "\nDaftar buku masih kosong. Silahkan tambah buku!\n";
    } else {
        cout << endl;
        int choice;
        cout << "\nUrutkan buku berdasarkan:\n1. Judul\n2. Penulis\n3. Tahun Terbit\n4. Jumlah Halaman\n\nPilihan: ";
        cin >> choice;
        cin.ignore();  
        switch (choice) {
            case 1:
                sort(library.begin(), library.end(), [](const Book &a, const Book &b) {
                    return a.title < b.title;
                });
                break;
            case 2:
                sort(library.begin(), library.end(), [](const Book &a, const Book &b) {
                    return a.author < b.author;
                });
                break;
            case 3:
                sort(library.begin(), library.end(), [](const Book &a, const Book &b) {
                    return a.year < b.year;
                });
            break;
            case 4:
                sort(library.begin(), library.end(), [](const Book &a, const Book &b) {
                    return a.pages < b.pages;
                });
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                return;
        }
        cout << "\nBuku telah diurutkan!" << endl << endl;
    }
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "====================\nPROGRAM PERPUSTAKAAN\n====================\n\n";
        cout << "Masukan perintah\n";
        cout << "1. Tambah Buku\n2. Tampilkan Buku\n3. Hapus Buku\n4. Cari Buku\n5. Hitung Halaman\n6. Perbarui Buku\n7. Urutkan Buku\n0. Keluar\n\nPilihan: ";
        cin >> choice;
        
        if(choice >= 1 && choice <= 7){
            switch (choice) {
                case 1: addBook(); break;
                case 2: displayBooks(); break;
                case 3: deleteBook(); break;
                case 4: searchBook(); break;
                case 5: countPages(); break;
                case 6: updateBook(); break;
                case 7: sortBooks(); break;
            }
        } else if (choice != 0) {
            cout << "Pilihan tidak valid!\n\n";
        }
    } while (choice != 0);

    return 0;
}
