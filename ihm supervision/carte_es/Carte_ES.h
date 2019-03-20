/******************************************************************************/
/* 						Classe réalisée par Piat Solène						  */
/*							   Classe Carte_ES	   							  */
/*																			  */
/******************************************************************************/
//---------------------------------------------------------------------------

#ifndef Carte_ESH
#define Carte_ESH
//---------------------------------------------------------------------------
#endif
class Carte_ES
{
	private:
	   TCPIP * tcp;
	   bool EtatCarte;


	public:
	  Carte_ES();
	  void EcritureCarte();
	  char etatCarte();




};