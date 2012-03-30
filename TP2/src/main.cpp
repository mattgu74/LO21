
#include <iostream>
#include "banque.h"

using namespace std;
using namespace BANQUE;

int main(int argc, char **argv)
{

	// Une Banque
	Banque BNP; BNP.Initialiser("BNP");

	// Ses différents types de comptes
	BNP.CreerUnTypeDeCompte("CHEQUE",-500,9999999,0);
	BNP.CreerUnTypeDeCompte("EPARGNE",15,9999999,1);
	BNP.CreerUnTypeDeCompte("LIVRET A",15,15300,1.25);
	BNP.CreerUnTypeDeCompte("CEL",300,15300,0.75);
	BNP.CreerUnTypeDeCompte("CODEVI",50,6000,1.25);

	// Ses clients
	BNP.AjouterUnClient("Clement","Fouque",30,6,1987);
	BNP.AjouterUnClient("Amjad","Abou-Assali",19,12,1986);
	BNP.AjouterUnClient("Sofiane","Khalfallah",31,5,1986);
	BNP.AjouterUnClient("Cuong","Duc Dang",18,11,1990);
	BNP.AjouterUnClient("Sergio","Rodriguez",24,8,1987);

	// Ses comptes
	BNP.CreerUnCompte("CODEVI","Clement","Fouque",400);
	BNP.CreerUnCompte("CHEQUE","Clement","Fouque",15);
	BNP.CreerUnCompte("LIVRET A","Clement","Fouque",2000);
	BNP.CreerUnCompte("CHEQUE","Amjad","Abou-Assali",3000);
	BNP.CreerUnCompte("CEL","Amjad","Abou-Assali",1000);
	BNP.CreerUnCompte("EPARGNE","Amjad","Abou-Assali",200);
	BNP.CreerUnCompte("CHEQUE","Sofiane","Khalfallah",500);
	BNP.CreerUnCompte("LIVRET A","Sofiane","Khalfallah",800);
	BNP.CreerUnCompte("CODEVI","Sofiane","Khalfallah",6000);
	BNP.CreerUnCompte("CHEQUE","Cuong","Duc Dang",15000);
	BNP.CreerUnCompte("CODEVI","Cuong","Duc Dang",150);
	BNP.CreerUnCompte("EPARGNE","Cuong","Duc Dang",1500);
	BNP.CreerUnCompte("CHEQUE","Sergio","Rodriguez",4000);
	BNP.CreerUnCompte("CEL","Sergio","Rodriguez",4000);
	BNP.CreerUnCompte("CHEQUE","Sergio","Rodriguez",6000);

	// Quelques opérations
	BNP.GetCompte("CHEQUE","Clement","Fouque").Deposer(3000);
	BNP.GetCompte("CHEQUE","Clement","Fouque").Retirer(100);
	BNP.GetCompte("CHEQUE","Clement","Fouque").Retirer(40);
	BNP.GetCompte("CHEQUE","Clement","Fouque").Retirer(50);
	BNP.GetCompte("CHEQUE","Clement","Fouque").Retirer(100);
	BNP.GetCompte("CHEQUE","Clement","Fouque").Retirer(20);
	BNP.GetCompte("CHEQUE","Clement","Fouque").Retirer(1500);
	BNP.GetCompte("CHEQUE","Clement","Fouque").Retirer(140);
	BNP.GetCompte("CHEQUE","Clement","Fouque").Retirer(200);
	BNP.GetCompte("CHEQUE","Clement","Fouque").Retirer(200);
	BNP.GetCompte("CHEQUE","Clement","Fouque").Retirer(400);
	BNP.GetCompte("CHEQUE","Clement","Fouque").
	TransfererVers(200,BNP.GetCompte("CODEVI","Clement","Fouque"));

	// Affichage
	BNP.Afficher();

	return 0;
}

