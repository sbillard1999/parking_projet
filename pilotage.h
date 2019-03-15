//---------------------------------------------------------------------------

#ifndef pilotageH
#define pilotageH
#include <string>
#include <vcl.h>
//---------------------------------------------------------------------------
using namespace std;
class pilotage
{
   UnicodeString etat;
   public:
   void ouverture();
   void fermeture();
   UnicodeString getetat();

};
#endif
