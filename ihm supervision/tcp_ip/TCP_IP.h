/******************************************************************************/
/* 						Classe r�alis�e par Piat Sol�ne					 	  */
/*							   Classe TCP_IP	   							  */
/*																			  */
/******************************************************************************/
//---------------------------------------------------------------------------

#ifndef TCP_IPH
#define TCP_IPH
//---------------------------------------------------------------------------
#endif
class TCP_IP
{
	private:
	  bool EtatTCP;

	public:
	  TCP_IP();
	  void EcritureTCP(bool EtatTCP);
	  void LectureTCP();
	  char etatTCP();

}
