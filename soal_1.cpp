#include <iostream>
using namespace std;

void programDesc() {
    cout << "+====================================================================================+\n";
    cout << "Program mencari nilai terkecil, terbesar dan rata-rata dari array satu dimensi yang\nkita buat. Program ini akan meminta input dari user berupa jumlah elemen pada array\ndan isinya lalu menampilkan nilai terkecil, terbesar dan rata-rata dari elemen array tersebut.\n";
    cout << "+====================================================================================+\n\n";
}

int main() {
    programDesc();
    
    int n;
    cout << "Masukkan jumlah elemen pada array: ";
    cin >> n;
    int arr[n];

    cout << "\nMasukkan nilai-nilai elemen" << endl;
    for(int i = 0; i < n; i++) {
        cout << "Masukan elemen ke-" << i+1 << ": ";
        cin >> arr[i];
    }
    cout << endl;

    int min = arr[0];
    int max = arr[0];
    int sum = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
        sum += arr[i];
    }
    double avg = static_cast<double>(sum) / n;

    cout << "Nilai minimum: " << min << endl;
    cout << "Nilai maksimum: " << max << endl;
    cout << "Rata-rata: " << avg << endl;

    return 0;
}
