/*************************************************************************
                           compositeJourney
                             -------------------
    début                : 27/11/2023
    copyright            : (C) 2023 par Jixiang, Adam, Clément, Louis
    binome               : B3311 et B3309
*************************************************************************/

//---------- Interface de la classe <compositeJourney> (fichier
//compositeJourney.h) ----------------

#ifndef COMPOSITEJOURNEY_H_
#define COMPOSITEJOURNEY_H_

//--------------------------------------------------- Interfaces utilisées
#include "journey.h"
#include "journeys.h"

class CompositeJourney : public Journey, public Journeys {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  int Add(Journey *journey, bool check = true);
  // Mode d'emploi :
  // return value
  // 0  OK
  // -1 _to of the last journey != _from of the journey to Add

  // important:should pass a new Journey* object,
  // CompositeJourney will make the GC for it

  // check is used to check if the journeys is continuous.

  // we need to redifine << here because it exist in both Journey and Journeys

  //------------------------------------------------- Surcharge d'opérateurs
  friend std::ostream &operator<<(std::ostream &os,
                                  const CompositeJourney &compositeJourney);

  //------------------------------------------------------------------ PRIVE

private:
  //----------------------------------------------------- Méthodes protégées
  void show(void) const;
};

#endif