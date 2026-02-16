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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
  int ai = a.back(), aj = -1, tar = ai / 2;
  auto it = lower_bound(a.begin(), a.end() - 1, tar);
  if (it == a.begin())
    aj = *it;
  else if (it == a.end() - 1)
    aj = *(it - 1);
  else {
    int r1 = *(it - 1), r2 = *it;
    if (abs(r1 - tar) < abs(r2 - tar))
      aj = r1;
    else
      aj = r2;
  }
  cout << ai << " " << aj << endl;
  return 0;
}