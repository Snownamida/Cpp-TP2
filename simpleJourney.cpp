/*************************************************************************
                           SimpleJourney  -  description
                             -------------------
    début                : 27/11/2023
    copyright            : (C) 2023 par Jixiang, Adam, Clément, Louis
    binome               : B3311 et B3309
*************************************************************************/

//- Réalisation de la classe <SimpleJourney> (fichier SimpleJourney.cpp) -

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include personnel
#include "simpleJourney.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void SimpleJourney::show(void) const
{

  std::cout << _from << " --(" << _transportMethod << ")-> " << _to;
}

//-------------------------------------------- Constructeurs - destructeur

SimpleJourney::SimpleJourney(const char *start, const char *end, const char *transportMethod): Journey(start, end), _transportMethod(strdup(transportMethod)) {}

//Using free instead of delete because the string was created with strdup(), which require a free
SimpleJourney::~SimpleJourney() { free((char *)_transportMethod); }
