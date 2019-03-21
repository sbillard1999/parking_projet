//---------------------------------------------------------------------------

#pragma hdrstop

#include "MYSQL.h"


MySQL::MySQL()
{
	//mysql = mysql_init(NULL);
}

//------------------------------------------------------------------------------

MySQL::MySQL(String ip, String login, String password, String dbname)
{
	char ipcp[16], logincp[50], passwordcp[50], dbnamecp[50];

		// Conversion String en char*
		wcstombs(ipcp, ip.c_str(), ip.Length()+1);
		wcstombs(logincp, login.c_str(), login.Length()+1);
		wcstombs(passwordcp, password.c_str(), password.Length()+1);
		wcstombs(dbnamecp, dbname.c_str(), dbname.Length()+1);

		/*if(!mysql_real_connect(mysql, ipcp, logincp,  passwordcp,  dbnamecp , 0, NULL, 0))
		{
			etatConnexion = false;
		}
		else
		{
			etatConnexion = true;
		}  */
}

//------------------------------------------------------------------------------

bool MySQL::getEtat()
{
	 if(etatConnexion == true)
	 {
		return true;
	 }
	 else
	 {
		return false;
	 }
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
