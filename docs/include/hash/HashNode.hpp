#ifndef HASHNODE_HPP_
#define HASHNODE_HPP_

enum Status { EMPTY, OCCUPIED, DELETED };
template <typename T>
struct LPNode {
  int key;
  T data;
  Status status = EMPTY;
};

#endif
