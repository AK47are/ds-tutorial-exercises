#ifndef LINKQUEUE_HPP_
#define LINKQUEUE_HPP_

#include "LinkList.hpp"

template <typename T>
class LinkQueue : public LinkList<T> {
  using List = LinkList<T>;
  using Node = LinkNode<T>;

 private:
  Node* rear_;

  Node* End() override { return List::End(); }
  const Node* End() const override { return List::End(); }
  using List::Begin;
  using List::Erase;
  using List::GetHead;
  using List::Insert;
  using List::PrevNode;

 public:
  LinkQueue() : List(), rear_(List::GetHead()){};
  LinkQueue(std::initializer_list<T> il)
      : List(il), rear_(List::PrevNode(List::Begin(), List::End())){};

  void EnQueue(const T data) { rear_ = rear_->CreateNext(data); }

  void DeQueue() {
    if (this->Size() == 1) rear_ = GetHead();
    List::Erase(0);
  }

  const T& GetFront() const { return List::Begin()->data; }
  const T& GetRear() const { return rear_->data; }

  virtual ~LinkQueue() = default;
};
#endif
