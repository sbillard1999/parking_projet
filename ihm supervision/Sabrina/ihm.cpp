//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ihm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tdemarrage *demarrage;

//---------------------------------------------------------------------------
__fastcall Tdemarrage::Tdemarrage(TComponent* Owner)
	: TForm(Owner)
{
	labelmode->Visible = false;
	listmode->Visible = false;
	buttonmode->Visible = false;
	titre->Visible = false;
	this->horodatage->Clear();
	this->proprietaire->Clear();
	this->plaque->Clear();
	horodatage->Visible = false;
	proprietaire->Visible = false;
	plaque->Visible = false;
	this->titre->Visible = false;
	this->export_->Visible = false;
	this->labelconnexion->Visible = true;
	this->id->Visible = true;
	this->mdp->Visible = true;
	this->buttonconnexion->Visible = true;
	labelsauvegardemode->Visible = false;
	connexiontcp->Visible = false;
	demarrageprog->Visible = false;
	ouvrir->Visible = false;
	fermer->Visible = false;
	tcp = new TCP_IP_Client();
	Recherche->Visible = false;
	buttonrecherche->Visible = false;
	editrecherche->Visible = false;

}
//---------------------------------------------------------------------------
void __fastcall Tdemarrage::Afficherlesaccs1Click(TObject *Sender)
{
	this->horodatage->Clear();
	this->proprietaire->Clear();
	this->plaque->Clear();
	horodatage->Visible = true;
	proprietaire->Visible = true;
	plaque->Visible = true;
	this->titre->Visible = true;
	this->export_->Visible = true;
	labelmode->Visible = false;
	listmode->Visible = false;
	buttonmode->Visible = false;
	labelsauvegardemode->Visible = false;
	connexiontcp->Visible = false;
	demarrageprog->Visible = false;
	ouvrir->Visible = false;
	fermer->Visible = false;
	Recherche->Visible = true;
	buttonrecherche->Visible = true;
	editrecherche->Visible = true;
	titre->Caption = "Affichage des acc�s non autoris�";

	bddplaque.clear();
	bddhorodatage.clear();
	bddproprietaire.clear();
	//lecture access
	access.lecture_access();
	bddhorodatage = access.gethorodatage();
	bddplaque = access.getimmatriculation();
	bddproprietaire = access.getproprietaire();

	//Affichage des donn�es dans des memos
	for(int i = 0; i < bddproprietaire.size(); i++) {
		this->proprietaire->Lines->Add(bddproprietaire[i].c_str());
		this->plaque->Lines->Add(bddplaque[i].c_str());
		this->horodatage->Lines->Add(bddhorodatage[i].c_str());
	}

}
//---------------------------------------------------------------------------


void __fastcall Tdemarrage::export_Click(TObject *Sender)
{
	labelsauvegardemode->Visible = false;
	message->Visible = true;
	connexiontcp->Visible = false;

	//Vider le fichier
	ofstream fichier("export.txt", ios::out | ios::trunc); //d�claration du flux et ouverture du fichier

	if (fichier) // si l'ouverture a r�ussi
	{
	}
	for (int i = 0; i < bddproprietaire.size(); i++) {
		sup.export_(bddproprietaire[i], bddplaque[i], bddhorodatage[i]);
	}

}
//---------------------------------------------------------------------------


void __fastcall Tdemarrage::Parametre1Click(TObject *Sender)
{
	labelmode->Visible = true;
	listmode->Visible = true;
	buttonmode->Visible = true;
	this->horodatage->Clear();
	this->proprietaire->Clear();
	this->plaque->Clear();
	horodatage->Visible = false;
	proprietaire->Visible = false;
	plaque->Visible = false;
	demarrageprog->Visible = false;
	titre->Visible = true;
	ouvrir->Visible = false;
	fermer->Visible = false;
	Recherche->Visible = false;
	buttonrecherche->Visible = false;
	editrecherche->Visible = false;

	labelsauvegardemode->Visible = false;
	this->export_->Visible = false;
	titre->Caption = "Parametrage du mode de fonctionnement";
	titre->Visible = true;
	connexiontcp->Visible = false;
}


//---------------------------------------------------------------------------

void __fastcall Tdemarrage::buttonmodeClick(TObject *Sender)
{
	UnicodeString mode;
	labelsauvegardemode->Visible = false;
	connexiontcp->Visible = false;

	int selection = 0;
	for (int i = 0; i < 2; i++) {
		if (listmode->Selected[i]) {
			mode = "";
			mode = listmode->Items->Strings[i];
			selection++;
		}
	}
	if (selection > 0){
		labelsauvegardemode->Visible = true;
		sup.enregistrement_parametre(mode);
		labelsauvegardemode->Caption = "vos modifications ont �t� sauvegard�";
	}

	else {
		labelsauvegardemode->Visible = true;
		labelsauvegardemode->Caption = "aucun elements selectionn�s";
	}

}
//---------------------------------------------------------------------------



void __fastcall Tdemarrage::buttonconnexionClick(TObject *Sender)
{
	UnicodeString identifiant = id->Text;
	labelsauvegardemode->Visible = false;
	connexiontcp->Visible = false;
	UnicodeString motdepasse = mdp->Text;
	admin validateur;
	msgco->Visible = false;

	if (validateur.connexion(identifiant, motdepasse) == true) {
		Afficherlesaccs1->Visible = true;
		Parametre1->Visible = true;
		Demarrage1->Visible = true;
		Manuel1->Visible = true;
		this->labelconnexion->Visible = false;
		this->id->Visible = false;
		this->mdp->Visible = false;
		this->buttonconnexion->Visible = false;
	}

	else {
		msgco->Visible = true;
		msgco->Caption = "Erreur de connexion !";
	}

}
//---------------------------------------------------------------------------



void __fastcall Tdemarrage::Demarrage1Click(TObject *Sender)
{
	labelmode->Visible = false;
	listmode->Visible = false;
	buttonmode->Visible = false;
	titre->Visible = false;
	this->horodatage->Clear();
	this->proprietaire->Clear();
	this->plaque->Clear();
	horodatage->Visible = false;
	proprietaire->Visible = false;
	plaque->Visible = false;
	this->titre->Visible = false;
	this->export_->Visible = false;
	labelsauvegardemode->Visible = false;
	connexiontcp->Visible = true;
	demarrageprog->Visible = true;
	ouvrir->Visible = false;
	fermer->Visible = false;
	Recherche->Visible = false;
	buttonrecherche->Visible = false;
	editrecherche->Visible = false;

}
//---------------------------------------------------------------------------

void __fastcall Tdemarrage::connexiontcpClick(TObject *Sender)
{
	tcp->connexion(client);
}
//---------------------------------------------------------------------------

void __fastcall Tdemarrage::demarrageprogClick(TObject *Sender)
{
	UnicodeString mode = sup.getmode();
	demarrageprog->Visible = true;
	string proprietaire;
	vector<string> plaquebase;
	string plaquelu;
	UnicodeString etat;
	UnicodeString autorisation;

	int correspondance = 0;

	if (client->Connected() == true) {

		if (mode == "Automatique") {
			plaquebase.clear();
			plaquelu = lecture.Lire_acquisition();
			access.lecture_access();
			plaquebase = access.getimmatriculation();

			// date / heure actuelle bas�e sur le syst�me actuel
			time_t tmm = time(0);
			string horodatage = ctime(&tmm);

			if (sup.compare_plaque(plaquebase, plaquelu) == true) {
				decision.ouverture();
				proprietaire = access.lecture_access_proprietaire(plaquelu);
				autorisation="autoris�";
			}
			else {
				decision.fermeture();
				proprietaire = "inconnu";
				autorisation="non autoris�";
			}
			etat = decision.getetat();
			tcp->Ecriture(client, etat);
			access.ecriture();
		}
		else if (mode == "overopen") {
			plaquebase.clear();
			decision.ouverture();
			UnicodeString etat = "ouverture";
			tcp->Ecriture(client, etat);
			string plaquelu = lecture.Lire_acquisition();
			access.lecture_access();
			plaquebase = access.getimmatriculation();

			time_t tmm = time(0);
			// convertir en forme de cha�ne
			string horodatage = ctime(&tmm);

			if (sup.compare_plaque(plaquebase, plaquelu) == true) {
				proprietaire = access.lecture_access_proprietaire(plaquelu);
			}

			else {
				proprietaire = "inconnu";
			}

			access.ecriture();
		}
	}


}
//---------------------------------------------------------------------------

void __fastcall Tdemarrage::ouvrirClick(TObject *Sender)
{
	decision.ouverture();
	UnicodeString etat = "ouverture";
	tcp->Ecriture(client, etat);
}
//---------------------------------------------------------------------------

void __fastcall Tdemarrage::fermerClick(TObject *Sender)
{
	decision.fermeture();
	UnicodeString etat="Fermeture";
	tcp->Ecriture(client,etat);
}
//---------------------------------------------------------------------------

void __fastcall Tdemarrage::Manuel1Click(TObject *Sender)
{
	labelmode->Visible = false;
	listmode->Visible = false;
	buttonmode->Visible = false;
	titre->Visible = false;
	this->horodatage->Clear();
	this->proprietaire->Clear();
	this->plaque->Clear();
	horodatage->Visible = false;
	proprietaire->Visible = false;
	plaque->Visible = false;
	this->titre->Visible = false;
	this->export_->Visible = false;
	labelsauvegardemode->Visible = false;
	connexiontcp->Visible = true;
	demarrageprog->Visible = false;
	ouvrir->Visible = true;
	fermer->Visible = true;
	Recherche->Visible = false;
	buttonrecherche->Visible = false;
	editrecherche->Visible = false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall Tdemarrage::buttonrechercheClick(TObject *Sender)
{
	proprietaire->Clear();
	plaque->Clear();
	horodatage->Clear();

	bddproprietaire.clear();
	bddplaque.clear();
	bddhorodatage.clear();

	access.lecture_access_vehicule(editrecherche->Text);

	bddproprietaire = access.getproprietaire();
	bddplaque = access.getimmatriculation();
	bddhorodatage = access.gethorodatage();
	for (int i = 0; i < bddplaque.size(); i++) {

		proprietaire->Lines->Add(bddproprietaire[i].c_str());
		plaque->Lines->Add(bddplaque[i].c_str());
		horodatage->Lines->Add(bddhorodatage[i].c_str());
	}

}
//---------------------------------------------------------------------------



