#include <iostream>
#include <algorithm> // std::sort
#include <vector> // std::vector
#include <string>
#include <fstream>
#include "fraction.hpp"

using namespace std;

int main() {

	Fraction liste;
	ifstream fichier("C:/Users/Administrateur/source/repos/TP 6-7 OOP/TP 6-7 OOP/Exercice2/fichier.txt"); // on ouvre le fichier en lecture

	string ligne;
	string num;
	string den;
	vector<Fraction> tab;

	if (fichier)
	{
		while (getline(fichier, ligne))
		{
			int id = ligne.find('/');
			num = ligne.substr(0, id); // ajoute les elements du départ jusqu'au '/'
			den = ligne.substr(id + 1); // ajoute les element du '/' jusqu'à la fin
			int numerateur = stoi(num); // convertit le string en int
			int denominateur = stoi(den); // convertit le string en int
			Fraction f(numerateur, denominateur); // crée une fraction f
			f.reduce();
			tab.push_back(f); // insère la fraction à la fin du tableau
		}
		fichier.close();  // on ferme le fichier
	}
	else
	{
		cerr << "Impossible d'ouvrir le fichier !" << endl;
		return 1;
	}
		
	sort(tab.begin(), tab.end());
	unique(tab.begin(), tab.end());
	remove_if(tab.begin(), tab.end(), [](const Fraction& f) {
		return ((f.getNum() < 0 && f.getDen() > 0) || (f.getNum() > 0 && f.getDen() < 0));
		});
	cout << endl;

	for (int i = 0; i < tab.size(); i++) {
		cout << tab[i] << endl;
	}

	return 0;
}