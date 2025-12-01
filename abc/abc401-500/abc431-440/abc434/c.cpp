#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

void solve()
{
  int n;
  ll h;
  cin >> n >> h;
  vector<ll> t(n), l(n), u(n);
  rep(i, 0, n) cin >> t[i] >> l[i] >> u[i];
  ll pret = 0, low = h, up = h;
  rep(i, 0, n)
  {
    ll d = t[i] - pret;
    ll new_low = max(low - d, l[i]), new_up = min(up + d, u[i]);
    if (new_low > new_up)
    {
      cout << "No" << endl;
      return;
    }
    low = new_low, up = new_up, pret = t[i];
  }
  cout << "Yes" << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) solve();
}