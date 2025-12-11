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
  vector<ll> a(n);
  ll sum = 0;
  rep(i, 0, n) cin >> a[i], sum += a[i];
  ll x;
  cin >> x;
  ll cycle = x / sum;
  ll ans = cycle * n;
  ll now = cycle * sum;
  rep(i, 0, n)
  {
    now += a[i], ans++;
    if (now > x)
    {
      cout << ans << endl;
      return 0;
    }
  }
}