//---------------------------------------------------------------------------

#pragma hdrstop

#include "pilotage.h"
//---------------------------------------------------------------------------
UnicodeString pilotage::ouverture()
{
	this->etat="ouvert";
	return etat;
}
UnicodeString pilotage::fermeture()
{
	this->etat="ferm�";
	return etat;
}
UnicodeString pilotage::getetat()
{
	return this->etat;
}
pilotage::pilotage()
{
  this->etat="ferm�";
}

#pragma package(smart_init)
