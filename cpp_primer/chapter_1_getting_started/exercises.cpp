#include <iostream>
using namespace std;

// Section 1.1.1
// Uncomment one of the exercises and compile

// Ex. 1.2
// int main() {
//   // My mac terminal doesn't actually output an error message
//   return -1;
// }

// Ex. 1.8
// int main() {
//   cout << "/*"; // Ok
//   cout << "*/"; // Ok

//   // These two are not ok because they end up with unclosed strings
//   cout << /* "*/" */;
//   cout << /* "*/" /* "/*" */;
//   return 0;
// }

// 1.4.8
// int main() {
//   int sum = 0, value = 0;
//   // The input operator (>>) returns its left value, which is cin in this case
//   // It stops looping when cin is false, i.e. the input encounters an End Of File (EOF)
//   // You can enter one through the terminal by pressing ctrl-z on Windows or ctrl-d on Mac/Linux
//   while (cin >> value) {
//     sum += value;
//   }
//   cout << "Sum is: " << sum << endl;
//   return 0;
// }