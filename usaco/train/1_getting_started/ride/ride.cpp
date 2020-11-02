#include <fstream>
#include <string>
using namespace std;

ifstream fin("ride.in");
ofstream fout("ride.out");

int main()
{
    string comet, group;
    fin >> comet >> group;

    // get the total product for the comet
    int comet_prod = 1;
    if (comet.size() == 0)
        comet_prod = 0;
    else
        for (int i = 0; i < comet.size(); ++i)
            comet_prod = (comet_prod * (comet[i] - 'A' + 1)) % 47;

    // get the total product for the group
    int group_prod = 1;
    if (group.size() == 0)
        group_prod = 0;
    else
        for (int i = 0; i < group.size(); ++i)
            group_prod = (group_prod * (group[i] - 'A' + 1)) % 47;

    if (comet_prod == group_prod)
        fout << "GO\n";
    else
        fout << "STAY\n";

    fin.close();
    fout.close();
    return 0;
}
