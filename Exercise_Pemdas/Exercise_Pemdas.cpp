#include <iostream>
#include <vector>
using namespace std;

#include "Buku.h"

class penerbit;
class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;
	vector<Buku*> daftar_buku;

	pengarang(string pNama) :nama(pNama) {
		cout << "pengarang \"" << nama << "\" ada\n";
	}
	~pengarang() {
		cout << "pengarang\"" << nama << "\" tidak ada\n";
	}

	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
	void tambahbuku(Buku*);
	void cetakbuku();
};

class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	penerbit(string pNama) :nama(pNama) {
		cout << "penerbit \"" << nama << "\"ada\n";
	}
	~penerbit() {
		cout << "penerbit \"" << nama << "\" tidak ada\n";
	}

	void tambahpengarang(pengarang*);
	void cetakpengarang();
};

void pengarang::tambahpenerbit(penerbit* ppenerbit) {
	daftar_penerbit.push_back(ppenerbit);
}
void pengarang::cetakpenerbit() {
	cout << "Daftar penerbit yang diikuti pengarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void penerbit::tambahpengarang(pengarang* ppengarang) {
	daftar_pengarang.push_back(ppengarang);
	ppengarang->tambahpenerbit(this);
}
void penerbit::cetakpengarang() {
	cout << "Daftar pengarang pada penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void pengarang::tambahbuku(Buku* pBuku) {
	daftar_buku.push_back(pBuku);
}
void pengarang::cetakbuku() {
	cout << "Daftar buku yang dikarang \"" << this->nama << "\": " << endl;
	for (auto& buku : daftar_buku) {
		cout << buku->judul << endl;
	}
	cout << endl;
}


int main() {
	penerbit* varpenerbit1 = new penerbit("Gama Press");
	penerbit* varpenerbit2 = new penerbit("Intan Pariwara");
	pengarang* varpengarang1 = new pengarang("Giga");
	pengarang* varpengarang2 = new pengarang("Joko");
	pengarang* varpengarang3 = new pengarang("Lia");
	pengarang* varpengarang4 = new pengarang("Asroni");

	/*untuk membuat asosiasi hubungan pengarang dengan penerbit*/
	varpenerbit1->tambahpengarang(varpengarang2);
	varpenerbit1->tambahpengarang(varpengarang3);
	varpenerbit1->tambahpengarang(varpengarang1);
	varpenerbit2->tambahpengarang(varpengarang4);
	varpenerbit2->tambahpengarang(varpengarang1);

	/*Membuat hubungan agregasi buku dengan pengarang*/
	varpengarang1->tambahbuku(new Buku("Matematika"));
	varpengarang1->tambahbuku(new Buku("Multimedia 1"));
	varpengarang2->tambahbuku(new Buku("Fisika"));
	varpengarang2->tambahbuku(new Buku("Algoritma"));
	varpengarang3->tambahbuku(new Buku("Basisdata"));
	varpengarang4->tambahbuku(new Buku("Dasar Pemrograman"));

	/*menampilkan pengarang*/
	varpenerbit1->cetakpengarang();
	varpenerbit2->cetakpengarang();

	/*menampilkan penerbit*/
	varpengarang1->cetakpenerbit();

	/*menampilkan buku*/
	varpengarang2->cetakbuku();
	varpengarang3->cetakbuku();
	varpengarang4->cetakbuku();
	varpengarang1->cetakbuku();

	delete varpengarang1;
	delete varpengarang2;
	delete varpenerbit1;
	delete varpenerbit2;

	return 0;
}