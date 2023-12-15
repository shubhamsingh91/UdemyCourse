#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <stack>
#include <vector>
using namespace std;

int main() {

  std::stack<int> s; // uses deque
  s.push(12);
  s.push(1);
  s.push(2);

  cout << s.size() << endl;
  s.pop();
  cout << s.size() << endl;
  cout << s.top() << endl;
  return 0;
}