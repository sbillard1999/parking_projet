/******************************************************************************/
/* 						Classe r�alis�e par Piat Sol�ne						  */
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