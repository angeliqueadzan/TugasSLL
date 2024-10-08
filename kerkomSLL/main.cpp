#include <iostream>
#include "SLL.h"
using namespace std;


int main() {
    // deklarasi variable List. Nama variable List adalah huruf pertama pada nama lengkap Anda dan huruf terakhir nama lengkap anggota tim Anda
    List RNR;
    adr P;

    // 01. meng create list
    Create_List_RNR(RNR);
    adr elemen1, elemen2, elemen3, elemen4, elemen5, elemen6;

    // meminta user data pertama yang akan dimasukkan ke list
    Penerbangan penerbangan;
    cout << "Masukan data pertama" << endl;
    cout << "Masukan jadwal penerbangan: ";
    cin >> penerbangan.jadwal;
    cout << "Masukan nama lengkap pemesan: ";
    cin >> penerbangan.pemesan;
    cout << "Masukan kode penerbangan: ";
    cin >> penerbangan.kodePenerbangan;

    // 02. melakukan create new elemen berdasarkan data yang diinputkan user
    elemen1 = New_Elemen_RNR(penerbangan);

    // 03. memanggil salah satu jenis insert (jangan insert after)
    Insert_First_RNR(RNR, elemen1);

    // meminta user data kedua yang akan dimasukkan ke list
    cout << "Masukan data kedua" << endl;
    cout << "Masukan jadwal penerbangan: ";
    cin >> penerbangan.jadwal;
    cout << "Masukan nama lengkap pemesan: ";
    cin >> penerbangan.pemesan;
    cout << "Masukan kode penerbangan: ";
    cin >> penerbangan.kodePenerbangan;

    // 04. melakukan create new elemen berdasarkan data yang diinputkan user
    elemen2 = New_Elemen_RNR(penerbangan);

    // 05. memanggil salah satu jenis insert (berbeda dengan insert yang data pertama, jangan Insert after)
    Insert_Last_RNR(RNR, elemen2);

    // meminta user data ketiga yang akan dimasukkan ke list
    cout << "Masukan data ketiga" << endl;
    cout << "Masukan jadwal penerbangan: ";
    cin >> penerbangan.jadwal;
    cout << "Masukan nama lengkap pemesan: ";
    cin >> penerbangan.pemesan;
    cout << "Masukan kode penerbangan: ";
    cin >> penerbangan.kodePenerbangan;

    // 06. melakukan create new elemen berdasarkan data yang diinputkan user
    elemen3 = New_Elemen_RNR(penerbangan);

    // memanggil salah satu jenis insert (insert First)
    Insert_First_RNR(RNR, elemen3);

    // meminta user data keempat yang akan dimasukkan ke list
    cout << "Masukan data keempat" << endl;
    cout << "Masukan jadwal penerbangan: ";
    cin >> penerbangan.jadwal;
    cout << "Masukan nama lengkap pemesan: ";
    cin >> penerbangan.pemesan;
    cout << "Masukan kode penerbangan: ";
    cin >> penerbangan.kodePenerbangan;

    // 07. melakukan create new elemen berdasarkan data yang diinputkan user
    elemen4 = New_Elemen_RNR(penerbangan);

    // 08. memanggil salah satu jenis insert (insert Last)
    Insert_Last_RNR(RNR, elemen4);

    // meminta user data kelima yang akan dimasukkan ke list
    cout << "Masukan data kelima" << endl;
    cout << "Masukan jadwal penerbangan: ";
    cin >> penerbangan.jadwal;
    cout << "Masukan nama lengkap pemesan: ";
    cin >> penerbangan.pemesan;
    cout << "Masukan kode penerbangan: ";
    cin >> penerbangan.kodePenerbangan;
    // 09. melakukan create new elemen berdasarkan data yang diinputkan user
    elemen5 = New_Elemen_RNR(penerbangan);

    // 10. memanggil salah satu jenis insert (insert after) pada data ke 4
    Insert_After_RNR(RNR, elemen4, elemen5);

    // meminta user data keenam yang akan dimasukkan ke list
    cout << "Masukan data keenam" << endl;
    cout << "Masukan jadwal penerbangan: ";
    cin >> penerbangan.jadwal;
    cout << "Masukan nama lengkap pemesan: ";
    cin >> penerbangan.pemesan;
    cout << "Masukan kode penerbangan: ";
    cin >> penerbangan.kodePenerbangan;

    // 11. melakukan create new elemen berdasarkan data yang diinputkan user
    elemen6 = New_Elemen_RNR(penerbangan);

    // 12. memanggil salah satu jenis insert (insert after) pada data ke 4
    Insert_After_RNR(RNR, elemen4, elemen6);

    // memanggil show (01)
    cout << "\nData penerbangan sebelum penghapusan:" << endl;
    Show_RNR(RNR);

    // 13. melakukan pencarian dan penghapusan data kedua dengan memanfaatkan salah satu jenis delete (delete after)
    int cari;
    cout << "Masukan data ke berapa yang ingin dihapus: ";
    cin >> cari;
    P = SearchByPosisi_RNR(RNR, cari);
    adr q = RNR.first;
    while (q->next != P && q->next != nullptr) {
        q = q->next;
    }
    Delete_After_RNR(RNR, q, P);


// 14. melakukan pencarian dengan memanggil function searchby dan penghapusan data dengan memanfaatkan salah satu jenis delete (gunakan pengkondisian, jika data diawal gunakan deletefirst, jika data diakhir gunakan deletelast, kondisi lain gunakan deleteafter)
cout << "Masukan data ke berapa yang ingin dihapus: ";
cin >> cari;
P = SearchByPosisi_RNR(RNR, cari);
if (P != nullptr) {
    if (P == RNR.first) {
        Delete_First_RNR(RNR, P);
    } else {
        adr q = RNR.first;
        while (q->next != P && q->next != nullptr) {
            q = q->next;
        }
        if (P->next == nullptr) {
            Delete_Last_RNR(RNR, P);
        } else {
            Delete_After_RNR(RNR, q, P);
        }
    }
}


    // 15. melakukan pengurutan elemen pada list berdasarkan sub data yang didefinisikan
    SortByHarga_RNR(RNR);

    // memanggil show (02)
    cout << "\nData penerbangan setelah pengurutan:" << endl;
    Show_RNR(RNR);

    return 0;
}
