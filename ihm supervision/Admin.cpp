//---------------------------------------------------------------------------

#pragma hdrstop

#include "Admin.h"
//---------------------------------------------------------------------------
admin::admin()
{
	 this->identifiant="";
	 this->mdp="";
}
bool admin::connexion(UnicodeString id,UnicodeString mdp)
{
	//recup de la bdd
	 UnicodeString idbdd="admin";
	 UnicodeString mdpbdd="root";
   if((idbdd==id)&&(mdpbdd==mdp))
   {
	 return true;
   }
   else
   {
	   return false;
   }
}

#pragma package(smart_init)
