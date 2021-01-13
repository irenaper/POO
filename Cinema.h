//#pragma once
#include "Film.h"

using namespace std;

class Cinema
{
	char* denumire;
	int nrProiectii;
	int* proiectii;
	int nrFilme;
	Film* filme;

	const int idC;
	static string oras;
public:
	Cinema() :idC(1) {
		denumire = nullptr;
		nrProiectii = 1;
		proiectii = nullptr;
		nrFilme = 1;
		filme = nullptr;
	}

	Cinema(const char* denumire, int nrProiectii, int* proiectii, int nrFilme, Film* filme) :idC() {
		if (denumire != nullptr) {
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		}
		this->nrProiectii = nrProiectii;
		this->proiectii = new int[nrProiectii];
		for (int i = 0; i < nrProiectii; i++)
		{
			this->proiectii[i] = proiectii[i];
		}
		this->nrFilme = nrFilme;
		this->filme = new Film[nrFilme];
		for (int i = 0; i < nrFilme; i++)
		{
			this->filme[i] = filme[i];
		}
	}


	/*Cinema(const char* denumire, int nrProiectii, int* proiectii) :idC() {
		if (denumire != nullptr) {
			this->denumire = new char[strlen(denumire) + 1];
			strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		}
		this->nrProiectii = nrProiectii;
		this->proiectii = new int[nrProiectii];
		for (int i = 0; i < nrProiectii; i++)
		{
			this->proiectii[i] = proiectii[i];
		}
		this->nrFilme = 0;
		this->filme = new Film[nrFilme];
		for (int i = 0; i < nrFilme; i++)
		{
			this->filme[i] = filme[i];
		}
	}*/

	Cinema(const Cinema& c) :idC() {
		if (c.denumire != nullptr) {
			this->denumire = new char[strlen(c.denumire) + 1];
			strcpy_s(this->denumire, strlen(c.denumire) + 1, c.denumire);
		}
		else {
			this->denumire = nullptr;
		}
		if (c.nrProiectii > 0 && c.proiectii != nullptr) {
			this->nrProiectii = c.nrProiectii;
			this->proiectii = new int[c.nrProiectii];
			for (int i = 0; i < c.nrProiectii; i++) {
				this->proiectii[i] = c.proiectii[i];
			}
		}
		else {
			this->nrProiectii = 0;
			this->proiectii = nullptr;
		}
		if (c.nrFilme > 0 && c.filme != nullptr) {
			this->nrFilme = c.nrFilme;
			filme = new Film[c.nrFilme];
			for (int i = 0; i < c.nrFilme; i++) {
				this->filme[i] = c.filme[i];
			}
		}
		else {
			this->nrFilme = 0;
			this->filme = nullptr;
		}
	}

	~Cinema() {
		if (this->denumire != nullptr) {
			delete[]this->denumire;
		}
		if (this->proiectii != nullptr) {
			delete[]this->proiectii;
		}

		if (this->filme != nullptr) {
			delete[]this->filme;
		}
	}

	Cinema operator=(const Cinema& c) {
		if (this->denumire != nullptr) {
			delete[]this->denumire;
		}
		if (this->proiectii != nullptr) {
			delete[]this->proiectii;
		}
		if (this->filme != nullptr) {
			delete[]this->filme;
		}
		if (c.denumire != nullptr) {
			this->denumire = new char[strlen(c.denumire) + 1];
			strcpy_s(this->denumire, strlen(c.denumire) + 1, c.denumire);
		}
		else {
			this->denumire = nullptr;
		}
		if (c.nrProiectii > 0 && c.proiectii != nullptr) {
			this->nrProiectii = c.nrProiectii;
			this->proiectii = new int[c.nrProiectii];
			for (int i = 0; i < c.nrProiectii; i++) {
				this->proiectii[i] = c.proiectii[i];
			}
		}
		else {
			this->nrProiectii = 0;
			this->proiectii = nullptr;
		}
		if (c.nrFilme > 0 && c.filme != nullptr) {
			this->nrFilme = c.nrFilme;
			for (int i = 0; i < c.nrFilme; i++) {
				filme = new Film[c.nrFilme];
				for (int i = 0; i < c.nrFilme; i++) {
					this->filme[i] = c.filme[i];
				}
			}
		}
		else {
			this->nrFilme = 0;
			this->filme = nullptr;
		}
		return *this;
	}

	int& operator[](int index) {
		if (index < this->nrProiectii && index >= 0) {
			return proiectii[index];
		}
		throw exception("index invalid");
	}

	Cinema operator+(int valoare) {
		if (valoare > 0) {
			Cinema copie = *this;
			copie.nrProiectii += valoare;
			return copie;
		}
		else {
			throw 1;
		}
	}

	bool operator>(Cinema c) {
		return this->nrProiectii > c.nrProiectii;
	}

	bool operator!() {
		return nrProiectii > 1000;
	}

	explicit operator float() {
		return getMedieRev();
	}

	float getMedieRev() {
		if (this->proiectii != nullptr) {
			int suma = 0;
			//int medie = 0;
			for (int i = 0; i < this->nrProiectii; i++) {
				suma += this->proiectii[i];
			}
			return (float)suma / this->nrProiectii;
		}
		else
			return 0;
	}

	Cinema operator+=(Cinema c) {

	}
	Cinema operator++() {
		this->nrProiectii++;
		return *this;
	}

	Cinema operator++(int) {
		Cinema copie = *this;
		this->nrProiectii++;
		return copie;
	}

	void operator==(Cinema c) {
		if (this->denumire == c.denumire)
			cout << endl << "Sunt egale";
		else
			cout << endl << "Sunt diferite";
	}

	/*bool operator==(Cinema c) {
		if (this->denumire.compare(c.denumire) == 1)
			return true;
		else
			return false;
	}	*/

	//friend ostream& operator<<(ostream& out, Cinema c);
	//friend istream& operator>> (istream& in, Cinema& c);

	friend ostream& operator<<(ostream& out, Cinema c) {
		out << endl;
		out << "Denumire cinema: " << c.denumire << endl;
		out << "Nr proiectii: " << c.nrProiectii;
		for (int i = 0; i < c.nrProiectii; i++) {
			out << c.proiectii[i] << endl;
		}
		out << "Nr filme:" << c.nrFilme << endl;
		//	out << "Bilete: " << endl;
		for (int i = 0; i < c.nrFilme; i++) {
			out << "Film " << i + 1 << " " << c.filme[i] << endl;
		}
		out << "---end output Cinema---";
		return out;
	}

	friend ofstream& operator<<(ofstream& fout, Cinema c) {
		fout << c.denumire << endl;
		fout << c.nrProiectii << endl;
		for (int i = 0; i < c.nrProiectii; i++) {
			fout << c.proiectii[i] << endl;
		}
		fout << c.nrFilme << endl;
		for (int i = 0; i < c.nrFilme; i++) {
			fout << c.filme[i] << endl;
		}
		return fout;
	}

	friend istream& operator>> (istream& in, Cinema& c) {
		cout << "Nume cinema = ";
		in >> ws;
		char buffer[100];
		in.getline(buffer, 99);
		if (c.denumire != nullptr) {
			delete[] c.denumire;
		}
		c.denumire = new char[strlen(buffer) + 1];
		strcpy_s(c.denumire, strlen(buffer) + 1, buffer);

		cout << "Nr. proiectii = ";
		in >> c.nrProiectii;
		if (c.proiectii != nullptr) {
			delete[]c.proiectii;
		}
		if (c.nrProiectii > 0) {
			c.proiectii = new int[c.nrProiectii];
			for (int i = 0; i < c.nrProiectii; i++) {
				cout << "Proiectie " << i + 1 << " = ";
				in >> c.proiectii[i];
			}
		}
		else {
			c.nrProiectii = 0;
			c.proiectii = nullptr;
		}

		cout << "Nr. filme = ";
		in >> c.nrFilme;

		if (c.filme != nullptr) {
			delete[]c.filme;
		}
		if (c.nrFilme > 0) {
			c.filme = new Film[c.nrFilme];
			for (int i = 0; i < c.nrFilme; i++) {
				cout << "Film " << i + 1 << endl;
				in >> c.filme[i];
			}
		}
		else {
			c.nrFilme = 0;
			c.filme = nullptr;
		}
		cout << "---end input Cinema---" << endl;

		return in;
	}

	friend ifstream& operator>>(ifstream& fin, Cinema& c) {
		if (c.denumire != nullptr) {
			delete[] c.denumire;
		}
		char buffer[100];
		fin >> buffer;
		c.denumire = new char[strlen(buffer) + 1];
		strcpy_s(c.denumire, strlen(buffer) + 1, buffer);
		fin >> c.nrProiectii;
		if (c.proiectii != nullptr) {
			delete[] c.proiectii;
		}
		c.proiectii = new int[c.nrProiectii];
		for (int i = 0; i < c.nrProiectii; i++) {
			fin >> c.proiectii[i];
		}
		fin >> c.nrFilme;
		if (c.filme != nullptr) {
			delete[] c.filme;
		}
		c.filme = new Film[c.nrFilme];
		for (int i = 0; i < c.nrFilme; i++) {
			Film b;
			fin >> b;
			//in >> c.filme[i];
		}
		return fin;
	}

};

