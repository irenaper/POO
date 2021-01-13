//#pragma once
#include <iostream>
#include <fstream>

using namespace std;


class Bilet
{
private:
	char* nume;
	float pret;
	int nrCateg;
	int* categorii;

	const int idB;
	static int nrBilete;
public:
	Bilet() : idB(1)
	{
		nume = nullptr;
		pret = 0;
		categorii = nullptr;
		nrCateg = 0;
	}

	Bilet(const char* nume, float pret, int* categorii, int nrCateg) :idB(++nrBilete)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->pret = pret;
		this->nrCateg = nrCateg;
		if (categorii != nullptr && nrCateg > 0)
		{
			this->categorii = new int[nrCateg];
			for (int i = 0; i < nrCateg; i++)
			{
				this->categorii[i] = categorii[i];
			}
		}
		else
		{
			this->categorii = nullptr;
			this->nrCateg = 0;
		}
	}

	Bilet(const Bilet& b) : idB(++nrBilete)
	{
		if (b.nume != nullptr)
		{
			this->nume = new char[strlen(b.nume) + 1];
			strcpy_s(this->nume, strlen(b.nume) + 1, b.nume);
		}
		else
		{
			this->nume = nullptr;
		}

		this->pret = b.pret;
		this->nrCateg = b.nrCateg;
		if (b.categorii != nullptr && b.nrCateg > 0)
		{
			this->categorii = new int[b.nrCateg];
			for (int i = 0; i < b.nrCateg; i++)
			{
				this->categorii[i] = b.categorii[i];
			}
		}
		else
		{
			this->categorii = nullptr;
			this->nrCateg = 0;
		}

	}

	~Bilet()
	{
		if (nume != nullptr)
		{
			delete[] nume;
		}
		if (categorii != nullptr)
		{
			delete[] categorii;
		}
	}

	Bilet& operator=(const Bilet& b)
	{
		if (nume != nullptr)
		{
			delete[] nume;
		}
		if (categorii != nullptr)
		{
			delete[] categorii;
		}
		if (b.nume != nullptr)
		{
			this->nume = new char[strlen(b.nume) + 1];
			strcpy_s(this->nume, strlen(b.nume) + 1, b.nume);
		}
		else
		{
			this->nume = nullptr;
		}
		this->pret = b.pret;
		if (b.categorii != nullptr && b.nrCateg != 0)
		{
			this->nrCateg = b.nrCateg;
			this->categorii = new int[b.nrCateg];
			for (int i = 0; i < b.nrCateg; i++)
			{
				this->categorii[i] = b.categorii[i];
			}
		}
		else
		{
			this->categorii = nullptr;
			this->nrCateg = 0;
		}
		return *this;
	}

	const char* getNume() {
		return nume;
	}

	float getPret() {
		return pret;
	}

	int getNrCat()
	{
		return nrCateg;
	}

	float getMedie() {
		float s = 0;
		for (int i = 0; i < nrCateg; i++) {
			s += categorii[i];
		}
		if (nrCateg != 0)
			return s / nrCateg;
		else
			return 0;
	}

	int* getCategorii()
	{
		if (categorii != nullptr)
		{
			int* copie = new int[nrCateg];
			for (int i = 0; i < nrCateg; i++)
			{
				copie[i] = categorii[i];

			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getCategorie(int index)
	{
		if (index >= 0 && index < nrCateg && categorii != nullptr)
		{
			return categorii[index];
		}
	}

	void setNume(const char* nume) {
		if (strlen(nume) >= 3) {
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else
			throw "Numele este prea scurt";
	}

	void setPret(float valoare) {
		this->pret = valoare;
	}

	void setNrCateg(int valoare) {
		if (valoare > 0) {
			this->nrCateg = nrCateg;
		}
	}

	void setCategorii(int* categorii, int nrCateg)
	{
		if (categorii != nullptr && nrCateg != 0)
		{
			this->nrCateg = nrCateg;
			if (this->categorii != nullptr)
			{
				delete[] this->categorii;

			}
			this->categorii = new int[nrCateg];
			for (int i = 0; i < nrCateg; i++)
			{
				this->categorii[i] = categorii[i];
			}
		}
	}

	Bilet operator+(float valoare)
	{
		Bilet copie = *this;
		copie.pret += valoare;
		return copie;
	}

	Bilet operator*(float valoare)
	{
		Bilet copie = *this;
		copie.pret *= valoare;
		return copie;
	}

	/*void operator*=(int repetitii) {
		*this = repetitii * (*this);
	}*/

	Bilet operator++()
	{
		this->pret++;
		return *this;
	}

	Bilet operator++(int i)
	{
		Bilet copie = *this;
		this->pret++;
		return copie;
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < nrCateg)
		{
			return categorii[index];
		}
		throw exception("index invalid");
	}

	explicit operator int()
	{
		return pret;
	}

	//int operator()()
	//{
	//	if (nume != nullptr)
	//	{
	//		return strlen(nume);
	//	}
	//	else
	//	{
	//		return 0;
	//	}
	//}

	//sterg categorii din vector
	void operator-=(int nrCategSters) {
		if (nrCategSters <= this->nrCateg) {
			int* listaNoua = new int[this->nrCateg - nrCategSters];
			for (int i = 0; i < this->nrCateg - nrCategSters; i++)
				listaNoua[i] = this->categorii[i];
			if (this->categorii != nullptr)
				delete[] this->categorii;
			this->categorii = listaNoua;
			this->nrCateg -= nrCategSters;
		}
		else
			throw new exception();
	}

	//compar 2 bilete
	void operator==(Bilet b) {
		if (strcmp(this->nume, b.nume) == 1 && pret == b.pret
			&& nrCateg == b.nrCateg && categorii == b.categorii)
			/*
			if (strcmp(this->nume, b.nume) == 1 && pret == b.pret && nrCateg == b.nrCateg &&
			for (int i = 0; i < b.nrCateg; i++) {
					categorii[i] == b.categorii[i] ;
			})*/

			cout << endl << "Bilete identice";
		else
			cout << endl << "Bilete diferite";

	}

	bool operator!()
	{
		return pret > 20;
	}

	static int getNrBilete()
	{
		return Bilet::nrBilete;
	}
	static void setNrBilete(int nrBilete)
	{
		Bilet::nrBilete = nrBilete;
	}


	static float medieBilete(Bilet* bilete, int nrBilete)
	{
		float suma = 0;
		int nr = 0;
		if (bilete != nullptr && nrBilete > 0)
		{
			for (int i = 0; i < nrBilete; i++)
			{
				if (bilete[i].categorii != nullptr)
				{
					for (int j = 0; j < bilete[i].nrCateg; j++)
					{
						suma += bilete[i].categorii[j];
						nr++;
					}
				}
			}
			if (nr > 0)
			{
				return suma / nr;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}

	//friend ostream& operator<<(ostream& out, Bilet b);
	//friend istream& operator>>(istream& in, Bilet& b);

	friend ostream& operator<<(ostream& out, Bilet b)
	{
		out << "Id bilet: " << b.idB << endl;
		out << "Nume persoana: " << b.nume << endl;
		out << "Pret bilet: " << b.pret << endl;
		out << "Nr. categorii pret: " << b.nrCateg << endl;
		out << "Categorii preturi: ";
		if (b.categorii != nullptr)
		{
			for (int i = 0; i < b.nrCateg; i++)
			{
				out << b.categorii[i] << " " << endl;
			}
		}
		out << "---end output Bilet---";
		return out;
	}

	friend istream& operator>>(istream& in, Bilet& b)
	{
		char buffer[100];
		cout << "Nume = ";
		in >> ws;
		in.getline(buffer, 99);
		if (b.nume != nullptr)
		{
			delete[] b.nume;
		}
		b.nume = new char[strlen(buffer) + 1];
		strcpy_s(b.nume, strlen(buffer) + 1, buffer);

		cout << "Pret = ";
		in >> b.pret;

		cout << "Nr. categorii = ";
		in >> b.nrCateg;
		if (b.categorii != nullptr)
		{
			delete[] b.categorii;
		}
		if (b.nrCateg > 0)
		{
			b.categorii = new int[b.nrCateg];
			for (int i = 0; i < b.nrCateg; i++)
			{
				cout << "Categorii[" << i << "] = ";
				in >> b.categorii[i];
			}
		}
		else
		{
			b.nrCateg = 0;
			b.categorii = nullptr;
		}
		cout << "---end intput Bilet---" << endl;

		return in;
	}

	friend ofstream& operator<<(ofstream& fout, Bilet b) {
		fout << b.nume << endl;
		fout << b.pret << endl;
		fout << b.nrCateg << endl;
		for (int i = 0; i < b.nrCateg; i++) {
			fout << b.categorii[i] << endl;
		}
		return fout;
	}

};

