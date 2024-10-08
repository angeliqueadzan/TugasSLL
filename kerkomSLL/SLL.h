#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

// Type penerbangan
struct Penerbangan {
    string jadwal;
    string pemesan;
    int kodePenerbangan;
};

// Type infotype
typedef Penerbangan infotype;

// Type adr
typedef struct elmList *adr;

// Type elmList
struct elmList {
    infotype info;
    adr next;
};

// Type List
struct List {
    adr first;
};

// Deklarasi fungsi dan prosedur
void Create_List_RNR(List &RNR);
adr New_Elemen_RNR(infotype data);
void Insert_First_RNR(List &RNR, adr p);
void Insert_Last_RNR(List &RNR, adr p);
void Insert_After_RNR(List &RNR, adr prec, adr p);
void Delete_First_RNR(List &RNR, adr &p);
void Delete_Last_RNR(List &RNR, adr &p);
void Delete_After_RNR(List &RNR, adr prec, adr &p);
void Show_RNR(List RNR);
void SortByHarga_RNR(List &RNR);
adr SearchByPosisi_RNR(List L, int posisi); // Prosedur pencarian berdasarkan nama maskapai

#endif // SLL_H_INCLUDED
