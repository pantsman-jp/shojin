#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int l, h, n;

void solve()
{
  int a;
  cin >> a;
  if (a < l)
    cout << l - a << endl;
  else if (l <= a and a <= h)
    cout << 0 << endl;
  else
    cout << -1 << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> l >> h >> n;
  rep(_, 0, n) solve();
}