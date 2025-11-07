#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int r, g, b;
  string c;
  cin >> r >> g >> b >> c;
  if (c[0] == 'R')
    cout << min(g, b) << endl;
  if (c[0] == 'G')
    cout << min(r, b) << endl;
  if (c[0] == 'B')
    cout << min(r, g) << endl;
}
