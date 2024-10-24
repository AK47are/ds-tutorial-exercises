#ifndef LINKQUEUE_HPP_
#define LINKQUEUE_HPP_

#include "LinkList.hpp"

template <typename T>
class LinkQueue : public LinkList<T> {
  using List = LinkList<T>;
  using Node = LinkNode<T>;

 private:
  Node* rear;

  Node* End() override { return List::End(); }
  const Node* End() const override { return List::End(); }
  using List::Begin;
  using List::Erase;
  using List::GetHead;
  using List::Insert;
  using List::PrevNode;

 public:
  LinkQueue() : List(), rear(List::GetHead()){};
  LinkQueue(std::initializer_list<T> il)
      : List(il), rear(List::PrevNode(List::Begin(), List::End())){};

  Node* EnQueue(const T data) { return rear = rear->CreateNext(data); }

  Node* DeQueue() { return List::Erase(0); }

  const T& GetFront() const { return List::Begin()->data; }
  const T& GetRear() const { return rear->data; }

  virtual ~LinkQueue() = default;
};
#endif
