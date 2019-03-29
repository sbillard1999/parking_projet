//---------------------------------------------------------------------------

#ifndef GESTION_VALIDATEURH
#define GESTION_VALIDATEURH

class GESTION_VALIDATEUR
{
	private:
		string login;
		string password;

	public:
		GESTION_VALIDATEUR();
		bool lecture();
		bool ecriture();
		bool modifier();
		bool authentification_validateur(string *login, string *password);
		bool ajouter_validateur();
		bool modifier_validateur();
		bool supprimer_validateur();

};

//---------------------------------------------------------------------------
#endif
