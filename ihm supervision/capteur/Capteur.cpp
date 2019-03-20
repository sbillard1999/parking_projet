/******************************************************************************/
/*				   Classe r�alis�e par Piat Sol�ne							  */
/*							Classe Capteur									  */
/*																			  */
/******************************************************************************/
//---------------------------------------------------------------------------

#pragma hdrstop

#include "Capteur.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Capteur::Capteur(int CapteurPin, int LedPresence, int LedAbsence)
{
    pinMode(CapteurPin, INPUT); //entr�e pour le capteur
    pinMode(LedPresence, OUTPUT); //sortie qui indique la pr�sence d'un objet
    pinMode(LedAbsence, OUTPUT); //sortie qui indique l'absence d'un objet
}
//------------------------------------------------------------------------------

void Capteur::objet()
{
     if(digitalRead(CapteurPin) == LOW) // si le capteur rep�re un obstacle
    {
        digitalWrite(LedPresence, HIGH); //allume la LED de pr�sence
		digitalWrite(LedAbsence, LOW); //�teint la LED d'absence
		EtatCapteur = true;
	}
	else
	{
		digitalWrite(LedPresence, LOW); //�teint la LED de pr�sence
		digitalWrite(LedAbsence, HIGH); //allume la LED d'absence
		EtatCapteur = false;
     }
}
//------------------------------------------------------------------------------


