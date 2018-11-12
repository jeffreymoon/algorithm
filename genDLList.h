#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template<typename T>
class DLLNode {
  public:
  DLLNode() {
    next = prev = 0;
  }
  DLLNode(const T& el, DLLNode* n = 0, DLLNode* p = 0) {
    info = el;
    next = n;
    prev = p;
  }
  T info;
  DLLNode* next;
  DLLNode* prev;
};

#endif