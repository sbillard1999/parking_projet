//---------------------------------------------------------------------------

#pragma hdrstop

#include "pilotage.h"
//---------------------------------------------------------------------------
string pilotage::ouverture()
{
	this->etat="ouvert";
	return etat;
}
string pilotage::fermeture()
{
	this->etat="ferm�";
	return etat;
}
pilotage::pilotage()
{

}

#pragma package(smart_init)
