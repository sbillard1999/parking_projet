//---------------------------------------------------------------------------

#ifndef HORODATAGEH
#define HORODATAGEH

class HORODATAGE
{
	private:
		string nom;
		string prenom;
		string horodatage;

	public:
		HORODATAGE();
		bool lecture();
		bool ecriture();
		bool modifier();
};

//---------------------------------------------------------------------------
#endif
