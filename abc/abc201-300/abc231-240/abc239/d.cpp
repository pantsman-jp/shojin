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

vector<bool> era(ll n) {
  vector<bool> is_prime(n + 2, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i * i <= n; i++) {
    if (is_prime[i])
      for (ll j = i * i; j <= n; j += i) is_prime[j] = false;
  }
  return is_prime;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<bool> is_prime = era(b + d + 1);
  rep(x, a, b + 1) {
    bool ok = true;
    rep(y, c, d + 1) {
      if (is_prime[x + y]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "Takahashi" << endl;
      return 0;
    }
  }
  cout << "Aoki" << endl;
  return 0;
}