/*************************************************************************
                           linkedList
                             -------------------
    début                : 27/11/2023
    copyright            : (C) 2023 par Jixiang, Adam, Clément, Louis
    binome               : B3311 et B3309
*************************************************************************/

//---------- Interface de la classe <linkedList> (fichier linkedList.h)
//----------------

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//------------------------------------------------------------------ Types
template <typename T> struct Node {
  T *pdata;
  Node<T> *next;
};
template <typename T>

class LinkedList {
  //----------------------------------------------------------------- PUBLIC

public:
  //----------------------------------------------------- Méthodes publiques

  void Add(T *pdata, bool AddToEnd = true)
  // important:should pass a new Journey* object,
  // LinkedList will make the GC for it
  // data should have a refCount
  {
    Node<T> *node = new Node<T>{pdata, nullptr};
    pdata->refCount++;

    if (!_first)

      _first = _last = node;

    else if (AddToEnd)

      _last = _last->next = node;

    else {
      node->next = _first;
      _first = node;
    };
  }

  Node<T> *GetFirst(void) const { return _first; }

  Node<T> *GetLast(void) const { return _last; }

  //-------------------------------------------- Constructeurs - destructeur
  virtual ~LinkedList() {
    while (_first) {
      _last = _first; // from here on, _last is only used as a temp var
      _first = _first->next;
      _last->pdata->refCount--;

      if (!_last->pdata->refCount)

        delete _last->pdata;

      delete _last;
    }
  }

  //----------------------------------------------------- Attributs publics
  unsigned int refCount = 0;

protected:
  //------------------------------------------------------------------ PRIVE

  //----------------------------------------------------- Attributs protégés
  Node<T> *_first = nullptr;
  Node<T> *_last = nullptr;
};

#endif
