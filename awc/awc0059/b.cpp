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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> t(m);
  rep(i, 0, m) cin >> t[i];
  vector<pll> pass;
  rep(i, 0, n) {
    bool ok = true;
    ll sum = 0;
    rep(j, 0, m) {
      int s;
      cin >> s;
      if (s < t[j]) ok = false;
      sum += s;
    }
    if (ok) pass.emplace_back(sum, i + 1);
  }
  if (pass.size() <= k) {
    vector<int> ans_list;
    for (auto [sum, ans] : pass) {
      ans_list.push_back(ans);
    }
    sort(all(ans_list));
    for (auto ans : ans_list) cout << ans << '\n';
  } else {
    sort(rall(pass));
    ll b = pass[k - 1].first;
    vector<int> ans_list;
    for (auto [sum, ans] : pass) {
      if (sum >= b) {
        ans_list.push_back(ans);
      }
    }
    sort(all(ans_list));
    for (auto ans : ans_list) cout << ans << '\n';
  }
  return 0;
}