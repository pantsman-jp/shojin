#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
using ld = long double;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ld w, h, x, y;
  cin >> w >> h >> x >> y;
  cout << fixed << setprecision(10) << w * h / 2.0;
  cout << ' ' << ((w / 2.0 == x) and (h / 2.0 == y)) << endl;
}