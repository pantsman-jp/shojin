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
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define dout(x) cout << fixed << setprecision(10) << x << "\n"
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  ll s;
  cin >> n >> m >> s;
  vector<ll> d(n);
  rep(i, 0, n) cin >> d[i];
  map<int, ll> pr;
  rep(_, 0, m) {
    int p;
    ll r;
    cin >> p >> r;
    pr[p - 1] = r;
  }
  bool tired = false;
  rep(i, 0, n) {
    s -= d[i];
    if (tired) s -= d[i];
    if (s <= 0 and !tired) tired = true;
    if (pr[i] != 0) s += pr[i];
  }
  cout << s << '\n';
  return 0;
}