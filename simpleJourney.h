/*************************************************************************
                           SimpleJourney  -  description
                             -------------------
    début                : 27/11/2023
    copyright            : (C) 2023 par Jixiang, Adam, Clément, Louis
    binome               : B3311 et B3309
*************************************************************************/

//--- Interface de la classe <simpleJourney> (fichier simpleJourney.h) ---

#ifndef SIMPLEJOURNEY_H_
#define SIMPLEJOURNEY_H_

//--------------------------------------------------- Interfaces utilisées

#include "journey.h"


class SimpleJourney : public Journey {

//----------------------------------------------------------------- PUBLIC


public:

//-------------------------------------------- Constructeurs - destructeur

  SimpleJourney(const char *start = "", const char *end = "", const char *transportMethod = "");

  virtual ~SimpleJourney();

//-------------------------------------------------------------- PROTECTED

protected:
//----------------------------------------------------- Attributs protégés

  const char *_transportMethod;

//------------------------------------------------------------------ PRIVE

private:
//------------------------------------------------------- Méthodes privées

  void show(void) const;
};

#endif
