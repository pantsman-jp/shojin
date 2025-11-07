#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> x(n + 1);
  x[0] = 0;
  rep(i, 1, n + 1) cin >> x[i];
  vector<ll> pos;
  pos.push_back(0);
  rep(i, 1, n + 1)
  {
    pos.push_back(x[i]);
    sort(pos.begin(), pos.end());
    int r = pos.size();
    vector<ll> d(r);
    rep(j, 0, r)
    {
      ll left, right;
      if (j > 0)
        left = abs(pos[j] - pos[j - 1]);
      else
        left = inf;
      if (j < r - 1)
        right = abs(pos[j] - pos[j + 1]);
      else
        right = inf;
      d[j] = min(left, right);
    }
    ll ans = 0;
    rep(j, 0, r) ans += d[j];
    cout << ans << endl;
  }
}