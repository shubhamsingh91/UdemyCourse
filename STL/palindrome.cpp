#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_palindrome(const std::string &s) {
  std::deque<char> d1;
  std::deque<char> d2;

  for (auto c : s) {
    if ((c != ' ') && (c != '\'') && (c != ',') && (c != '-') && (c != '_') &&
        (c != '.') && (c != '!') && (c != '+')) {
      d1.push_back(std::tolower(c));
      d2.push_front(std::tolower(c));
    }
  }
  auto it = d1.begin();
  for (int i = 0; i < d1.size(); i++) {
    if (d1[i] != d2[i]) {
      return false;
    }
  }
  return true;
}

int main() {

  std::vector<string> test_str{
      "a",
      "aa",
      "aba",
      "abba",
      "abbcbba",
      "ab",
      "abc",
      "radar",
      "bob",
      "ana",
      "avid diva",
      "Amore, Roma",
      "A Toyota's a Toyota",
      "A Santa at NASA",
      "C++",
      "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-panama,",
      "This is a palindrome",
      "palindrome"};

  for (const auto &s : test_str) {
    cout << is_palindrome(s) << endl;
  }

  return 0;
}