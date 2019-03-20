/******************************************************************************/
/* 					Classe réalisée par Piat Solène						 	  */
/*						 	 Classe Camera				   			  		  */
/*																			  */
/******************************************************************************/
//---------------------------------------------------------------------------

#ifndef CameraH
#define CameraH
#include <windows.h>
#include <stdlib.h>
#include <string>
//---------------------------------------------------------------------------
#endif
class Camera
{
	private:
		HANDLE hComm;
		DCB serie;
		OVERLAPPED over;
		bool EtatCamera;
		//Tps_acquisition;


	public:
		Camera(wchar_t Port[4]);
		void Activer_acquisition(); //Lecture de la plaque
		bool etatCamera(); //Controle de l'etat de la camera

}