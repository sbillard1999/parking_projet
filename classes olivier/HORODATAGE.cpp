//---------------------------------------------------------------------------

#pragma hdrstop
#include <vector>
#include <string>
#include <iostream.h>
#include <fstream.h>
using namespace std;
#include "HORODATAGE.h"


HORODATAGE::HORODATAGE()
{

}

void HORODATAGE::lecture_access()
{
	proprietaire.clear();
	horodatage.clear();
	immatriculation.clear();
	for(int i=0;i<3;i++)
	{
		proprietaire.push_back("sabrina");
		horodatage.push_back("12/12/2020");
		immatriculation.push_back("df-55-fd");

	}
	for(int i=0;i<3;i++)
	{
		proprietaire.push_back("solene");
		horodatage.push_back("12/10/2020");
		immatriculation.push_back("170-d-sasa");
	}
	for(int i=0;i<3;i++)
	{
		proprietaire.push_back("antoine");
		horodatage.push_back("12/12/2015");
		immatriculation.push_back("1f70-efda-5df2");

	}
}
void HORODATAGE::lecture_access_vehicule(UnicodeString plaque)
{
    proprietaire.clear();
	horodatage.clear();
	immatriculation.clear();

	//requette select avec plaque
    for(int i=0;i<3;i++)
	{
		proprietaire.push_back("antoine");
		horodatage.push_back("12/12/2015");
		immatriculation.push_back("1f70-efda-5df2");

	}



}
string HORODATAGE::lecture_access_proprietaire(string plaque)
{
	string proprietaire="sabrina";
	return proprietaire;
}

bool HORODATAGE::ecriture()
{
	return true;
}

bool HORODATAGE::modifier()
{
	return true;
}


vector<string>HORODATAGE::getproprietaire()
{
	return proprietaire;
}
vector<string>HORODATAGE::getimmatriculation()
{
	return immatriculation;
}
vector<string>HORODATAGE::gethorodatage()
{
	return horodatage;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
