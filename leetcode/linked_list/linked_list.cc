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

  /* 206. 反转链表 */
  ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* cur = head;
    ListNode* tmp;
    while (cur) {
      tmp = cur->next;
      cur->next = pre;

      // 更新 pre cur
      pre = cur;
      cur = tmp;
    }
    return pre;
  }
  ListNode* reverse(ListNode* pre, ListNode* cur) {
    if (cur == nullptr) return pre;
    ListNode* tmp = cur->next;
    cur->next = pre;

    return reverse(cur, tmp);
  }
  ListNode* reverseList2(ListNode* head) { return reverse(nullptr, head); }

  /* 24. 两两交换链表中的节点 */
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* cur = dummy;

    while (cur->next && cur->next->next) {
      ListNode* tmp1 = cur->next;
      ListNode* tmp2 = cur->next->next;
      tmp1->next = tmp2->next;
      tmp2->next = tmp1;
      cur->next = tmp2;
    }
    return dummy->next;
  }

  void DeleteAtIndex(ListNode* head, int index) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* cur = dummy;

    while (index-- && cur->next != nullptr) {
      cur = cur->next;
    }
    ListNode* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
  }
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode* cur = head;
    while (cur) {
      size++;
      cur = cur->next;
    }
    DeleteAtIndex(head, size - n);
    return head;
  }
};

// 注意什么时候取 dummy->next 或 dummy
class MyLinkedList {
 public:
  MyLinkedList() {
    dummy_head_ = new ListNode(0);
    size_ = 0;
  }

  // todo:...
  int get(int index) {
    if (index > size_ - 1 || index < 0) {
      return -1;
    }
    ListNode* cur = dummy_head_->next;
    while (index--) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) {
    ListNode* node = new ListNode(val, dummy_head_->next);
    dummy_head_->next = node;
    size_++;
  }

  void addAtTail(int val) {
    ListNode* cur = dummy_head_;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    ListNode* node = new ListNode(val);
    cur->next = node;
    size_++;
  }

  void addAtIndex(int index, int val) {
    if (index > size_ || index < 0) {
      return;
    }
    ListNode* cur = dummy_head_;
    while (index--) {
      cur = cur->next;
    }
    ListNode* node = new ListNode(val, cur->next);
    cur->next = node;
    size_++;
  }

  void deleteAtIndex(int index) {
    if (index >= size_ || index < 0) {
      return;
    }
    ListNode* cur = dummy_head_;
    while (index--) {
      cur = cur->next;
    }
    ListNode* tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    size_--;
  }

 private:
  ListNode* dummy_head_;
  int size_;
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
