//---------------------------------------------------------------------------

#ifndef MYSQLH
#define MYSQLH
#include <vector>
#include <string>
#include <iostream.h>
#include <fstream.h>
//#include "include/mysql.h"
#include <vcl.h>
#include <string.h>
using namespace std;


class MySQL
{
	private:
		//MYSQL *mysql;
		bool etatConnexion;

	public:
		MySQL();
		MySQL(String ip, String login, String password, String dbname);
		bool getEtat();
};

//---------------------------------------------------------------------------
#endif
