//---------------------------------------------------------------------------

#ifndef HORODATAGEH
#define HORODATAGEH
#include <vcl.h>
#include <string>
#include <vector>
using namespace std;

class HORODATAGE
{
	private:
		vector<string> proprietaire;
		vector<string>horodatage;
		vector <string>immatriculation;

	public:
		HORODATAGE();
		void lecture_access();
		string lecture_access_proprietaire(string);
		void lecture_access_vehicule(UnicodeString);
		bool ecriture();
		bool modifier();
		vector<string> getproprietaire();
		vector<string> gethorodatage();
		vector <string> getimmatriculation();
};

//---------------------------------------------------------------------------
#endif