//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
void __fastcall TForm1::serveurExecute(TIdContext *AContext)
{
	msg="";
	msg=serv->lecture(AContext);
	Label1->Caption=msg;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

   serv->activation(serveur);

}
//---------------------------------------------------------------------------



