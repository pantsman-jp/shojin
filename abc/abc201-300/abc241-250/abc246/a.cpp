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
  map<int, int> cntx, cnty;
  rep(i, 0, 3)
  {
    int x, y;
    cin >> x >> y;
    cntx[x]++, cnty[y]++;
  }
  for (auto [x, c] : cntx)
    if (c == 1)
      cout << x << ' ';
  for (auto [y, c] : cnty)
    if (c == 1)
      cout << y << endl;
}