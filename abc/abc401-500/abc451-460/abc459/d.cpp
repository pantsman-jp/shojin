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
  int t;
  cin >> t;
  rep(_, 0, t) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;
    if (*max_element(all(cnt)) > (n + 1) / 2) {
      yn(false);
      continue;
    } else {
      yn(true);
      vector<pair<int, char>> cnt2;
      rep(i, 0, 26) if (cnt[i] > 0) cnt2.emplace_back(cnt[i], 'a' + i);
      sort(rall(cnt2));
      vector<char> ans(n);
      vector<int> positions;
      for (int i = 0; i < n; i += 2) positions.push_back(i);
      for (int i = 1; i < n; i += 2) positions.push_back(i);
      int idx = 0;
      for (auto [m, c] : cnt2) {
        rep(_, 0, m) ans[positions[idx++]] = c;
      }
      for (char c : ans) cout << c;
      cout << '\n';
    }
  }
  return 0;
}