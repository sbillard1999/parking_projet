/******************************************************************************/
/* 			        Classe réalisée par Piat Solène					 		  */
/*							Classe Camera				   	                  */
/*																			  */
/******************************************************************************/
//---------------------------------------------------------------------------

#pragma hdrstop

#include "Camera.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Camera::Camera(wchar_t Port[4])
{
	hComm = CreateFile( Port,
					GENERIC_READ | GENERIC_WRITE,
					0,
					0,
					OPEN_EXISTING,
					FILE_FLAG_NO_BUFFERING,
					0);

		GetCommState(hComm,&serie);
		serie.BaudRate = 9600;
		serie.ByteSize = 8;
		serie.Parity = NOPARITY;
		serie.StopBits = ONESTOPBIT;
		SetCommState(hComm,&serie);
		EtatCamera = true;
}
//------------------------------------------------------------------------------

void Camera::Activer_acquisition(){

	while(true)
	{
		if(EtatCamera == true)
		{
			//return "Activation en cours";
		}
		else
		{
			//return "Impossible d'activer l'acquisition: caméra non connectée";
		}
	}
}
//------------------------------------------------------------------------------

bool Camera::etatCamera(){

	if(EtatCamera == true)
	{
		return EtatCamera;
	}
	else
	{
		return EtatCamera;
  }
}
//------------------------------------------------------------------------------

