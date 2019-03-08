//---------------------------------------------------------------------------

#pragma hdrstop

#include "supervision.h"
//---------------------------------------------------------------------------
bool supervision::compare_plaque(string plaque_lu,string plaque_bdd)
{

	int reponse_bdd=0;
	if(reponse_bdd==0)
	{
		  return false;
	}
	else
	{
		return true;
	}


}
void supervision::export_()
{

}

void supervision::mode_individuel()
{

}

void supervision::mode_ouvert()
{

}

void supervision::enregistrement_parametre()
{

}

void supervision::affichage_acces(string proprio,string plaque, string horodatage)
{
  proprio=this->proprietaire;
  plaque=this->plaque;
  horodatage=this->horodatage;
}
supervision::supervision()
{

}
#pragma package(smart_init)
