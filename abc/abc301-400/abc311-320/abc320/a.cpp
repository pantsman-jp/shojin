#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main()
{
  int a, b;
  cin >> a >> b;
  int x = 1, y = 1;
  rep(_, b) { x *= a; }
  rep(_, a) { y *= b; }
  cout << x + y << endl;
}
