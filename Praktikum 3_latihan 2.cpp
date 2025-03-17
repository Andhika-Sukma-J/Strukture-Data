#include <iostream>
using namespace std;

int hitungBiaya(int totalDetik) {
    return (totalDetik / 30) * 130;
}

void hitungDurasi(int jamMulai, int menitMulai, int detikMulai,
                  int jamSelesai, int menitSelesai, int detikSelesai) {
    int totalMulai = (jamMulai * 3600) + (menitMulai * 60) + detikMulai;
    int totalSelesai = (jamSelesai * 3600) + (menitSelesai * 60) + detikSelesai;

    int durasiDetik = totalSelesai - totalMulai;

    int durasiJam = durasiDetik / 3600;
    int sisaDetik = durasiDetik % 3600;
    int durasiMenit = sisaDetik / 60;
    int durasiSisaDetik = sisaDetik % 60;

    int biaya = hitungBiaya(durasiDetik);

    cout << "\nDurasi penggunaan: " << durasiJam << " jam "
         << durasiMenit << " menit " << durasiSisaDetik << " detik" << endl;
    cout << "Total biaya rental: Rp. " << biaya << ",-" << endl;
}

int main() {
    int jamMulai, menitMulai, detikMulai;
    int jamSelesai, menitSelesai, detikSelesai;

    cout << " Menghitung waktu penggunakan komputer" << endl;
    cout << " Silahkan Masukkan waktu anda mulai dan selesai " <<endl;
    cout << " Contoh :" << endl;
    cout << " Mulai\t\t: 2(jam) 30(menit) 0 (detik) " << endl;
    cout << " Selesai\t: 4(jam) 0(menit) 0 (detik) " << endl;

    cout << "\n Masukkan waktu mulai (jam menit detik): ";
    cin >> jamMulai >> menitMulai >> detikMulai;

    cout << " Masukkan waktu selesai (jam menit detik): ";
    cin >> jamSelesai >> menitSelesai >> detikSelesai;

    hitungDurasi(jamMulai, menitMulai, detikMulai, jamSelesai, menitSelesai, detikSelesai);

    return 0;
}
