/*************************************************************************
                           journey
                             -------------------
    début                : 27/11/2023
    copyright            : (C) 2023 par Jixiang, Adam, Clément, Louis
    binome               : B3311 et B3309
*************************************************************************/

//---------- Interface de la classe <journey> (fichier journey.h)
//----------------

#ifndef JOURNEY_H_
#define JOURNEY_H_

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <iostream>

class Journey {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  const char *GetFrom(void) const { return _from; }

  const char *GetTo(void) const { return _to; }

  //------------------------------------------------- Surcharge d'opérateurs
  friend std::ostream &operator<<(std::ostream &os, const Journey &journey);

  //-------------------------------------------- Constructeurs - destructeur
  Journey(const char *start = "", const char *end = "")
      : _from(strdup(start)), _to(strdup(end)) {}

  virtual ~Journey();

  //-------------------------------------------- Attribut publique
  unsigned int refCount = 0;

  //------------------------------------------------------------------ PROTECTED

protected:
  //----------------------------------------------------- Attributs protégés
  const char *_from;
  const char *_to;

  //------------------------------------------------------------------ PRIVE

private:
  //----------------------------------------------------- Méthodes privées
  virtual void show(void) const;
};

#endif
