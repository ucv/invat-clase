#include <iostream>
#include <string>

using namespace std;



class piese_de_joc {
	//private:
	char piesa_de_joc;

public:
	piese_de_joc(char piesa) {
		this->piesa_de_joc = piesa;
		//initializare
	}

	~piese_de_joc() {

		//dezinitializare
	}
};


struct POZITIE {
	int coloana;
	int linie;
	string coutPozitie() {
		string ret_value = "[";
		ret_value.append(to_string(this->coloana));
		ret_value.append("],[");
		ret_value.append(to_string(this->linie));
		ret_value.append("]");
		return ret_value.c_str();
	};
}pozitie;

class tabla {
//private:
char piese_de_joc[8][8];



public:
	POZITIE getPozitie() {
		string pozitie_initiala;
		while (true) {
			std::getline(std::cin, pozitie_initiala);

			if (pozitie_initiala.length() != 2) {
				cout << "Valoare incorecta , reintroduceti valoarea\n";
			}
			//cout << "Numarul de caractere este:" << pozitie_initiala.length() << endl;
			//if (pozitie_initiala.length() != 2) {
			//cout << "Valoare incorecta , reintroduceti valoarea\n";

			if (isdigit(pozitie_initiala[0]) && isalpha(pozitie_initiala[1]) || isalpha(pozitie_initiala[0])
				&& isdigit(pozitie_initiala[1])) {


				if (isalpha(pozitie_initiala[0])) {
					pozitie.coloana = atoi(&pozitie_initiala[1]) - 1;
					pozitie.linie = int(pozitie_initiala[0]) - 97;
				}
				else {
					pozitie.coloana = atoi(&pozitie_initiala[0]) - 1;
					pozitie.linie = int(pozitie_initiala[1]) - 97;
				}



				if (pozitie.coloana >= 0 && pozitie.coloana < 8 && pozitie.linie >= 0 && pozitie.linie < 8) {
					return pozitie;
				}
				else {
					pozitie_initiala.erase();
					cout << "Valoare incorecta , reintroduceti valoarea\n";
				}
			}
			else if (isdigit(pozitie_initiala[0]) && isdigit(pozitie_initiala[1]) || isalpha(pozitie_initiala[0])
				&& isalpha(pozitie_initiala[1])) {
				cout << "Valoare incorecta , reintroduceti valoarea\n";
			}

		}

	}
	tabla() {
		//initializare

		for (int i = 0; i < 8; i++) {
			for (int ii = 0; ii < 8; ii++) {
				piese_de_joc[i][ii] = '-';
			}
		}


		piese_de_joc[4][0] = 'q';
		piese_de_joc[3][7] = 'Q';

		piese_de_joc[3][0] = 'r';
		piese_de_joc[4][7] = 'R';

		piese_de_joc[2][0] = 'n';
		piese_de_joc[5][0] = 'n';
		piese_de_joc[2][7] = 'N';
		piese_de_joc[5][7] = 'N';

		piese_de_joc[1][0] = 'c';
		piese_de_joc[6][0] = 'c';
		piese_de_joc[1][7] = 'C';
		piese_de_joc[6][7] = 'C';

		piese_de_joc[0][0] = 't';
		piese_de_joc[7][0] = 't';
		piese_de_joc[0][7] = 'T';
		piese_de_joc[7][7] = 'T';

		//pioni
		for (int i = 0; i < 8; i++) {
			piese_de_joc[i][1] = 'p';
			piese_de_joc[i][6] = 'P';
		}

		cout << "S-a initializat tabla de sah\n";
	}

	void afiseaza_tabla() {

		for (int ii = -1; ii < 8; ii++) {
			cout << char(ii + 97) << " ";

			for (int i = 0; i < 8; i++) {
				if (ii == -1) {
					cout << i + 1 << " ";
				}
				else {
					cout << piese_de_joc[i][ii] << " ";
				}


			}
			cout << endl;
		}
	}
	~tabla() {
		//delete piese_tabla;
		//dezinitializare
	}
};











int main() {

	tabla TablaDeSah;
	TablaDeSah.afiseaza_tabla();

	//bonus afiseaza numarul de coloana de la 1 -> 8
	//extra bonus afisaza numarul de linii de la a -> h
			// char de a = 97

	bool isRunning = true;
	while (isRunning) {
		//citeste de la tastatura x,y
		//citeste de la tastatura x,y
		//a2
		



		tabla tabla_de_sah;
		POZITIE valoare = tabla_de_sah.getPozitie();
		cout << valoare.coutPozitie() << endl;
		



	}

	system("pause");
	return 0;
}

	
