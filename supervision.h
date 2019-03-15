//---------------------------------------------------------------------------

#ifndef supervisionH
#define supervisionH
#include <string>
#include <vcl.h>
#include <StringUtils.h>
#include <vector>


using namespace std;
//---------------------------------------------------------------------------
class supervision
{
	private:
	UnicodeString mode;
	public:
	void export_(string,string,string);
	void enregistrement_parametre(UnicodeString);
	UnicodeString getmode();
	bool compare_plaque(vector<UnicodeString>,UnicodeString plaquelu);


	supervision();
	~supervision();
	StringUtils *conversion;


};
#endif
