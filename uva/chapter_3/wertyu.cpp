// Problem ID: 10082
// By Alexander Cai
// Accepted

#include <iostream>
#include <string>
using namespace std;

string keyboard{"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};

int main() {
  string line;
  
  while (getline(cin, line)) {
    for (char c : line) {
      auto index = keyboard.find(c);
      if (index == string::npos)
        cout << ' ';
      else
        cout << keyboard[--index];
    }

    cout << endl;
  }
  
  return 0;
}

