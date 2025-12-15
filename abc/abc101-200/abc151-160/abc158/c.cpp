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
  int a, b;
  cin >> a >> b;
  rep(x, 1, 1e4 + 1)
  {
    if ((8 * x) / 100 == a and (10 * x) / 100 == b)
    {
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}