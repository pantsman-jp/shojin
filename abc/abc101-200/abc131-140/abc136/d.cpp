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

vector<pair<char, int>> rle(string s) {
  vector<pair<char, int>> ans;
  int cnt = 1;
  char now = s[0];
  rep(i, 1, s.size()) {
    if (s[i] == now)
      cnt++;
    else
      ans.push_back({now, cnt}), now = s[i], cnt = 1;
  }
  ans.push_back({now, cnt});
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  vector<ll> ans(n, 0);
  int idx = 0;
  auto xs = rle(s);
  rep(i, 0, xs.size() - 1) {
    auto [c1, a] = xs[i];
    auto [c2, b] = xs[i + 1];
    if (c1 == 'R' and c2 == 'L') {
      int pos = idx + a - 1;
      ans[pos] = (a + 1) / 2 + b / 2;
      ans[pos + 1] = a / 2 + (b + 1) / 2;
    }
    idx += a;
  }
  for (int x : ans) cout << x << " ";
  cout << endl;
}