//---------------------------------------------------------------------------

#pragma hdrstop

#include <vector>
#include <string>
#include <iostream.h>
#include <fstream.h>
using namespace std;

#include "GESTION_ACCESS_.h"

GESTION_ACCESS::GESTION_ACCESS()
{

}

void GESTION_ACCESS::lire_demande()
{
	for(int i=0;i<8;i++)
	{
		proprietaire.push_back("sabrina");
		horodatage.push_back("12/12/2020");
		immatriculation.push_back("170-ea-52");
	}

}

void GESTION_ACCESS::changer_etat()
{

}

bool GESTION_ACCESS::envoi_message()
{
    return true;
}

bool GESTION_ACCESS::modifier_date_expiration()
{
    return true;
}
vector<string> GESTION_ACCESS::getproprietaire()
{
  return proprietaire;
}
vector<string> GESTION_ACCESS::gethorodatage()
{
  return horodatage;
}
vector<string> GESTION_ACCESS::getimmatriculation()
{
  return immatriculation;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
