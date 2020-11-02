#include <iostream>
#include <string>
using namespace std;

int main ()
{
	int g, s, c;
	cin >> g >> s >> c;
	int bp = 3 * g + 2 * s + c;

	string vic = "";
	string tre = "";
	
	if (bp >= 8)
		vic = "Province";
	else if (bp >= 5)
		vic = "Duchy";
	else if (bp >= 2)
		vic = "Estate";
	
	if (bp >= 6) 
		tre = "Gold";
	else if (bp >= 3)
		tre = "Silver";
	else
		tre = "Copper";

	if (vic != "")
		cout << vic << " or ";
	
	cout << tre << endl;
}