//---------------------------------------------------------------------------

#pragma hdrstop

#include "TCP_IP_Client.h"
//---------------------------------------------------------------------------
TCP_IP_Client::TCP_IP_Client()
{

}

bool TCP_IP_Client::connexion(TIdTCPClient *client)
{

   client->Connect();
   if(client->Connected()==true)
   {
	   return true;
   }
   else
   {
	   return false;
   }

}

bool TCP_IP_Client::Ecriture(TIdTCPClient *client,UnicodeString etat)
{
  client->Socket->WriteLn(etat);
}

#pragma package(smart_init)