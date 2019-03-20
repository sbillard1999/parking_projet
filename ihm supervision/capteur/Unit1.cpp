//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Capteur.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int sensor = 9;
	int ledP = 7;
	int ledA = 5;

	Capteur(sensor,ledP,ledA);
	if (objet() == true)
	{
		Panel1->Caption = "Présence d'un véhicule";
	}
	else
	{
		Panel1->Caption = "Absence de véhicule";
	}
}
//---------------------------------------------------------------------------

