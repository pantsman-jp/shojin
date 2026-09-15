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
using mint = modint998244353;
// using mint = modint1000000007;

// 素数判定
bool is_prime(ll n) {
  if (n < 2) return false;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

// 素数判定配列
vector<bool> era(ll n) {
  vector<bool> is_prime(n + 2, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (ll j = i * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return is_prime;
}

// 素数列挙
vector<ll> primes(ll n) {
  vector<bool> prime(n + 2, true);
  prime[0] = prime[1] = false;
  for (ll i = 2; i * i <= n; i++) {
    if (prime[i]) {
      for (ll x = i * i; x <= n; x += i) prime[x] = false;
    }
  }
  vector<ll> ans;
  for (ll i = 2; i <= n; i++) {
    if (prime[i]) ans.push_back(i);
  }
  return ans;
}

// 約数列挙
vector<ll> divisors(ll n) {
  vector<ll> ans;
  for (ll m = 1; m * m <= n; m++) {
    if (n % m != 0) continue;
    ans.push_back(m);
    if (m != n / m) ans.push_back(n / m);
  }
  sort(all(ans));
  return ans;
}

// 素因数分解
/// vector<pll>
vector<pll> factorization(ll n) {
  vector<pll> ans;
  for (ll p = 2; p * p <= n; p++) {
    if (n % p != 0) continue;
    ll e = 0;
    while (n % p == 0) n /= p, ++e;
    ans.push_back({p, e});
  }
  if (n != 1) ans.emplace_back(n, 1);
  return ans;
}

/// vector<ll>
vector<ll> facts(ll n) {
  vector<ll> ans;
  for (ll p = 2; p * p <= n; p++) {
    if (n % p != 0) continue;
    ll e = 0;
    while (n % p == 0) n /= p, ++e;
    rep(_, 0, e) ans.push_back(p);
  }
  if (n != 1) ans.push_back(n);
  return ans;
}

// 階乗
ll fact(ll n, ll mod) {
  ll ans = 1;
  for (ll m = 1; m <= n; m++) ans = ans * m % mod;
  return ans;
}

// 順列
ll npr(ll n, ll r) {
  ll ans = 1;
  rep(i, 0, r) ans *= (n - i);
  return ans;
}

// 組み合わせ
ll ncr(ll n, ll r) {
  if (r > n - r) r = n - r;
  ll ans = 1;
  rep(i, 0, r) ans *= (n - i) / (i + 1);
  return ans;
}

ll nc2(ll n) { return n * (n - 1) / 2; }

// 余りの計算
/// pow(a,b) % mod （繰り返し二乗法）
mint modpow(ll a, ll b) {
  mint x = a, ans = 1;
  while (b > 0) {
    if (b & 1) ans *= x;
    x *= x, b >>= 1;
  }
  return ans;
}

/// (a÷b) % mod
mint modinv(ll a, ll b) { return mint(a) * mint(b).inv(); }

/// 階乗: n!
mint modfact(int n) {
  mint ans = 1;
  rep(i, 1, n + 1) ans *= i;
  return ans;
}

/// 順列: nPr
mint modnpr(ll n, ll r) {
  mint ans = 1;
  rep(i, 0, r) ans *= (n - i);
  return ans;
}

/// 組み合わせ: nCr
mint modncr(ll n, ll r) {
  if (r < 0 or r > n) return 0;
  if (r > n - r) r = n - r;
  mint num = 1, den = 1;
  rep(i, 0, r) num *= (n - i), den *= (i + 1);
  return num / den;
}

/// 組み合わせ: nC2
mint modnc2(ll n) { return mint(n) * (n - 1) / 2; }

// 平方数判別
bool is_square(ll n) {
  for (ll i = 1; i * i <= n; i++) {
    if (i * i == n) return true;
  }
  return false;
}

// 進数変換 (10進->k進)
string to_base_k(ll n, int k) {
  if (n == 0) return "0";
  string ans = "";
  while (n > 0) ans += '0' + (n % k), n /= k;
  reverse(all(ans));
  return ans;
}

// 進数変換 (k進->10進)
ll to_base_10(string n, int k) {
  ll ans = 0;
  reverse(all(n));
  ll powk = 1;
  for (char c : n) {
    ans += (ll)(c - '0') * powk;
    powk *= k;
  }
  return ans;
}

// 各桁の和
int digit_sum(ll n) {
  int ans = 0;
  while (n > 0) ans += n % 10, n /= 10;
  return ans;
}

// 4 近傍（時計回り）
const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

// 8 近傍（時計回り）
const vector<int> di = {-1, -1, 0, 1, 1, 1, 0, -1};
const vector<int> dj = {0, 1, 1, 1, 0, -1, -1, -1};

// グリッド内判定（0-index）
bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

// 移動
void move(int x, int y, char c) {
  if (c == 'R') {
    x++;
  } else if (c == 'L') {
    x--;
  } else if (c == 'U') {
    y++;
  } else {
    y--;
  }
}

// 回文判定
bool is_pali(string s) {
  string t = s;
  reverse(all(t));
  return s == t;
}

// ランレングス圧縮（文字列）
vector<pair<char, int>> rle(string s) {
  vector<pair<char, int>> ans;
  int cnt = 1;
  char now = s[0];
  rep(i, 1, s.size()) {
    if (s[i] == now) {
      cnt++;
    } else {
      ans.push_back({now, cnt});
      now = s[i];
      cnt = 1;
    }
    ans.push_back({now, cnt});
    return ans;
  }
}

// ランレングス圧縮（整数配列）
vector<pii> rle(vector<int> xs) {
  vector<pii> ans;
  int cnt = 1, now = xs[0];
  rep(i, 1, xs.size()) {
    if (xs[i] == now) {
      cnt++;
    } else {
      ans.push_back({now, cnt});
      now = xs[i];
      cnt = 1;
    }
  }
  ans.push_back({now, cnt});
  return ans;
}

// 文字列中の文字の出現回数
int count_char(string s, char c) {
  int ans = 0;
  rep(i, 0, s.size()) if (s[i] == c) ans++;
  return ans;
}

// x 桁になるまで自然数 n を 文字 c で埋める
string padding(int x, int n, char c) {
  string s = to_string(n);
  return string(max(0, x - (int)s.size()), c) + s;
}

// x 桁になるまで文字列 s を 文字 c で埋める
string padding(int x, string s, char c) {
  return string(max(0, x - (int)s.size()), c) + s;
}

// ユークリッド距離の二乗
ll eudist(ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

// マンハッタン距離
ll mandist(ll x1, ll y1, ll x2, ll y2) { return abs(x1 - x2) + abs(y1 - y2); }

// ダイクストラ法
vector<ll> dijkstra(const vector<vector<pair<int, ll>>>& g, int s) {
  using pli = pair<ll, int>;
  rpq<pli> q;
  vector<ll> dist(g.size(), INF);
  dist[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : g[u]) {
      ll nd = d + w;
      if (nd < dist[v]) {
        dist[v] = nd;
        q.push({nd, v});
      }
    }
  }
  return dist;
}

// 二部グラフ判定（label の初期値は -1）
bool is_bipartite(const vector<vector<int>>& g, vector<int>& label) {
  int n = g.size();
  label.assign(n, -1);
  function<bool(int, int)> dfs = [&](int u, int l) {
    label[u] = l;
    for (int v : g[u]) {
      if (label[v] == l) return false;
      if (label[v] == -1 and !dfs(v, l ^ 1)) return false;
    }
    return true;
  };
  rep(i, 0, n) if (label[i] == -1 and !dfs(i, 0)) return false;
  return true;
}

// サイクル検出（無向グラフ）
bool has_cycle(vector<vector<int>>& g) {
  int n = g.size();
  dsu uf(n);
  rep(u, 0, n) {
    for (int v : g[u]) {
      if (u >= v) continue;
      if (uf.same(u, v)) return true;
      uf.merge(u, v);
    }
  }
  return false;
}

// サイクル検出（有効グラフ）
vector<int> detect_cycle(const vector<int>& g) {
  int v = 0;
  rep(i, 0, g.size()) v = g[v];
  vector<int> ans;
  int s = v;
  do {
    ans.push_back(v);
    v = g[v];
  } while (v != s);
  return ans;
}

// DAG 判定
bool is_dag(const vector<vector<int>>& g) {
  int n = g.size();
  vector<int> state(n, 0);
  auto dfs = [&](auto self, int u) -> bool {
    state[u] = 1;
    for (int v : g[u]) {
      if (state[v] == 1) return false;
      if (state[v] == 0 and !self(self, v)) return false;
    }
    state[u] = 2;
    return true;
  };
  rep(i, 0, n) if (state[i] == 0 and !dfs(dfs, i)) return false;
  return true;
}

// 0-indexed DAG トポロジカルソート（辞書順最小）
vector<int> topo_sort(const vector<vector<int>>& g) {
  int n = g.size();
  vector<int> indeg(n, 0);
  rep(u, 0, n) for (int v : g[u]) indeg[v]++;
  rpq<int> q;
  rep(u, 0, n) if (indeg[u] == 0) q.push(u);
  vector<int> ans;
  while (!q.empty()) {
    int u = q.top();
    q.pop();
    ans.push_back(u);
    for (int v : g[u]) {
      indeg[v]--;
      if (indeg[v] == 0) q.push(v);
    }
  }
  if (ans.size() != n) return {};
  return ans;
}

// ワーシャルフロイド法
vector<vector<ll>> warshall_floyd(const vector<vector<pair<int, ll>>>& g) {
  int n = g.size();
  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  rep(i, 0, n) dist[i][i] = 0;
  rep(i, 0, n) for (const auto& [v, w] : g[i]) chmin(dist[i][v], w);
  rep(k, 0, n) rep(i, 0, n) {
    if (dist[i][k] < INF) {
      rep(j, 0, n) {
        if (dist[k][j] < INF) chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}

// ans[i][c] := i 文字目以降で最初に文字 c が登場する index
// 存在しないときは N
// https://drken1215.hatenablog.com/entry/2021/10/10/195200
vector<vector<int>> calc_next(const string& s) {
  int n = (int)s.size();
  vector<vector<int>> ans(n + 1, vector<int>(26, n));
  rrep(i, 0, n) {
    ans[i] = ans[i + 1];
    ans[i][s[i] - 'a'] = i;
  }
  return ans;
}

// 文字列 s は文字列 t を部分列として持つか？
bool has_subsequence(const string& s, const string& t) {
  int pos = 0, n = s.size(), m = t.size();
  rep(i, 0, m) {
    while (pos < n and s[pos] != t[i]) pos++;
    if (pos == n) return false;
    pos++;
  }
  return true;
}

// 文字列 s は文字列 t を部分文字列として持つか？
bool has_substring(const string& s, const string& t) {
  return s.find(t) != string::npos;
}

// floor(sqrt(x))
ll sqrt_floor(const ll& x) {
  ll ans = sqrt((ld)x);
  while ((ans + 1) <= x / (ans + 1)) ans++;
  while (ans > x / ans) ans--;
  return ans;
}

// 区間 [l,r] の平方数の個数
ll cnt_sqr(ll l, ll r) { return sqrt_floor(r) - sqrt_floor(l - 1); }