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
  ll n, m, t;
  cin >> n >> m >> t;
  vector<ll> a(n);
  rep(i, 1, n) cin >> a[i];
  unordered_map<ll, ll> bonus;
  rep(i, 0, m)
  {
    ll x, y;
    cin >> x >> y;
    bonus[x] += y;
  }
  rep(i, 1, n)
  {
    if (t <= a[i])
    {
      cout << "No" << endl;
      return 0;
    }
    t -= a[i];
    ll room = i + 1;
    if (bonus.count(room))
      t += bonus[room];
  }
  cout << "Yes" << endl;
}