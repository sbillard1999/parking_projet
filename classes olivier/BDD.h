//---------------------------------------------------------------------------

#ifndef BDDH
#define BDDH
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
//---------------------------------------------------------------------------
class BDD
{
	private:
		string ip;
		string login;
		string password;
		string dbname;

	public:
		BDD();
		BDD(string ip, string login, string password, string dbname);
		bool connectBDD(string ip, string login, string password, string dbname);
		void disconnect();
		virtual	bool insert()=0;
		virtual bool update()=0;
		virtual bool delete_()=0;
		//virtual std::vector<std::vector<string>>select()=0;

};
#endif
