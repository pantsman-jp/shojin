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
  ll n, T;
  cin >> n >> T;
  vector<ll> t(n);
  rep(i, 0, n) cin >> t[i];
  ll ans = T;
  rep(i, 0, n - 1) ans += min(T, t[i + 1] - t[i]);
  cout << ans << endl;
}