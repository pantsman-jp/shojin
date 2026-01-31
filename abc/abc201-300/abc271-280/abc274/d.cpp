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
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

bool f(int x, vector<int> a) {
  set<int> s;
  s.insert(0);
  for (int na : a) {
    set<int> p;
    swap(p, s);
    for (int nx : p) {
      s.insert(nx - na);
      s.insert(nx + na);
    }
  }
  return s.count(x) != 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<int> xs, ys;
  rep(i, 1, n) {
    if (i % 2 == 0)
      xs.push_back(a[i]);
    else
      ys.push_back(a[i]);
  }
  yn(f(x - a[0], xs) and f(y, ys));
  return 0;
}