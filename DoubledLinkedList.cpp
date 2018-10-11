#include <iostream>
using namespace std;

class DoubledLinkedList
{
  struct Node
  {
    int data;
    Node* prev;
    Node* next;
    Node(int data = 0)
    {
      this->data = data;
      prev = next = 0;
    }
  };
  Node* head;
  Node* tail;
public:
  class Iterator
  {
    Node* node;
  public:
    friend class DoubledLinkedList;
    Iterator(Node* node = 0)
    {
      this->node = node;
    }
    int GetData() const
    {
      if(node == 0) {
        throw "There is no data.";
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
  DoubledLinkedList()
  {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
  }
  ~DoubledLinkedList()
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
    HangNode(node, tail);
  }
  void PushFront(int data)
  {
    Node* node = new Node(data);
    HangNode(node, head->next);
  }
  void Insert(Iterator iter, int data)
  {
    Node* node = new Node(data);
    HangNode(node, iter.node);
  }
  Iterator Begin()
  {
    Iterator iter(head->next);
    return iter;
  }
  Iterator End()
  {
    Iterator iter(tail);
    return iter;
  }
  bool Erase(int data)
  {
    Node* pos = 0;
    for(pos = head->next; pos != tail; pos=pos->next) {
      if(pos->data == data) {
        break;
      }
    }
    if(pos==tail) {
      return false;
    }
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    delete pos;
    return true;
  }
  bool Exist(int data) 
  {
    Node* seek = 0;
    for(seek = head->next; seek != tail; seek=seek->next) {
      if(seek->data == data) {
        return true;
      }
    }
    return false;
  }
  void ViewAll() const
  {
    Node* seek = 0;
    for(seek = head->next; seek != tail; seek=seek->next) {
      cout << seek->data << " ";
    }
    cout << endl;
  }
  private:
  void HangNode(Node* now, Node* pos)
  {
    now->prev = pos->prev;
    now->next = pos;
    pos->prev->next = now;
    pos->prev = now;
  }
};

using DList = DoubledLinkedList;
int main()
{
  DList dl;
  dl.PushBack(3);
  dl.PushBack(5);
  dl.PushBack(8);
  dl.PushBack(2);
  dl.PushBack(9);
  dl.PushBack(7);
  dl.PushFront(1);
  dl.ViewAll();
  dl.Erase(8);
  dl.ViewAll();

  DList::Iterator seek = dl.Begin();
  DList::Iterator last = dl.End();
  for(; seek != last; seek.MoveNext()) {
    if(seek.GetData()==5) {
      break;
    }
  }
  dl.Insert(seek, 6);
  dl.ViewAll();
  return 0;
}