#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

ll n, m;
vector<int> dy = {-2, -1, 1, 2, 2, 1, -1, -2}, dx = {-1, -2, -2, -1, 1, 2, 2, 1};
set<vector<ll>> s;

ll solve()
{
  ll a, b;
  cin >> a >> b;
  s.insert({a, b});
  rep(i, 0, 8)
  {
    ll y = a + dy[i], x = b + dx[i];
    if (1 <= y and y <= n and 1 <= x and x <= n)
      s.insert({y, x});
  }
  return 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  rep(_, 0, m) solve();
  cout << n * n - (ll)s.size() << endl;
}
