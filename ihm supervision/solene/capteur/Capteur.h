/******************************************************************************/
/*				   Classe réalisée par Piat Solène							  */
/*						 Classe Capteur										  */
/*																			  */
/******************************************************************************/
//---------------------------------------------------------------------------

#ifndef CapteurH
#define CapteurH

#include <Arduino.h>

//---------------------------------------------------------------------------
#endif
class Capteur{

	private:
        int CapteurPin;
        int LedPresence;
        int LedAbsence;
	    bool EtatCapteur;

	public:
        Capteur(int CapteurPin, int LedPresence, int LedAbsence);
        void objet();

};
