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
   labelmode->Visible=false;listmode->Visible=false;buttonmode->Visible=false;
   titre->Visible=false;
	this->horodatage->Clear();this->proprietaire->Clear();this->plaque->Clear();
	horodatage->Visible=false;proprietaire->Visible=false;plaque->Visible=false;
	this->titre->Visible=false;this->export_->Visible=false;
	this->labelconnexion->Visible=true;
	this->id->Visible=true;
	this->mdp->Visible=true;
	this->buttonconnexion->Visible=true;
	labelsauvegardemode->Visible=false;
	connexiontcp->Visible=false;
	demarrageprog->Visible=false;
	ouvrir->Visible=false;
	fermer->Visible=false;
	tcp=new TCP_IP_Client();
	Recherche->Visible=false;
	buttonrecherche->Visible=false;
	editrecherche->Visible=false;

}
//---------------------------------------------------------------------------
void __fastcall Tdemarrage::Afficherlesaccs1Click(TObject *Sender)
{
	this->horodatage->Clear();this->proprietaire->Clear();this->plaque->Clear();
	horodatage->Visible=true;proprietaire->Visible=true;plaque->Visible=true;
	this->titre->Visible=true;this->export_->Visible=true;
	labelmode->Visible=false;listmode->Visible=false;buttonmode->Visible=false;
	labelsauvegardemode->Visible=false;
	connexiontcp->Visible=false;
	demarrageprog->Visible=false;
    ouvrir->Visible=false;
	fermer->Visible=false;
	Recherche->Visible=true;
	buttonrecherche->Visible=true;
	editrecherche->Visible=true;
	titre->Caption="Affichage des acc�s";
    	bddproprietaire.clear();
		bddplaque.clear();
		bddhorodatage.clear();



	for(int i=0;i<3;i++)
	{
		bddplaque.push_back("ewf-dd44-fd");
		bddproprietaire.push_back("sabrina");
		bddhorodatage.push_back("19/04/2019");
		bddplaque.push_back("ewdfdff-ffddd44-fd");
		bddproprietaire.push_back("sabrinda");
		bddhorodatage.push_back("19/04/2019");
	}


	for(int i=0;i<bddproprietaire.size();i++)
	{
		this->proprietaire->Lines->Add(bddproprietaire[i].c_str());
		this->plaque->Lines->Add(bddplaque[i].c_str());
		this->horodatage->Lines->Add(bddhorodatage[i].c_str());

	}




}
//---------------------------------------------------------------------------


void __fastcall Tdemarrage::export_Click(TObject *Sender)
{
	labelsauvegardemode->Visible=false;
	message->Visible=true;
	connexiontcp->Visible=false;

	ofstream fichier("export.txt", ios::out | ios::trunc);  //d�claration du flux et ouverture du fichier

		if(fichier)  // si l'ouverture a r�ussi
		{

		}
	for(int i=0;i<bddproprietaire.size();i++)
	{
	  sup.export_(bddproprietaire[i],bddplaque[i],bddhorodatage[i]);
	}

}
//---------------------------------------------------------------------------


void __fastcall Tdemarrage::Parametre1Click(TObject *Sender)
{
   labelmode->Visible=true;listmode->Visible=true;buttonmode->Visible=true;
	this->horodatage->Clear();this->proprietaire->Clear();this->plaque->Clear();
	horodatage->Visible=false;proprietaire->Visible=false;plaque->Visible=false;
	demarrageprog->Visible=false;
	titre->Visible=true;
    ouvrir->Visible=false;
	fermer->Visible=false;
    Recherche->Visible=false;
	buttonrecherche->Visible=false;
	editrecherche->Visible=false;

	labelsauvegardemode->Visible=false;
	this->export_->Visible=false;
   titre->Caption="Parametrage du mode de fonctionnement";
   titre->Visible=true;
   connexiontcp->Visible=false;
}


//---------------------------------------------------------------------------

void __fastcall Tdemarrage::buttonmodeClick(TObject *Sender)
{
	UnicodeString mode;
	labelsauvegardemode->Visible=false;
	connexiontcp->Visible=false;

   int selection=0;
	for(int i=0;i<3;i++)
   {
	   if(listmode->Selected[i])
	   {

		mode=listmode->Items->Strings[i];
		selection++;
	   }

   }
	 if(selection>0)

	 {
		 labelsauvegardemode->Visible=true;
		 sup.enregistrement_parametre(mode);
		 labelsauvegardemode->Caption="vos modifications ont �t� sauvegard�";
     }


	  else
	  {
		 labelsauvegardemode->Visible=true;
		 labelsauvegardemode->Caption="aucun elements selectionn�s";
	  }

}
//---------------------------------------------------------------------------



void __fastcall Tdemarrage::buttonconnexionClick(TObject *Sender)
{
	UnicodeString identifiant=id->Text;
	labelsauvegardemode->Visible=false;
	connexiontcp->Visible=false;
	UnicodeString motdepasse=mdp->Text;
	admin validateur;
	msgco->Visible=false;



	if(validateur.connexion(identifiant,motdepasse)==true)
	{
	   Afficherlesaccs1->Visible=true;
	   Parametre1->Visible=true;
	   Demarrage1->Visible=true;
	   Manuel1->Visible=true;
		this->labelconnexion->Visible=false;
		this->id->Visible=false;
		this->mdp->Visible=false;
		this->buttonconnexion->Visible=false;


	}

	else
	{
		msgco->Visible=true;
		msgco->Caption="Erreur de connexion !";
    }






}
//---------------------------------------------------------------------------



void __fastcall Tdemarrage::Demarrage1Click(TObject *Sender)
{

  labelmode->Visible=false;listmode->Visible=false;buttonmode->Visible=false;
   titre->Visible=false;
	this->horodatage->Clear();this->proprietaire->Clear();this->plaque->Clear();
	horodatage->Visible=false;proprietaire->Visible=false;plaque->Visible=false;
	this->titre->Visible=false;this->export_->Visible=false;
	labelsauvegardemode->Visible=false;
	connexiontcp->Visible=true;
	demarrageprog->Visible=true;
    ouvrir->Visible=false;
	fermer->Visible=false;
    Recherche->Visible=false;
	buttonrecherche->Visible=false;
	editrecherche->Visible=false;




}
//---------------------------------------------------------------------------



void __fastcall Tdemarrage::connexiontcpClick(TObject *Sender)
{

	tcp->connexion(client);


}
//---------------------------------------------------------------------------

void __fastcall Tdemarrage::demarrageprogClick(TObject *Sender)
{
	UnicodeString mode=sup.getmode();
	demarrageprog->Visible=true;

	if(client->Connected()==true)
	{
		if(mode=="automatique")
		{

			vector<UnicodeString>plaquebase;

			plaquebase.push_back("ds-478-dsf");
			plaquebase.push_back("fd-fdf-455");
			plaquebase.push_back("df-55-fd");
			UnicodeString plaquelu="df-55-fd";
			if(sup.compare_plaque(plaquebase,plaquelu)==true)
			{
				decision.ouverture();
			}
			else
			{
				decision.fermeture();
			}
			UnicodeString etat=decision.getetat();
			tcp->Ecriture(client,etat);
			//enregistrer

		}
		else if(mode=="overopen")
		{
			decision.ouverture();
			UnicodeString etat="ouverture";
			tcp->Ecriture(client,etat);
			//ecriture bdd

		}
    }

}
//---------------------------------------------------------------------------

void __fastcall Tdemarrage::ouvrirClick(TObject *Sender)
{
	decision.ouverture();
	UnicodeString etat="ouverture";
	tcp->Ecriture(client,etat);

	//bdd
}
//---------------------------------------------------------------------------

void __fastcall Tdemarrage::fermerClick(TObject *Sender)
{
	decision.fermeture();
	UnicodeString etat="Fermeture";
	tcp->Ecriture(client,etat);
	//bdd
}
//---------------------------------------------------------------------------

void __fastcall Tdemarrage::Manuel1Click(TObject *Sender)
{
	labelmode->Visible=false;listmode->Visible=false;buttonmode->Visible=false;
   titre->Visible=false;
	this->horodatage->Clear();this->proprietaire->Clear();this->plaque->Clear();
	horodatage->Visible=false;proprietaire->Visible=false;plaque->Visible=false;
	this->titre->Visible=false;this->export_->Visible=false;
	labelsauvegardemode->Visible=false;
	connexiontcp->Visible=true;
	demarrageprog->Visible=false;
	ouvrir->Visible=true;
	fermer->Visible=true;
    Recherche->Visible=false;
	buttonrecherche->Visible=false;
	editrecherche->Visible=false;

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


	//bdd requette select
	for(int i=0;i<6;i++)
	{
	  bddproprietaire.push_back("sabrina");
	  bddplaque.push_back("ed-qq85-ds");
	  bddhorodatage.push_back("date");
	}
	for(int i=0;i<bddplaque.size();i++)
	{

			proprietaire->Lines->Add(bddproprietaire[i].c_str());
			plaque->Lines->Add(bddplaque[i].c_str());
			horodatage->Lines->Add(bddhorodatage[i].c_str());

	}

}
//---------------------------------------------------------------------------

