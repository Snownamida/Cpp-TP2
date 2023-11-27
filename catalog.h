/*************************************************************************
                           catalog
                             -------------------
    début                : 27/11/2023
    copyright            : (C) 2023 par Jixiang, Adam, Clément, Louis
    binome               : B3311 et B3309
*************************************************************************/

//---------- Interface de la classe <Catalog> (fichier catalog.h) ----------------
#ifndef CATALOG_H_
#define CATALOG_H_

//--------------------------------------------------- Interfaces utilisées
#include "journeys.h"

struct PathNode
{
  Journey *pjourney;
  PathNode *lastPathNode;
  LinkedList<PathNode> nextPathNodes;
  unsigned int refCount = 0;

  // Constructor that takes two parameters
  PathNode(Journey *journey, PathNode *lastNode) : pjourney(journey), lastPathNode(lastNode) {}
};

class Catalog : public Journeys
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

  void Search(const char *const from, const char *const to, PathNode *pathHead = nullptr);
//------------------------------------------------- Surcharge d'opérateurs

  friend std::ostream &operator<<(std::ostream &os, const Catalog &Catalog);

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés

  PathNode pathRoot{nullptr, nullptr};

};

#endif
