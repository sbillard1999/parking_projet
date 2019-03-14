//---------------------------------------------------------------------------

#ifndef AdminH
#define AdminH
#include <string>
#include <vcl.h>
using namespace std;
//---------------------------------------------------------------------------
class admin
{
   string identifiant,mdp;
   public:
   admin();
   bool connexion(UnicodeString,UnicodeString);
   void deconnexion();
};
#endif
