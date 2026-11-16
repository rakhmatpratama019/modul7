
#include <iostream>
#include "stack.h"

using namespace std;

// Membuat stack kosong
void createStack(Stack &S) {
    S.top = 0;
}

// Menambahkan elemen ke stack
void push(Stack &S, infotype x) {
    if (S.top < MAX) {
        S.info[S.top] = x;
        S.top++;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

// Mengambil elemen paling atas
infotype pop(Stack &S) {
    if (S.top > 0) {
        S.top--;
        return S.info[S.top];
    }

    cout << "Stack kosong!" << endl;
    return -1;
}

// Menampilkan isi stack
void printInfo(Stack S) {
    if (S.top == 0) {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "[TOP] ";

    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }

    cout << endl;
}

// Membalik isi stack
void balikStack(Stack &S) {
    int temp[MAX];
    int jumlah = S.top;

    for (int i = 0; i < jumlah; i++) {
        temp[i] = S.info[jumlah - 1 - i];
    }

    for (int i = 0; i < jumlah; i++) {
        S.info[i] = temp[i];
    }
}

// Menerima input karakter sampai pengguna menekan Enter
void getInputStream(Stack &S) {
    char karakter;

    cout << "Masukkan angka (tekan Enter untuk selesai): ";

    while (cin.get(karakter) && karakter != '\n') {
        if (karakter >= '0' && karakter <= '9') {
            push(S, karakter - '0');
        }
    }
}
