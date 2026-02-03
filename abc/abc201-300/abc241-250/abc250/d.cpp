#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(tf) cout << (tf ? "Yes\n" : "No\n");
#define dout(x) cout << fixed << setprecision(10) << x << "\n";
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

vector<ll> primes(ll n) {
  vector<bool> prime(n + 2, true);
  prime[0] = prime[1] = false;
  for (ll i = 2; i * i <= n; i++) {
    if (prime[i])
      for (ll x = i * i; x <= n; x += i) prime[x] = false;
  }
  vector<ll> ans;
  for (ll i = 2; i <= n; i++)
    if (prime[i]) ans.push_back(i);
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> ps = primes(1e6), cnt(1e6 + 1);
  for (ll p : ps) cnt[p]++;
  rep(i, 0, 1e6) cnt[i + 1] += cnt[i];
  ll ans = 0;
  for (ll q : ps) ans += cnt[min(q - 1, n / q / q / q)];
  cout << ans << endl;
  return 0;
}