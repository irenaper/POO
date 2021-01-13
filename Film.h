//#pragma once
#include "Bilet.h"

using namespace std;

class Film
{
	char* titlu;
	int nrReviews;
	int* reviews;
	int nrBilete;
	Bilet* bilete;

	const int idFilm;
	static int nrFilme;
public:
	Film() :idFilm(++nrFilme) {
		titlu = nullptr;
		nrReviews = 1;
		reviews = nullptr;
		nrBilete = 1;
		bilete = nullptr;
	}

	Film(const char* titlu, int nrReviews, int* reviews, int nrBilete, Bilet* bilete) :idFilm(++nrFilme) {
		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		this->nrReviews = nrReviews;
		this->reviews = new int[nrReviews];
		for (int i = 0; i < nrReviews; i++)
		{
			this->reviews[i] = reviews[i];
		}
		this->nrBilete = nrBilete;
		this->bilete = new Bilet[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->bilete[i] = bilete[i];
		}
	}


	/*Film(const char* titlu, int nrReviews, int* reviews) :idFilm(++nrFilme) {
		if (titlu != nullptr) {
			this->titlu = new char[strlen(titlu) + 1];
			strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		}
		this->nrReviews = nrReviews;
		this->reviews = new int[nrReviews];
		for (int i = 0; i < nrReviews; i++)
		{
			this->reviews[i] = reviews[i];
		}
		this->nrBilete = 0;
		this->bilete = new Bilet[nrBilete];
		for (int i = 0; i < nrBilete; i++)
		{
			this->bilete[i] = bilete[i];
		}
	}*/

	Film(const Film& f) :idFilm(++nrFilme) {
		if (f.titlu != nullptr) {
			this->titlu = new char[strlen(f.titlu) + 1];
			strcpy_s(this->titlu, strlen(f.titlu) + 1, f.titlu);
		}
		else {
			this->titlu = nullptr;
		}
		if (f.nrReviews > 0 && f.reviews != nullptr) {
			this->nrReviews = f.nrReviews;
			this->reviews = new int[f.nrReviews];
			for (int i = 0; i < f.nrReviews; i++) {
				this->reviews[i] = f.reviews[i];
			}
		}
		else {
			this->nrReviews = 0;
			this->reviews = nullptr;
		}

		if (f.nrBilete > 0 && f.bilete != nullptr) {
			this->nrBilete = f.nrBilete;
			for (int i = 0; i < f.nrBilete; i++) {
				bilete = new Bilet[f.nrBilete];
				for (int i = 0; i < f.nrBilete; i++) {
					this->bilete[i] = f.bilete[i];
				}
			}
		}
		else {
			this->nrBilete = 0;
			this->bilete = nullptr;
		}
	}

	~Film() {
		if (this->titlu != nullptr) {
			delete[]this->titlu;
		}
		if (this->reviews != nullptr) {
			delete[]this->reviews;
		}

		if (this->bilete != nullptr) {
			delete[]this->bilete;
		}

		nrBilete--;
	}

	Film operator=(const Film& f) {
		if (this->titlu != nullptr) {
			delete[]this->titlu;
		}
		if (this->reviews != nullptr) {
			delete[]this->reviews;
		}
		if (this->bilete != nullptr) {
			delete[]this->bilete;
		}
		if (f.titlu != nullptr) {
			this->titlu = new char[strlen(f.titlu) + 1];
			strcpy_s(this->titlu, strlen(f.titlu) + 1, f.titlu);
		}
		else {
			this->titlu = nullptr;
		}
		if (f.nrReviews > 0 && f.reviews != nullptr) {
			this->nrReviews = f.nrReviews;
			this->reviews = new int[f.nrReviews];
			for (int i = 0; i < f.nrReviews; i++) {
				this->reviews[i] = f.reviews[i];
			}
		}
		else {
			this->nrReviews = 0;
			this->reviews = nullptr;
		}
		if (f.nrBilete > 0 && f.bilete != nullptr) {
			this->nrBilete = f.nrBilete;
			for (int i = 0; i < f.nrBilete; i++) {
				bilete = new Bilet[f.nrBilete];
				for (int i = 0; i < f.nrBilete; i++) {
					this->bilete[i] = f.bilete[i];
				}
			}
		}
		else {
			this->nrBilete = 0;
			this->bilete = nullptr;
		}
		return *this;
	}

	int& operator[](int index) {
		if (index < this->nrReviews && index >= 0) {
			return reviews[index];
		}
		throw exception("index invalid");
	}

	Film operator+(int valoare) {
		if (valoare > 0) {
			Film copie = *this;
			copie.nrReviews += valoare;
			return copie;
		}
		else {
			throw 1;
		}
	}

	bool operator>(Film f) {
		return this->nrReviews > f.nrReviews;
	}

	bool operator!() {
		return nrReviews > 1000;
	}

	explicit operator float() {
		return getMedieRev();
	}

	float getMedieRev() {
		if (this->reviews != nullptr) {
			int suma = 0;
			//int medie = 0;
			for (int i = 0; i < this->nrReviews; i++) {
				suma += this->reviews[i];
			}
			return (float)suma / this->nrReviews;
		}
		else
			return 0;
	}

	Film operator+=(Film f) {

	}
	Film operator++() {
		this->nrReviews++;
		return *this;
	}

	Film operator++(int) {
		Film copie = *this;
		this->nrReviews++;
		return copie;
	}

	void operator==(Film f) {
		if (this->titlu == f.titlu)
			cout << endl << "Sunt egale";
		else
			cout << endl << "Sunt diferite";
	}

	/*bool operator==(Film f) {
		if (this->titlu.compare(f.titlu) == 1)
			return true;
		else
			return false;
	}	*/

	//friend ostream& operator<<(ostream& out, Film f);
	//friend istream& operator>> (istream& in, Film& f);

	friend ostream& operator<<(ostream& out, Film f) {
		out << endl;
		out << "Id film: " << f.idFilm << endl;
		out << "Titlu: " << f.titlu << endl;
		out << "Nr reviews: " << f.nrReviews;
		for (int i = 0; i < f.nrReviews; i++) {
			out << "Review" << i + 1 << " " << f.reviews[i] << endl;
		}
		out << "Nr bilete:" << f.nrBilete << endl;
		//	out << "Bilete: " << endl;
		for (int i = 0; i < f.nrBilete; i++) {
			out << "Bilet " << i + 1 << " " << f.bilete[i] << endl;
		}
		out << "---end output Film---";
		return out;
	}
	friend ofstream& operator<<(ofstream& fout, Film f) {
		fout << f.idFilm << endl;
		fout << f.titlu << endl;
		fout << f.nrReviews << endl;
		for (int i = 0; i < f.nrReviews; i++) {
			fout << f.reviews[i] << endl;
		}
		fout << f.nrBilete << endl;
		for (int i = 0; i < f.nrBilete; i++) {
			fout << f.bilete[i] << endl;
		}
		return fout;
	}


	friend istream& operator>> (istream& in, Film& f) {
		cout << "Titlu film = ";
		in >> ws;
		char buffer[100];
		in.getline(buffer, 99);
		if (f.titlu != nullptr) {
			delete[] f.titlu;
		}
		f.titlu = new char[strlen(buffer) + 1];
		strcpy_s(f.titlu, strlen(buffer) + 1, buffer);

		cout << "Nr. reviews = ";
		in >> f.nrReviews;
		if (f.reviews != nullptr) {
			delete[]f.reviews;
		}
		if (f.nrReviews > 0) {
			f.reviews = new int[f.nrReviews];
			for (int i = 0; i < f.nrReviews; i++) {
				cout << "Review " << i + 1 << " = ";
				in >> f.reviews[i];
			}
		}
		else {
			f.nrReviews = 0;
			f.reviews = nullptr;
		}
		cout << "Nr. bilete = ";
		in >> f.nrBilete;

		if (f.bilete != nullptr) {
			delete[]f.bilete;
		}
		if (f.nrBilete > 0) {
			f.bilete = new Bilet[f.nrBilete];
			for (int i = 0; i < f.nrBilete; i++) {
				cout << "Bilet " << i + 1 << endl;
				in >> f.bilete[i];
			}
		}
		else {
			f.nrBilete = 0;
			f.bilete = nullptr;
		}
		cout << "---end input Film---" << endl;

		return in;
	}

	friend ifstream& operator>>(ifstream& fin, Film& f) {
		if (f.titlu != nullptr) {
			delete[] f.titlu;
		}
		char buffer[100];
		fin >> buffer;
		f.titlu = new char[strlen(buffer) + 1];
		strcpy_s(f.titlu, strlen(buffer) + 1, buffer);
		fin >> f.nrReviews;
		if (f.reviews != nullptr) {
			delete[] f.reviews;
		}
		f.reviews = new int[f.nrReviews];
		for (int i = 0; i < f.nrReviews; i++) {
			fin >> f.reviews[i];
		}
		fin >> f.nrBilete;
		if (f.bilete != nullptr) {
			delete[] f.bilete;
		}
		f.bilete = new Bilet[f.nrBilete];
		for (int i = 0; i < f.nrBilete; i++) {
			Bilet b;
			fin >> b;
			//in >> f.bilete[i];
		}
		return fin;
	}

};


