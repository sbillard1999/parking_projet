//---------------------------------------------------------------------------

#ifndef TCP_IP_ClientH
#define TCP_IP_ClientH
#include <string>
#include <vcl.h>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include "pilotage.h"
using namespace std;
//---------------------------------------------------------------------------
class TCP_IP_Client
{


	public:
	TCP_IP_Client();
	pilotage decision;
	bool Ecriture(TIdTCPClient*,UnicodeString);
	bool connexion(TIdTCPClient*);

};
#endif
