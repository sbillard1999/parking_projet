//---------------------------------------------------------------------------

#ifndef supervisionH
#define supervisionH
#include <string>
using namespace std;
//---------------------------------------------------------------------------
class supervision
{
	private:
	string mode,plaque,login,mdp,horodatage,proprietaire;
	public:
	bool compare_plaque(string,string);
	void export_();
	void mode_individuel();
	void mode_ouvert();
	void enregistrement_parametre();
	void affichage_acces(string,string,string);
	supervision();


};
#endif
