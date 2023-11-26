#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template <typename Tdata, typename TnextData> struct Node {
  Tdata *pdata;
  Node<TnextData, Tdata> *next;
};

template <typename Tdata, typename TnextData> class LinkedList {
public:
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
  // important:should pass a new Journey* object,
  // LinkedList will make the GC for it
  // data should have a refCount
  void add(Tdata *pdata) {
    Node<Tdata, TnextData> *node = new Node<Tdata, TnextData>{pdata, nullptr};
    pdata->refCount++;
    if (!_first)
      _first = _last = node;
    else
      _last = _last->next = node;
  }

  Node<Tdata, TnextData> *getFirst(void) const { return _first; }
  Node<Tdata, TnextData> *getLast(void) const { return _last; }

protected:
  Node<Tdata, TnextData> *_first = nullptr;
  Node<Tdata, TnextData> *_last = nullptr;
};

#endif
