#include "SLL.h"

void Create_List_RNR(List &L) {
    L.first = nullptr;
}

adr New_Elemen_RNR(infotype data) {
    adr p = new elmList;
    p->info = data;
    p->next = nullptr;
    return p;
}

void Insert_First_RNR(List &L, adr p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        p->next = L.first;
        L.first = p;
    }
}

void Insert_Last_RNR(List &L, adr p) {
    if (L.first == nullptr) {
        L.first = p;
    } else {
        adr q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = p;
    }
}

void Insert_After_RNR(List &L, adr prec, adr p) {
    if (prec != nullptr) {
        p->next = prec->next;
        prec->next = p;
    }
}

void Delete_First_RNR(List &L, adr &p) {
    if (L.first != nullptr) {
        p = L.first;
        L.first = L.first->next;
        p->next = nullptr;
    }
}

void Delete_Last_RNR(List &L, adr &p) {
    if (L.first != nullptr) {
        adr q = L.first;
        if (q->next == nullptr) {
            p = q;
            L.first = nullptr;
        } else {
            while (q->next->next != nullptr) {
                q = q->next;
            }
            p = q->next;
            q->next = nullptr;
        }
    }
}

void Delete_After_RNR(List &L, adr prec, adr &p) {
    if (prec != nullptr && prec->next != nullptr) {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void Show_RNR(List L) {
    if (L.first == nullptr) {
        cout << "List kosong" << endl;
    } else {
        adr p = L.first;
        while (p != nullptr) {
            cout << "Jadwal Penerbangan: " << p->info.jadwal << endl;
            cout << "Pembayaran atas nama: " << p->info.pemesan << endl;
            cout << "Kode penerbangan: " << p->info.kodePenerbangan << endl;
            p = p->next;
        }
    }
}

void SortByHarga_RNR(List &L) {
    if (L.first == nullptr) {
        cout << "List kosong" << endl;
    } else {
        adr i, j, min;
        infotype temp;
        for (i = L.first; i->next != nullptr; i = i->next) {
            min = i;
            for (j = i->next; j != nullptr; j = j->next) {
                if (j->info.kodePenerbangan < min->info.kodePenerbangan) {
                    min = j;
                }
            }
            if (min != i) {
                temp = i->info;
                i->info = min->info;
                min->info = temp;
            }
        }
    }
}

adr SearchByPosisi_RNR(List L, int posisi) {
    adr p = L.first;
    int count = 1;
    while (p != nullptr && count < posisi) {
        p = p->next;
        count++;
    }
    if (count == posisi) {
        return p;
    } else {
        return nullptr;
    }
}
