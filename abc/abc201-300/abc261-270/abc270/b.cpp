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
  int x, y, z;
  cin >> x >> y >> z;
  if (y < 0)
    x = -x, y = -y, z = -z;
  if (x < y)
  {
    cout << abs(x);
    return 0;
  }
  if (z > y)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << abs(z) + abs(x - z) << endl;
}