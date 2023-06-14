#ifndef Buku_H
#define Buku_H

class Buku {
public:
	string judul;

	Buku(string pJudul) : judul(pJudul) {
		cout << "Buku \"" << judul << "\" ada" << endl;
	}
	~Buku() {
		cout << "Buku \"" << judul << "\" tidak ada" << endl;
	}
};

#endif // !Buku_H
