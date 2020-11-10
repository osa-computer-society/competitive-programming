// solved

// dynamic programming
// multi dimensional dynamic programming
// unbounded knapsack
// coordinate compression

#include <fstream>
#include <iostream>
#include <cstring>
#define MAXOFFERS 105
using namespace std;

ifstream fin("shopping.in");
ofstream fout("shopping.out");

// e.g. for sample input,
// code 7 = product 1
// code 8 = product 2

typedef struct offer
{
  int n;         // number of types of products
  int code[6];   // code[i] = code for ith element in deal
  int counti[6]; // counti[i] = number of code c[i]
  int countf[6]; // countf[i] = number of product i
  int p;         // price of offer
} offer;

offer offers[MAXOFFERS];
int target[6];
int code_to_product[1000];
int nproducts;
int np[6];
int dp[6][6][6][6][6];

int main()
{
  int noffers;
  fin >> noffers;

  for (int i = 1; i <= noffers; ++i)
  {
    fin >> offers[i].n;
    for (int j = 1; j <= offers[i].n; ++j)
      fin >> offers[i].code[j] >> offers[i].counti[j];
    fin >> offers[i].p;
  }

  fin >> nproducts;
  int c;
  for (int i = 1; i <= nproducts; ++i)
  {
    fin >> c >> target[i];
    code_to_product[c] = i;

    // initialize degenerate offer
    offers[noffers + i].n = 1;
    // ignore counti
    offers[noffers + i].countf[i] = 1;
    fin >> offers[noffers + i].p;
  }

  // convert product codes to product numbers
  for (int i = 1; i <= noffers; ++i)
  {
    for (int j = 1; j <= offers[i].n; ++j)
    {
      int prod = code_to_product[offers[i].code[j]];
      offers[i].countf[prod] = offers[i].counti[j];
    }
  }

  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0][0][0] = 0;
  int count[6];
  for (int o = 1; o <= noffers + nproducts; ++o)
  {
    for (int i = 1; i <= 5; ++i)
      count[i] = offers[o].countf[i];

    for (int a = count[1]; a <= target[1]; ++a)
      for (int b = count[2]; b <= target[2]; ++b)
        for (int c = count[3]; c <= target[3]; ++c)
          for (int d = count[4]; d <= target[4]; ++d)
            for (int e = count[5]; e <= target[5]; ++e)
            {
              dp[a][b][c][d][e] = min(
                  dp[a][b][c][d][e],
                  dp[a - count[1]][b - count[2]][c - count[3]][d - count[4]][e - count[5]] + offers[o].p);
            }
  }

  fout << dp[target[1]][target[2]][target[3]][target[4]][target[5]] << '\n';

  fin.close();
  fout.close();
  return 0;
}
