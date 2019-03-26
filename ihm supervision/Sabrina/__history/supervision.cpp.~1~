//---------------------------------------------------------------------------

#pragma hdrstop

#include "supervision.h"
#include <fstream>
#include <iostream>
//---------------------------------------------------------------------------

void supervision::export_(string horodatage,string proprietaire,string plaque)
{
  ofstream fichier("export.txt", ios::out | ios::app);  //déclaration du flux et ouverture du fichier

		if(fichier)  // si l'ouverture a réussi
		{
			// instructions
			fichier << proprietaire << plaque << horodatage << endl;
			fichier.close();  // on referme le fichier
		}
}

void supervision::enregistrement_parametre(UnicodeString mode)
{
	char*modee;
	int taille=mode.Length();
	modee=new char[taille];
	modee=conversion->magicConvert(mode);


	ofstream fichier("parametre.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

		if(fichier)  // si l'ouverture a réussi
		{
			// instructions
			fichier << "mode"<< " " << modee << endl;
			fichier.close(); // on referme le fichier
		}
		this->mode=mode;
		delete modee;
}

UnicodeString supervision::getmode(){

	return this->mode;
}
supervision::supervision()
{
  mode="automatique";
  conversion=new StringUtils;
}
bool supervision::compare_plaque(vector<UnicodeString>plaquebase,UnicodeString plaquelu)
{
	int valider=0;
	for(int i=0;i<plaquebase.size();i++)
	{
		if(plaquelu==plaquebase[i])
		{
		  valider++;
		}
	}
	if(valider>0)
	{
		return true;
	}
	else
	{
		return false;
    }


}
supervision::~supervision()
{

	delete conversion;
}
#pragma package(smart_init)
