//---------------------------------------------------------------------------

#pragma hdrstop

#include "supervision.h"
#include <fstream>
#include <iostream>
//---------------------------------------------------------------------------

supervision::supervision()
{
	conversion=new StringUtils;
	conversion2=new StringUtils;
	string modee="";
	ifstream fichier("parametre.txt", ios::in);  // on ouvre en lecture

		if(fichier)  // si l'ouverture a fonctionné
		{
				  // déclaration d'une chaîne qui contiendra la ligne lue
				getline(fichier,modee);  // on met dans "contenu" la ligne

				fichier.close();
		}
		UnicodeString para="";
		para=modee.c_str();
		this->mode=para;
}
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
	int size=0;
	size=mode.Length();
	char*modechar=new char[size];
	//modechar="";
	for(int i = 0; i < size; i++)
        modechar[i] = 0;
	modechar=StringUtils::magicConvert(mode);//conversion2->magicConvert(mode);


	ofstream fichier("parametre.txt", ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier

		if(fichier)  // si l'ouverture a réussi
		{
			// instructions
			fichier << modechar << endl;
			fichier.close(); // on referme le fichier
		}

		string modestring="";
		modestring=modechar;
		this->mode=modestring.c_str();



}

UnicodeString supervision::getmode(){

	return this->mode;

}

bool supervision::compare_plaque(vector<string>plaquebase,string plaquelu)
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
