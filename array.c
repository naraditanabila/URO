/* 	NIM/Nama 	: 18217034/Naradita Kunti Nabila
	Tanggal		: 13 September 2018
	Topik		: Tugas Pra Praktikum 1
	Deskripsi	: Implementasi dari file header array.h */
	
#include <stdio.h>
#include "array.h"


/* KAMUS */
TabInt T;

/* ALGORITMA */
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabInt *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	(*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	if (T.Neff==0) {
		return 0;
	}
	else {
		return GetLastIdx(T) - GetFirstIdx(T) + 1;
	}
}

int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return IdxMax - IdxMin + 1;
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
	/* KAMUS LOKAL */

	/* ALGORITMA */	
	return IdxMin; /*Karena penempatan elemen selalu rapat kiri */
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return IdxMin + T.Neff - 1;
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
	/* KAMUS LOKAL */
	int i;
	TabInt THsl;
	/* ALGORITMA */
	THsl.Neff = Tin.Neff;
	for (i=GetFirstIdx(Tin); i<=GetLastIdx(Tin); i++){
		THsl.TI[i] = Tin.TI[i];	
	}
	*Tout = THsl;
}

void SetEl (TabInt *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	(*T).TI[i]=v;
}

void SetNeff (TabInt *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	(*T).Neff=N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	if (i>=IdxMin && i<=IdxMax) {
		return true;
	}
	else false;
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	/* KAMUS LOKAL */
	int awal, akhir;
	/* ALGORITMA */
	awal=GetFirstIdx(T);
	akhir=GetLastIdx(T);
	if (i>=awal && i<=akhir){
		return true;
	}
	else return false;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	if (T.Neff==0){
		return true;
	} 
	else return false;
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	if (T.Neff==IdxMax-IdxMin+1){
		return true;
	}
	else return false;
}
