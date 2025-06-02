#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

struct Buku {
    int id;
    string judul;
    string penulis;
    int rak;
    Buku* next;
};

Buku* head = nullptr;
queue<string> antrian;
stack<string> riwayat;

const int JUMLAH_RAK = 5; // Graph: Pemetaan Rak
int rakGraph[JUMLAH_RAK][JUMLAH_RAK];

void inisialisasiRak() {
    for (int i = 0; i < JUMLAH_RAK; i++) {
        for (int j = 0; j < JUMLAH_RAK; j++) {
            rakGraph[i][j] = 0;
        }
    }
    rakGraph[4][1] = rakGraph[1][3] = 1;
    rakGraph[2][3] = rakGraph[3][4] = 1;
    rakGraph[3][2] = rakGraph[2][1] = 1;
    rakGraph[1][4] = rakGraph[4][2] = 1;
}

void tampilkanPetaRak() {
    cout << "\nPemetaan Rak:\n    ";
    for (int i = 0; i < JUMLAH_RAK; i++) cout << i << " ";

    cout << "\n";
    for (int i = 0; i < JUMLAH_RAK; i++) {
        cout << i << " | ";
        for (int j = 0; j < JUMLAH_RAK; j++) {
            cout << rakGraph[i][j] << " ";
        }
        cout << "\n";
    }
}

void tambahBuku(int id, string judul, string penulis, int rak) {
    Buku* baru = new Buku{id, judul, penulis, rak, head};
    head = baru;
}

void tampilkanBuku() {
    Buku* temp = head;
    while (temp) {
        cout << temp->id << ". " << temp->judul << " by " << temp->penulis << " (Rak " << temp->rak << ")\n";
        temp = temp->next;
    }
}

void pinjamBuku(string judul) {
    antrian.push(judul);
    cout << "Meminjam: " << judul << endl;
}

void prosesPeminjaman() {
    if (!antrian.empty()) {
        cout << "Diproses: " << antrian.front() << endl;
        antrian.pop();
    }
}

void kembalikanBuku(string judul) {
    riwayat.push(judul);
    cout << "Dikembalikan: " << judul << endl;
}

void tampilkanRiwayat() {
    stack<string> temp = riwayat;
    cout << "\nRiwayat Pengembalian:\n";
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
}

int main() {
    inisialisasiRak();
    tampilkanPetaRak();

    // Daftar buku yang ada di rak
    tambahBuku(1, "The C++ Programming Language", "Bjarne Stroustrup", 1);
    tambahBuku(1, "Python Crash Course", "Eric Matthes", 1);

    tambahBuku(2, "Introduction to Algorithms", "Thomas H. Cormen", 2);
    tambahBuku(2, "Algorithms", "Jeff Erickson", 2);

    tambahBuku(3, "Filosofi Teras", "Henry Manampiring", 3);
    tambahBuku(3, "Dunia Sophie", "Jostein Gaarder", 3);

    tambahBuku(4, "Laskar Pelangi", "Andrea Hirata", 4);
    tambahBuku(4, "Laut Bercerita", " Leila S. Chudori", 4);

    cout << "\nDaftar Buku:\n";
    tampilkanBuku();

    cout << "\n-- Buku yang dipinjam --\n";
    pinjamBuku("The C++ Programming Language by Bjarne Stroustrup");
    prosesPeminjaman();

    cout << "\n-- Buku yang dikembalikan --\n";
    kembalikanBuku("Laut Bercerita by  Leila S. Chudori");
    tampilkanRiwayat();

    return 0;
}
