#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	int n;
	cin >> n;

  string s;
	double tries = 0, arr[n];
	for (int i = 0; i < n; ++i)
		cin >> s >> arr[i]; //eat up password

	sort(arr, arr + n, greater<double>());
	for (int i = n-1; i >= 0; --i)
    tries += ((double)(i+1)*(double)arr[i]);

	cout << fixed << tries;
	return 0;   
}