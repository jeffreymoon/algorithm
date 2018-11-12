#include <iostream>
using namespace std;

class SimpleLinkedList
{
  struct Node
  {
    int data;
    Node *next;
    Node(int data = 0)
    {
      this->data = data;
      next = 0;
    }
  };
  Node* head;
  Node* tail;
public:
  class Iterator
  {
    Node* node;
    public:
    friend class SimpleLinkedList;
    Iterator(Node* node = 0)
    {
      this->node = node;
    }
    int GetData() const
    {
      if(node == 0) {
        throw "There is no valid Node.";
      }
      return node->data;
    }
    bool MoveNext()
    {
      if(node->next) {
        node = node->next;
        return true;
      }
      return false;
    }
    bool operator==(const Iterator& iter)
    {
      return node == iter.node;
    }
    bool operator!=(const Iterator& iter)
    {
      return node != iter.node;
    }
  };
  SimpleLinkedList()
  {
    head = 0;
    tail = 0;
  }
  ~SimpleLinkedList()
  {
    Node* prev = 0;
    while(head != 0) {
      prev = head;
      head = head->next;
      delete prev;
    }
  }
  void PushBack(int data)
  {
    Node* node = new Node(data);
    if(head == 0) {
      head = tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }
  void PushFront(int data)
  {
    Node* node = new Node(data);
    if(head == 0) {
      head = tail = node;
    } else {
      node->next = head;
      head = node;
    }
  }

  void InsertNext(Iterator iter, int data)
  {
    Node* node = new Node(data);
    Node* prev = iter.node;
    if(prev == 0) {
      if(head) {
        prev->next = head;
        head = prev;
      } else {
        head = tail = node;
      }
    } else {
      node->next = prev->next;
      prev->next = node;
      if(prev == tail) {
        tail = node;
      }
    }
  }
  Iterator Begin()
  {
    Iterator iter(head);
    return iter;
  }
  Iterator End()
  {
    Iterator iter(0);
    return iter;
  }
  bool Erase(int data)
  {
    Node* prev = 0;
    Node* seek = 0;
    for (seek = head; seek != 0; seek = seek->next) {
      if(seek->data == data) {
        break;
      }
      prev = seek;
    }
    if(seek == 0) {
      return false;
    }
    if(prev) {
      prev->next = seek->next;
    } else {
      head = seek->next;
    }
    if(seek == tail) {
      tail = prev;
    }
    delete seek;
    return true;
  }
  bool Exist(int data)
  {
    Node* seek=0;
    for(seek = head; seek != 0; seek = seek->next) {
      if(seek->data == data) {
        return true;
      }
    }
    return false;
  }
  void ViewAll() const
  {
    Node* seek = 0;
    for(seek = head; seek != 0; seek = seek->next) {
      cout << seek->data << " ";
    }
    cout << endl;
  }
};

typedef class SimpleLinkedList SList;
int main()
{
  SList sl;
  sl.PushBack(3);
  sl.PushBack(5);
  sl.PushBack(8);
  sl.PushBack(2);
  sl.PushBack(9);
  sl.PushBack(7);
  sl.PushFront(1);
  sl.ViewAll();
  sl.Erase(8);
  sl.ViewAll();

  SList::Iterator seek = sl.Begin();
  SList::Iterator last = sl.End();
  for( ; seek != last; seek.MoveNext()) {
    if(seek.GetData() == 5) {
      break;
    }
  }
  sl.InsertNext(seek, 6);
  sl.ViewAll();
  return 0;
}