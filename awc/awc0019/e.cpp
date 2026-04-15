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
  int n;
  cin >> n;
  vector<tuple<ll, ll, ll>> wd;
  rep(_, 0, n) {
    ll w, d;
    cin >> w >> d;
    wd.emplace_back(w + d, w, d);
  }
  sort(all(wd));
  priority_queue<ll> q;
  ll sumw = 0;
  for (auto [sum, w, d] : wd) {
    if (sumw <= d) {
      q.push(w);
      sumw += w;
    } else if (!q.empty() and q.top() > w) {
      sumw -= q.top();
      q.pop();
      q.push(w);
      sumw += w;
    }
  }
  cout << q.size() << "\n";
  return 0;
}