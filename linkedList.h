#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template <typename T> struct Node {
  T *pdata;
  Node *next;
};

template <typename T> class LinkedList {
public:
  virtual ~LinkedList() {
    while (_first) {
      _last = _first; // from here on, _last is only used as a temp var
      _first = _first->next;
      delete _last->pdata;
      delete _last;
    }
  }
  // important:should pass a new Journey* object,
  // LinkedList will make the GC for it
  void add(T *pdata) {
    Node<T> *node = new Node<T>{pdata, nullptr};
    if (!_first)
      _first = _last = node;
    else
      _last = _last->next = node;
  }

  Node<T> *getFirst(void) const { return _first; }
  Node<T> *getLast(void) const { return _last; }

protected:
  Node<T> *_first = nullptr;
  Node<T> *_last = nullptr;
};

#endif
