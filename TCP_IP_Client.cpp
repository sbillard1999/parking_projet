//---------------------------------------------------------------------------

#pragma hdrstop

#include "TCP_IP_Client.h"
//---------------------------------------------------------------------------
TCP_IP_Client::TCP_IP_Client()
{

}

bool TCP_IP_Client::connexion(TIdTCPClient client,unsigned short host,unsigned short port)
{
   client.Host=host;
   client.Port=port;
   client.Connect();
   if(client.Connected()==true)
   {
	   return true;
   }
   else
   {
	   return false;
   }


}
void TCP_IP_Client::deconnexion(TIdTCPClient client)
{
   client.Disconnect();
}
bool TCP_IP_Client::Ecriture(TIdTCPClient client)
{

  UnicodeString etat=decision.getetat();
  client.Socket->WriteLn(etat);
}

#pragma package(smart_init)
