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
  int n;
  cin >> n;
  vector<ll> a(n + 1), b(n);
  rep(i, 0, n + 1) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  ll ans = 0;
  rep(i, 0, n)
  {
    ll x = min(a[i], b[i]);
    ans += x;
    b[i] -= x;
    x = min(a[i + 1], b[i]);
    a[i + 1] -= x;
    ans += x;
  }
  cout << ans << endl;
}