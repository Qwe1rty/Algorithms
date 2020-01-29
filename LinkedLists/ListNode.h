#ifndef CLION_LISTNODE_H
#define CLION_LISTNODE_H

struct ListNode {

  int val;
  ListNode* next;

  explicit ListNode(int x) :
    val(x),
    next(nullptr)
  {}
};


#endif //CLION_LISTNODE_H
