#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int v, a, b, c;
  cin >> v >> a >> b >> c;
  while (true)
  {
    if (v < a)
    {
      cout << 'F' << endl;
      return 0;
    }
    v -= a;
    if (v < b)
    {
      cout << 'M' << endl;
      return 0;
    }
    v -= b;
    if (v < c)
    {
      cout << 'T' << endl;
      return 0;
    }
    v -= c;
  }
}