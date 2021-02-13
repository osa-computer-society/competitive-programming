# USACO 2019 December Contest, Silver

## 1. MooBuzz

*(Analysis by Benjamin Qi)*

Let $f(n)$ denote the n-th number spoken. Within the first 15 turns exactly eight numbers are spoken; in fact, this is true for any 15 consecutive turns. Therefore, we should be able to calculate $f(n)$ recursively. For $n \gt 8$,

$$f(n)=f(n−8)+15.$$

Defining $num=\lfloor n−18 \rfloor$, we can rewrite this as equation as

$$f(n)=f(n−8 \cdot num)+15 \cdot num,$$

where $1 \lt n − 8 \cdot num \lt 8$. When $n \lt 8$, we can easily calculate $f(n)$ via brute force, so we're done. My code follows:

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back

void setIO(string name) {
 freopen((name+".in").c_str(),"r",stdin);
 freopen((name+".out").c_str(),"w",stdout);
 ios_base::sync_with_stdio(0);
}

vi stor; // first 8 numbers

bool ok(int x) { return x%3 && x%5; } // not fizz or buzz
int dumb(int N) { // get f(n) slowly
 for (int i = 1;;++i) if (ok(i)) {
  N --;
  if (N == 0) return i;
 }
}
int smart(int N) { // get f(n) quickly
 int num = (N-1)/8;
 return stor[N-8*num-1]+15*num;
}

int main() {
 setIO("moobuzz");
 FOR(i,1,16) if (ok(i)) stor.pb(i);
 int N; cin >> N;
 cout << smart(N) << "\n";
}
```
