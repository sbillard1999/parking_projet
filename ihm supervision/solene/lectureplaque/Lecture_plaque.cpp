/******************************************************************************/
/*					   Classe r�alis�e par Piat Sol�ne						  */
/*					   		Classe Lecture_plaque			  				  */
/*																			  */
/******************************************************************************/
//---------------------------------------------------------------------------

#pragma hdrstop

#include "Lecture_plaque.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Lecture_plaque::Lecture_plaque()
{


}
//------------------------------------------------------------------------------

char Lecture_plaque::Lire_acquisition(Camera * acquisition)
{
	char * acquis;
	acquis = acquisition;

    return "acquisition r�ussie: %s",acquis;

}
//------------------------------------------------------------------------------