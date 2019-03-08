//---------------------------------------------------------------------------

#pragma hdrstop

#include "TCP_IP_Client.h"
//---------------------------------------------------------------------------
TCP_IP_Client::TCP_IP_Client()
{

}

bool TCP_IP_Client::Ecriture()
{
   return true;
}

string TCP_IP_Client::get_etat()
{
	return "envoie effectué";
}
#pragma package(smart_init)
