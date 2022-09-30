#include "linked_list.h"

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy_head = new ListNode(0, head);

    // delete非头节点
    ListNode* cur = dummy_head;
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->next->val == val) {
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
      } else
        cur = cur->next;
    }
    return dummy_head->next;
  }
};

class MyLinkedList {
 public:
  MyLinkedList() : head(nullptr) {}

  int get(int index) {
    ListNode* cur = head;
    while (cur && index > 0) {
      cur = cur->next;
      index--;
    }
    if (cur == nullptr || index < 0)
      return -1;
    else
      return cur->val;
  }

  void addAtHead(int val) {
    ListNode* new_head = new ListNode(val);
    if (head) {
      new_head->next = head;
    }
    head = new_head;
  }

  void addAtTail(int val) {
    ListNode* cur = head;
    while (cur && cur->next) {
      cur = cur->next;
    }
    cur->next = new ListNode(val);
  }

  void addAtIndex(int index, int val) {
    ListNode* cur = head;
    while (cur && index > 1) {
      cur = cur->next;
      index--;
    }
    ListNode* new_node = new ListNode(val, cur->next);
    cur->next = new_node;
  }

  void deleteAtIndex(int index) {
    ListNode* cur = head;
    while (cur && index > 1) {
      cur = cur->next;
      index--;
    }
    ListNode* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
  }

 private:
  ListNode* head;
};

int main() {
  MyLinkedList linkedList = MyLinkedList();
  linkedList.addAtHead(1);
  linkedList.addAtTail(3);
  linkedList.addAtIndex(1, 2);  //链表变为1-> 2-> 3
  int a = linkedList.get(1);    //返回2
  linkedList.deleteAtIndex(1);  //现在链表是1-> 3
  int b = linkedList.get(1);    //返回3
  return 0;
}
