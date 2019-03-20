/******************************************************************************/
/*				   Classe r�alis�e par Piat Sol�ne							  */
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
