// Problem ID: 10033
// By Alexander Cai 13-06-2019
// ACCEPTED (FINALLY)

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int ptr, total;
int registers[10];
int ram[1000];

int decode() {
  int cmd = ram[ptr] / 100;
  int a = (ram[ptr] % 100) / 10;
  int b = ram[ptr] % 10;

  switch (cmd) {
    case 1:
      return 0;
      break;
    
    case 2: // set to b
      registers[a] = b;
      ptr++;
      break;

    case 3: // Add b
      registers[a] = (registers[a] + b) % 1000;
      ptr++;
      break;
    
    case 4: // Multiply by b
      registers[a] = (registers[a] * b) % 1000;
      ptr++;
      break;
    
    case 5: // Set register a to value of register b
      registers[a] = registers[b];
      ptr++;
      break;

    case 6: // Add val of reg b to reg a
      registers[a] = (registers[a] + registers[b]) % 1000;
      ptr++;
      break;

    case 7: // Multiply reg a by reg b
      registers[a] = (registers[a] * registers[b]) % 1000;
      ptr++;
      break;

    case 8:
      registers[a] = ram[registers[b]];
      ptr++;
      break;

    case 9:
      ram[registers[b]] = registers[a];
      ptr++;
      break;

    case 0:
      if (registers[b]) ptr = registers[a];
      else ptr++;
      break;

    default:
      break;
  }

  return 1;
}

int main() {
  int n;
  string temp;
  getline(cin, temp);
  stringstream(temp) >> n;
  getline(cin, temp);

  // This is the loop to handle each test case
  for (int i = 0; i < n; i++) {
    // Reset registers, ram, and pointer
    for (int j = 0; j < 10; j++) registers[j] = 0;
    for (int j = 0; j < 1000; j++) ram[j] = 0;

    if (i) cout << endl; // Print an empty line

    // Read input
    ptr = 0;
    string s;
    while (getline(cin, s)) {
      if (!s.size()) break; // Empty line, we break
      // Get 3 digit number and break into parts
      ram[ptr] = (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
      ptr++;
    }

    total = 1;
    ptr = 0;
    while (decode()) total++;

    cout << total << endl;
  }
  
  return 0;
}
