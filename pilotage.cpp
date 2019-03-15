//---------------------------------------------------------------------------

#pragma hdrstop

#include "pilotage.h"
//---------------------------------------------------------------------------

void pilotage::ouverture()
{
	this->etat="ouverture";

}
void pilotage::fermeture()
{
	this->etat="fermeture";
}
UnicodeString pilotage::getetat()
{
	return this->etat;
}


#pragma package(smart_init)
