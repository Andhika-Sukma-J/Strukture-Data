#include <iostream>
using namespace std;
int main()
{
    int arr[5];
    int *ptr;
    cout << "Masukkan 5 angka:\n";
    for (int i = 0; i < 5; ++i)
    {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }
    ptr = arr;
    cout << "\nAlamat dan Nilai Array:\n";
    for (int i = 0; i < 5; ++i)
    {
        cout << "Alamat: " << (ptr + i) << " | Nilai: " << *(ptr + i) << endl;
    }
    return 0;
}
