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
  const int mx = 2e5 + 1;
  vector<int> lpf(mx), gpf(mx);
  rep(i, 2, mx) {
    if (lpf[i] == 0) {
      for (int j = i; j < mx; j += i) {
        if (lpf[j] == 0) lpf[j] = i;
        gpf[j] = i;
      }
    }
  }
  vector<ll> dpl(mx), dph(mx);
  rep(i, 2, mx) {
    dpl[i] = 1 + (ll)gpf[i] * dpl[i / gpf[i]];
    dph[i] = 1 + (ll)lpf[i] * dph[i / lpf[i]];
  }
  int n;
  cin >> n;
  ll low = 0, high = 0;
  rep(i, 0, n) {
    int a;
    cin >> a;
    low += dpl[a];
    high += dph[a];
  }
  cout << low << " " << high << '\n';
  return 0;
}