/*************************************************************************
                           compositeJourney
                             -------------------
    début                : 27/11/2023
    copyright            : (C) 2023 par Jixiang, Adam, Clément, Louis
    binome               : B3311 et B3309
*************************************************************************/

//---------- Réalisation de la classe <compositeJourney> (fichier compositeJourney.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstdlib>
#include <cstring>
#include <ostream>
using std::ostream;
using std::strcmp;
//------------------------------------------------------ Include personnel
#include "compositeJourney.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
int CompositeJourney::Add(Journey *pjourney, bool check) 
{
  if (!journeyLinkedList.GetFirst()) {

    Journeys::Add(pjourney);
    //Using free instead of delete because the string was created with strdup(), which require a free
    free((char *)_from); 

    free((char *)_to);
    _from = strdup(pjourney->GetFrom());
    _to = strdup(pjourney->GetTo());
    return 0;

  }

  if (check && std::strcmp(journeyLinkedList.GetLast()->pdata->GetTo(), pjourney->GetFrom())) {

    delete pjourney;
    return -1;
    
  }
  
  Journeys::Add(pjourney);
  //Using free instead of delete because the string was created with strdup(), which require a free

  free((char *)_to);
  _to = strdup(pjourney->GetTo());
  return 0;
} //----- Fin de Add


//------------------------------------------------- Surcharge d'opérateurs
std::ostream &operator<<(std::ostream &os, const CompositeJourney &compositeJourney)
{
  compositeJourney.show();
  return os;
} //----- Fin de operator <<

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void CompositeJourney::show(void) const 
{ 
  Journeys::show(); 
} //----- Fin de show