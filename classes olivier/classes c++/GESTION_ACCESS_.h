//---------------------------------------------------------------------------

#ifndef GESTION_ACCESS_H
#define GESTION_ACCESS_H
#include <vector>
#include <string>
using namespace std;

class GESTION_ACCESS
{
	private:
		string nom;
		string prenom;
		//string immatriculation;
		int etat;
		string expiration;
		string validateur;
		string message;
		string date;
		vector<string> proprietaire;
		vector<string> horodatage;
		vector<string>immatriculation;

	public:
		GESTION_ACCESS();
		void lire_demande();
		void changer_etat();
		bool envoi_message();
		bool modifier_date_expiration();
		vector<string> getproprietaire();
		vector<string> gethorodatage();
		vector <string> getimmatriculation();

};

//---------------------------------------------------------------------------
#endif
