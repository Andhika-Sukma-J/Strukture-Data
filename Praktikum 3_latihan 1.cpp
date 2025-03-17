#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Nilai {
    float absen, tugas, uts, uas, akhir;
    char huruf;
};

struct Mahasiswa {
    string npm, nama;
    Nilai nilai;
};

const int MAX_MAHASISWA = 20;
Mahasiswa dataMahasiswa[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void hitungNilai(Nilai &n) {
    n.akhir = (0.1 * n.absen) + (0.2 * n.tugas) + (0.3 * n.uts) + (0.4 * n.uas);
    if (n.akhir > 80) n.huruf = 'A';
    else if (n.akhir > 70) n.huruf = 'B';
    else if (n.akhir > 60) n.huruf = 'C';
    else n.huruf = 'D';
}

void inputData() {
    if (jumlahMahasiswa >= MAX_MAHASISWA) {
        cout << " Data mahasiswa penuh!" << endl;
        return;
    }
    Mahasiswa m;
    cout << "\n Masukkan NPM\t\t: "; cin >> m.npm;
    cout << " Masukkan Nama\t\t: ";
    cin.ignore(); getline(cin, m.nama);
    cout << " Masukkan Nilai Absen\t: ";
    cin >> m.nilai.absen;
    cout << " Masukkan Nilai Tugas\t: ";
    cin >> m.nilai.tugas;
    cout << " Masukkan Nilai UTS\t: ";
    cin >> m.nilai.uts;
    cout << " Masukkan Nilai UAS\t: ";
    cin >> m.nilai.uas;
    cout << endl;
    hitungNilai(m.nilai);
    dataMahasiswa[jumlahMahasiswa++] = m;
}

void tampilData() {
    cout << left << setw(15) << "NPM" << setw(25) << "Nama" << setw(10) << "Absen" << setw(10) << "Tugas"
         << setw(10) << "UTS" << setw(10) << "UAS" << setw(10) << "Akhir" << "Huruf" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        Mahasiswa m = dataMahasiswa[i];
        cout << left << setw(15) << m.npm << setw(25) << m.nama << setw(10) << m.nilai.absen << setw(10) << m.nilai.tugas
             << setw(10) << m.nilai.uts << setw(10) << m.nilai.uas << setw(10) << m.nilai.akhir << m.nilai.huruf << endl;
    }
}

void editData() {
    string npm;
    cout << " Masukkan NPM yang akan diedit: "; cin >> npm;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (dataMahasiswa[i].npm == npm) {
            cout << "\n Masukkan Nilai Absen\t: ";
            cin >> dataMahasiswa[i].nilai.absen;
            cout << " Masukkan Nilai Tugas\t: ";
            cin >> dataMahasiswa[i].nilai.tugas;
            cout << " Masukkan Nilai UTS\t: ";
            cin >> dataMahasiswa[i].nilai.uts;
            cout << " Masukkan Nilai UAS\t: ";
            cin >> dataMahasiswa[i].nilai.uas;
            cout << endl;
            hitungNilai(dataMahasiswa[i].nilai);
            cout << " Data berhasil diperbarui!" << endl;
            return;
        }
    }
    cout << " Data tidak ditemukan!" << endl;
}

void hapusData() {
    string npm;
    cout << " Masukkan NPM yang akan dihapus: "; cin >> npm;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (dataMahasiswa[i].npm == npm) {
            for (int j = i; j < jumlahMahasiswa - 1; j++) {
                dataMahasiswa[j] = dataMahasiswa[j + 1];
            }
            jumlahMahasiswa--;
            cout << " Data berhasil dihapus!" << endl;
            return;
        }
    }
    cout << " Data tidak ditemukan!" << endl;
}

int main() {
    int pilihan;
        cout << "\n";
        cout << " SELAMAT DATANG\n";
        cout << " SILAHKAN PILIH\n";
    do {
        cout << " \n Menu:\n";
        cout << " 1. Input Data Mahasiswa\n";
        cout << " 2. Tampil Data Mahasiswa\n";
        cout << " 3. Edit Data Mahasiswa\n";
        cout << " 4. Hapus Data Mahasiswa\n";
        cout << " 5. Keluar\n";
        cout << " Pilih menu:\n";
        cout << "\n";
        cin >> pilihan;
        switch ( pilihan) {
            case 1: inputData();
            cout << "\n Silahkan pilih lagi...\n";break;
            case 2: tampilData();
            cout << "\n Silahkan pilih lagi...\n";break;
            case 3: editData();
            cout << "\n Silahkan pilih lagi...\n";break;
            case 4: hapusData();
            cout << "\n Silahkan pilih lagi...\n";break;
            case 5: cout << " Program selesai." << endl; break;
            default: cout << " Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);
    return 0;
}
