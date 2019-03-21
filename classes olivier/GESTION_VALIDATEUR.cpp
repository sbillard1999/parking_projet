//---------------------------------------------------------------------------

#pragma hdrstop
#include <vector>
#include <string>
#include <iostream.h>
#include <fstream.h>
using namespace std;
#include "GESTION_VALIDATEUR.h"

GESTION_VALIDATEUR::GESTION_VALIDATEUR()
{

}

bool GESTION_VALIDATEUR::lecture()
{
    return true;
}

bool GESTION_VALIDATEUR::ecriture()
{
	return true;
}

bool GESTION_VALIDATEUR::modifier()
{
	return true;
}

bool GESTION_VALIDATEUR::authentification_validateur(string *login, string *password)
{
	return true;
}

bool GESTION_VALIDATEUR::ajouter_validateur()
{
	return true;
}

bool GESTION_VALIDATEUR::modifier_validateur()
{
	return true;
}

bool GESTION_VALIDATEUR::supprimer_validateur()
{
    return true;
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
