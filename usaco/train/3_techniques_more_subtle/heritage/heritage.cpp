// solved
// recurse, recursion
// binary tree
// inorder
// preorder
// postorder

#include <fstream>
#include <string>
using namespace std;

ifstream fin("heritage.in");
ofstream fout("heritage.out");

string inorder, preorder;
int n, pos[30];

void recurse(int l, int r, int i)
{
    if (l == r)
        return;

    int rootpos = pos[preorder[i] - 'A'];
    recurse(l, rootpos, i + 1);
    recurse(rootpos + 1, r, i + rootpos - l + 1);

    fout << preorder[i];
}

int main()
{
    fin >> inorder >> preorder;
    n = inorder.size();

    for (int i = 0; i < n; ++i)
        pos[inorder[i] - 'A'] = i;

    recurse(0, inorder.size(), 0);

    fout << '\n';

    fin.close();
    fout.close();
    return 0;
}
