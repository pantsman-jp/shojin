#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define YN(tf) cout << (tf ? "YES\n" : "NO\n")
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
template <typename T, typename U>
inline bool chmax(T& x, const U& y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
template <typename T, typename U>
inline bool chmin(T& x, const U& y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <typename T>
inline T lcm(T a, T b) {
  return (a / std::gcd(a, b)) * b;
}
template <typename T>
inline T divceil(T a, T b) {
  return (a + b - 1) / b;
}
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using rpq = priority_queue<T, vector<T>, greater<T>>;
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

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  rep(i, 0, t) solve();
  return 0;
}

struct P {
  ll r, c;
};

ll calc(ll a, ll b, ll c, ll d) {
  if (a == c) return (b == d) ? INF : -1;
  a -= c;
  d -= b;
  if (a < 0) a = -a, d = -d;
  if (d % a != 0) return -1;
  return d / a;
}

void solve() {
  P t, a;
  cin >> t.r >> t.c >> a.r >> a.c;
  ll n;
  int m, l;
  cin >> n >> m >> l;
  vector<pair<char, ll>> pt, pa;
  rep(_, 0, 2) {
    ll now = 0;
    rep(i, 0, m) {
      char s;
      ll a;
      cin >> s >> a;
      now += a;
      pt.emplace_back(s, now);
    }
    swap(pt, pa);
    swap(m, l);
  }
  map<char, P> mp;
  mp['U'] = P(-1, 0);
  mp['D'] = P(1, 0);
  mp['L'] = P(0, -1);
  mp['R'] = P(0, 1);
  ll ans = 0, now = 0;
  int ti = 0, ai = 0;
  while (ti < m and ai < l) {
    ll nxt = min(pt[ti].second, pa[ai].second);
    ll w = nxt - now;
    P dt = mp[pt[ti].first];
    P da = mp[pa[ai].first];
    {
      ll rx = calc(dt.r, t.r, da.r, a.r);
      ll cx = calc(dt.c, t.c, da.c, a.c);
      if (rx != -1 and cx != -1) {
        if (rx == INF) swap(rx, cx);
        if (rx == INF) {
          ans += w;
        } else if (cx == INF) {
          if (0 < rx and rx <= w) ans++;
        } else {
          if (rx == cx and 0 < rx and rx <= w) ans++;
        }
      }
    }
    t.r += dt.r * w;
    t.c += dt.c * w;
    a.r += da.r * w;
    a.c += da.c * w;
    if (nxt == pt[ti].second) ti++;
    if (nxt == pa[ai].second) ai++;
    now = nxt;
  }
  cout << ans << '\n';
}
