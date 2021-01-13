#include <string>
#include <iostream>
#include <fstream>
#include "Cinema.h"
#include "Spectacol.h"

int Bilet::nrBilete = 0;
int Film::nrFilme = 1;
string Cinema::oras = "Constanta";
float Spectacol::TVA = 19;


using namespace std;

int main() {
	/*Bilet b1, b2;
	cin >> b1;
	ofstream out1;
	out1.open("bilete.txt");
	out1 << b1;
	out1.close();

	ifstream in1;
	in1.open("bilete.txt");
	in1 >> b2;
	in1.close();
	cout << b2;*/

	Film f1,f2;
	cin >> f1;

	ofstream out2;
	out2.open("filme.txt");
	out2 << f1;
	out2.close();

	ifstream in2;
	in2.open("filme.txt");
	in2 >> f2;
	in2.close();
	cout << f2;


	//Cinema c1, c2, c3;
	////cin >> c1;
	//cout << c1;

	//ofstream out1;
	//out1.open("cinematografe.txt");
	//out1 << c1;
	//out1.close();

	///*ifstream in1;
	//in1.open("cinematograf.txt");
	//in1 >> c1;
	//in1.close();
	//cout << c1;*/


	//	/*Film f1, f2;
	//	Film vf[2] = { f1, f2 };
	//	Cinema c1("Cinema1",'a', vf, 2);*/
	//
	//	//ifstream out1;
	//	//out1.open("cinematografe")
	//
	//
	//
	//	/*Bilet b;
	//	cout << b;*/

	


	

}