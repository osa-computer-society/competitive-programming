// Problem ID: 848
// By Alexander Cai 2019-06-29
// Accepted
// With help from https://codingstrife.wordpress.com/2013/07/23/solution-uva848-pc110308-fmt/

#include <iostream>
#include <string>
using namespace std;
 
void rstrip(string &line) {
  if (line == "") return;
  for (int i = (int) line.length() - 1; !line.empty() && line[i] == ' ' ; i--)
    line.erase(i, 1);
}
 
void lstrip(string &line) {
  if (line == "") return;
  for (int i = 0; !line.empty() && line[i] == ' '; )
    line.erase(i, 1);
}

int main() {
  string output = "", line, buffer = "";
  bool line_created = false;

  while (true) {
    line = "";
    // read next line into line, if no more then we break
    if (!line_created && !getline(cin, line)) break;
    line_created = false;

    if (line != "" && line[0] == '*') break;
    rstrip(line);
    line = buffer + line;

    if (line.length() > 72) {
      buffer = "";
      // will be false if no space is found with index less than 72
      bool long_word = true;
      int space_idx = -1;
      for (int i = (int) line.length() - 1; i > 0; i--) {
        if (line[i] != ' ') continue;
        space_idx = i; // index of the rightmost space

        if (i <= 72) {
          buffer = line.substr(i+1, line.length());
          line = line.substr(0, i);
          long_word = false;
          break;
        }
      }

      if (space_idx != -1 && long_word) {
        buffer = line.substr(space_idx, line.length());
        line = line.substr(0, space_idx);
        long_word = false;
      }
      
      if (!long_word) line_created = true;
      rstrip(line);
      lstrip(buffer);
    } else if (line.length() < 72) {
      if (line.length() == 0) buffer = "";
      else if (line[(int) line.length() - 1] == ' ') buffer = ""; // if last char in line is space, erase buffer
      else if (cin.peek() == ' ' || cin.peek() == '\n' || cin.eof()) buffer = "";
      else {
        buffer = line + " ";
        line = "";
        continue;
      }
    } else buffer = ""; // line has length 72

    output += line + '\n';
  }

  if (output[output.length()-1] == ' ' || output[output.length()-1] == '\n')
    output.erase(output.length()-1, 1);
  cout << output << endl;

  return 0;
}
