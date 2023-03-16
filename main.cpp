#include <iostream>
#include <cstdlib>

using namespace std;

enum class Resultat
{
	Victoire,
	Defaite,
	Egalite
};

string ObtenirEntree()
{
	string choixUtilisateur{ " " };
	bool choixValide = false;
	while (!choixValide)
	{
		cout << "Choisir: (r)oche, (p)apier, (c)iseaux ?" << endl;
		cin >> choixUtilisateur;

		if (choixUtilisateur.length() > 1 || choixUtilisateur.empty())
		{
			cout << "Choix invalide, veuillez réessayer" << endl;
		}
		else
		{
			char choix = choixUtilisateur[0];
			if (choix != 'r' && choix != 'p' && choix != 'c' && choix != 'R' && choix != 'P' && choix != 'C')
			{
				cout << "Choix invalide, veuillez réessayer" << endl;
			}
			else
			{
				choixValide = true;
			}
		}
	}
		switch (choixUtilisateur[0])
		{
		case 'c':
		case 'C':
			return "Ciseaux";
		case 'r':
		case 'R':
			return "Roche";
		case 'p':
		case 'P':
			return "Papier";
		}
}

string ObtenirChoixOrdinateur()
{
	srand((unsigned int)time(NULL));
	int resultat{ rand() % 3 };

	switch (resultat)
	{
	case 0:
		return "Roche";
	case 1:
		return "Papier";
	case 2:
		return "Ciseaux";
	}
}

Resultat DeterminerResultat(string choixUtilisateur, string choixOrdinateur)
{
	if (choixOrdinateur == choixUtilisateur)
	{
		return Resultat::Egalite;
	}
	else if ((choixUtilisateur == "Papier" && choixOrdinateur == "Roche") || 
		(choixUtilisateur == "Roche" && choixOrdinateur == "Ciseaux")
		|| (choixUtilisateur == "Ciseaux" && choixOrdinateur == "Papier"))
	{
		return Resultat::Victoire;
	}
	else
	{
		return Resultat::Defaite;
	}
}

void AfficherResultat(string choixUtilisateur, string choixOrdinateur, Resultat resultat)
{
	cout << "Vous avez choisi: " << choixUtilisateur << endl;
	cout << "L'ordinateur a choisi: " << choixOrdinateur << endl;

	switch (resultat)
	{
	case Resultat::Victoire:
		cout << "Vous avez gagné !" << endl;
		break;
	case Resultat::Defaite:
		cout << "Vous avez perdu !" << endl;
		break;
	case Resultat::Egalite:
		cout << "Égalité !" << endl;
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "");

	cout << "--- Roche, Papier, Ciseaux ---" << endl;
	string choixUtilisateur { ObtenirEntree() };
	string choixOrdinateur{ ObtenirChoixOrdinateur() };
	Resultat resultat = DeterminerResultat(choixUtilisateur, choixOrdinateur);
	AfficherResultat(choixUtilisateur, choixOrdinateur, resultat);
	cout << "Voulez-vous rejouer ? (y/n)" << endl;

	string rejouer{ " " };
	cin >> rejouer;

	if (rejouer == "y" || rejouer == "Y")
	{
		main();
	}
	else
	{
		exit(0);
	}

	return 0;
}