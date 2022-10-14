#include <queue>
#include <stack>

using namespace std;

class Solution {
 public:
};

// stack 实现 queue
class MyQueue {
 public:
  MyQueue() {}

  void push(int x) { in_stack.push(x); }

  int pop() {
    if (out_stack.empty()) {
      while (!in_stack.empty()) {
        out_stack.push(in_stack.top());
        in_stack.pop();
      }
    }
    int res = out_stack.top();
    out_stack.pop();
    return res;
  }

  // todo: 复用pop()
  int peek() {
    int res = this->pop();
    out_stack.push(res);
    return res;
  }

  bool empty() { return in_stack.empty() && out_stack.empty(); }

 private:
  stack<int> in_stack;
  stack<int> out_stack;
};

// queue 实现 stack
class MyStack {
 public:
  MyStack() {}

  void push(int x) { que.push(x); }

  int pop() {
    int size = que.size();
    --size;
    while (size--) {
      que.push(que.front());
      que.pop();
    }
    int res = que.front();
    que.pop();
    return res;
  }

  int top() { return que.back(); }

  bool empty() { return que.empty(); }

 private:
  queue<int> que;
};

int main() {
  Solution ss;
  return 0;
}
