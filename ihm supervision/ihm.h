//---------------------------------------------------------------------------

#ifndef ihmH
#define ihmH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include "supervision.h"
#include <Vcl.Dialogs.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Admin.h"
#include "pilotage.h"
#include "TCP_IP_Client.h"
//---------------------------------------------------------------------------
using namespace std;
class Tdemarrage : public TForm
{
__published:	// Composants gérés par l'EDI
	TMainMenu *menu;
	TMenuItem *Afficherlesaccs1;
	TMemo *proprietaire;
	TMemo *plaque;
	TMemo *horodatage;
	TLabel *titre;
	TButton *export_;
	TLabel *message;
	TMenuItem *Parametre1;
	TLabel *labelmode;
	TButton *buttonmode;
	TListBox *listmode;
	TLabel *labelconnexion;
	TEdit *id;
	TEdit *mdp;
	TButton *buttonconnexion;
	TMenuItem *Demarrage1;
	TLabel *labelsauvegardemode;
	TIdTCPClient *client;
	TButton *connexiontcp;
	TButton *demarrageprog;
	TMenuItem *Manuel1;
	TButton *ouvrir;
	TButton *fermer;
	TLabel *msgco;
	TLabel *Recherche;
	TEdit *editrecherche;
	TButton *buttonrecherche;
	void __fastcall Afficherlesaccs1Click(TObject *Sender);
	void __fastcall export_Click(TObject *Sender);
	void __fastcall Parametre1Click(TObject *Sender);
	void __fastcall buttonmodeClick(TObject *Sender);
	void __fastcall buttonconnexionClick(TObject *Sender);
	void __fastcall Demarrage1Click(TObject *Sender);
	void __fastcall connexiontcpClick(TObject *Sender);
	void __fastcall demarrageprogClick(TObject *Sender);
	void __fastcall ouvrirClick(TObject *Sender);
	void __fastcall fermerClick(TObject *Sender);
	void __fastcall Manuel1Click(TObject *Sender);
	void __fastcall buttonrechercheClick(TObject *Sender);
private:	// Déclarations utilisateur

public:		// Déclarations utilisateur
	vector<string>bddplaque;
	vector<string> bddproprietaire;
	vector <string> bddhorodatage;

	supervision sup;
	pilotage decision;
	TCP_IP_Client* tcp;




	__fastcall Tdemarrage(TComponent* Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE Tdemarrage *demarrage;
//---------------------------------------------------------------------------


#endif
