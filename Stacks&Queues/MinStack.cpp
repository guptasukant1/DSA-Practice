#include <algorithm>
#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

// $ Minimum Stack Implement Min Stack | O(2N) and O(N) Space Complexity. Design
// a stack that supports push, pop, top, and retrieving the minimum element in
// constant time.

// $ Type 1
// $ TC: O(1) | SC: O(2N)
class MinStack {
  stack<pair<int, int>> st;

public:
  void push(int x) {
    int mini;
    if (st.empty())
      mini = x;
    else
      mini = min(st.top().second, x);
    st.push({x, mini});
  }
  void pop() {
    if (!st.empty())
      st.pop();
  }
  int top() {
    if (!st.empty())
      return st.top().first;
    throw runtime_error("Stack is Empty");
  }
  int getMin() {
    if (!st.empty())
      return st.top().second;
    throw runtime_error("Stack is Empty");
  }
};

// $ Type 2
// $ TC: O() | SC: O()
class MinStack2 {
  stack<pair<int, int>> st;

public:
};

int main() {
  MinStack minStack;
  minStack.push(3);
  minStack.push(5);
  cout << "Current minimum: " << minStack.getMin() << endl;

  minStack.push(2);
  minStack.push(1);
  cout << "Current minimum: " << minStack.getMin() << endl;

  minStack.pop();
  cout << "Current minimum after pop: " << minStack.getMin() << endl;

  cout << "Top element: " << minStack.top() << endl;

  minStack.pop();
  cout << "Current minimum after another pop: " << minStack.getMin() << endl;
}
