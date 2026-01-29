#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll W, H, N, A, B;
  cin >> W >> H >> N;
  vector<ll> p(N), q(N);
  rep(i, 0, N) cin >> p[i] >> q[i];
  cin >> A;
  vector<ll> a(A + 1);
  rep(i, 0, A) cin >> a[i + 1];
  cin >> B;
  vector<ll> b(B + 1);
  rep(i, 0, B) cin >> b[i + 1];
  map<P, int> cnt;
  rep(i, 0, N)
  {
    int x = lower_bound(all(a), p[i]) - a.begin();
    int y = lower_bound(all(b), q[i]) - b.begin();
    cnt[{x, y}]++;
  }
  int m = inf, M = -inf;
  for (auto [_, c] : cnt)
  {
    chmin(m, c);
    chmax(M, c);
  }
  if (cnt.size() < (A + 1) * (B + 1))
    m = 0;
  cout << m << " " << M << endl;
}