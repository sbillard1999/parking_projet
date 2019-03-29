//---------------------------------------------------------------------------

#ifndef DEMANDE_ACCESSH
#define DEMANDE_ACCESSH

class DEMANDE_ACCESS
{
	private:
		string nom;
		string prenom;
		string email;
		string immatriculation;
		int nbvehicule;
		string proprietaire;
		string etat;

	public:
		DEMANDE_ACCESS();
		bool lecture();
		bool update_etat();

};

//---------------------------------------------------------------------------
#endif
