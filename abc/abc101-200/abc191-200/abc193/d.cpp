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

ll score(const string& s) {
  vector<ll> pow10 = {1, 10, 100, 1000, 10000, 100000};
  vector<ll> cnt(10);
  for (char c : s) cnt[c - '0']++;
  ll ans = 0;
  rep(i, 1, 10) ans += i * pow10[cnt[i]];
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll k;
  string s, t;
  cin >> k >> s >> t;
  vector<ll> pile(10, k);
  rep(i, 0, 4) {
    pile[s[i] - '0']--;
    pile[t[i] - '0']--;
  }
  ld ans = 0.0;
  rep(i, 1, 10) if (pile[i] != 0) {
    rep(j, 1, 10) if (pile[j] - (i == j) >= 0) {
      string ss = s, tt = t;
      ss[4] = char('0' + i);
      tt[4] = char('0' + j);
      if (score(ss) > score(tt)) {
        ld ps = pile[i] / (9.0 * k - 8.0);
        ld pt = (pile[j] - (i == j)) / (9.0 * k - 9.0);
        ans += ps * pt;
      }
    }
  }
  dout(ans);
  return 0;
}