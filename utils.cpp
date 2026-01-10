#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;

// 素数判定
bool is_prime(ll n)
{
  if (n < 2)
    return false;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

// 素数列挙
vector<ll> primes(ll n)
{
  vector<bool> prime(n + 2, true);
  prime[0] = prime[1] = false;
  for (ll i = 2; i * i <= n; i++)
  {
    if (prime[i])
    {
      for (ll x = i * i; x <= n; x += i)
        prime[x] = false;
    }
  }
  vector<ll> ans;
  for (ll i = 2; i <= n; i++)
  {
    if (prime[i])
      ans.push_back(i);
  }
  return ans;
}

// 約数列挙
vector<ll> divisors(ll n)
{
  vector<ll> ans;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i != 0)
      continue;
    ans.push_back(i);
    if (i != n / i)
      ans.push_back(n / i);
  }
  sort(all(ans));
  return ans;
}

// 素因数分解
vector<ll> factorization(ll n)
{
  vector<ll> ans;
  for (ll i = 2; i * i <= n; i++)
    while (n % i == 0)
      ans.push_back(i), n /= i;
  if (n > 1)
    ans.push_back(n);
  return ans;
}

// 最大公約数
ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// 最小公倍数
ll lcm(ll a, ll b)
{
  return a / gcd(a, b) * b;
}

// 最大公約数（配列）
ll gcd_all(vector<ll> xs)
{
  ll ans = xs[0];
  rep(i, 1, xs.size()) ans = gcd(ans, xs[i]);
  return ans;
}

// 最小公倍数（配列）
ll lcm_all(vector<ll> xs)
{
  ll ans = xs[0];
  rep(i, 1, xs.size()) ans = ans / gcd(ans, xs[i]) * xs[i];
  return ans;
}

// 階乗
ll fact(ll n, ll mod)
{
  ll ans = 1;
  for (ll m = 1; m <= n; m++)
    ans = ans * m % mod;
  return ans;
}

// 順列
ll npr(ll n, ll r)
{
  ll ans = 1;
  rep(i, 0, r) ans *= (n - i);
  return ans;
}

// 組み合わせ
ll ncr(ll n, ll r)
{
  if (r > n - r)
    r = n - r;
  ll ans = 1;
  rep(i, 0, r) ans = ans * (n - i) / (i + 1);
  return ans;
}

// 巨大素数の余りの計算(modpow は 繰り返し二乗法 pow(a,b)(mod m), div は a÷b(mod m) を計算する)
ll modpow(ll a, ll b, ll mod)
{
  ll ans = 1;
  while (b > 0)
  {
    if ((b & 1) != 0)
      ans = ans * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return ans;
}

ll div(ll a, ll b, ll m) { return (a * modpow(b, m - 2, m)) % m; }

// 平方数判別
bool is_square(ll n)
{
  for (ll i = 1; i * i <= n; i++)
    if (i * i == n)
      return true;
  return false;
}

// 進数変換 (10進->k進)
string to_base_k(ll n, int k)
{
  if (n == 0)
    return "0";
  string ans = "";
  while (n > 0)
    ans += '0' + (n % k), n /= k;
  reverse(all(ans));
  return ans;
}

// 各桁の和
int digit_sum(ll n)
{
  int ans = 0;
  while (n > 0)
    ans += n % 10, n /= 10;
  return ans;
}

// 桁数
int digit(ll n)
{
  return to_string(n).size();
}

// 4 近傍（時計回り）
const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

// 8 近傍（時計回り）
const vector<int> di = {-1, -1, 0, 1, 1, 1, 0, -1};
const vector<int> dj = {0, 1, 1, 1, 0, -1, -1, -1};

// グリッド内判定（0-index）
bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

// 移動
void move(int x, int y, char c)
{
  if (c == 'R')
    x++;
  else if (c == 'L')
    x--;
  else if (c == 'U')
    y++;
  else
    y--;
}

// 回文判定
bool is_pali(string s)
{
  string t = s;
  reverse(all(t));
  return s == t;
}

// ラングレス圧縮
// string rl(string s)
// {
//   int cnt = 1;
//   string ans;
//   rep(i, 0, s.size())
//   {
//     if (i + 1 < s.size() and s[i] == s[i + 1])
//       cnt++;
//     else
//       ans += string(1, s[i]) + to_string(cnt), cnt = 1;
//   }
//   return ans;
// }

vector<pair<char, int>> rle(string s)
{
  vector<pair<char, int>> ans;
  int cnt = 1;
  char now = s[0];
  rep(i, 1, s.size())
  {
    if (s[i] == now)
      cnt++;
    else
      ans.push_back({now, cnt}), now = s[i], cnt = 1;
  }
  ans.push_back({now, cnt});
  return ans;
}

// 文字列中の文字の出現回数
int count_char(string s, char c)
{
  int ans = 0;
  rep(i, 0, s.size()) if (s[i] == c) ans++;
  return ans;
}

// i 番目のアルファベット (0-index)
char ith_alph(int i)
{
  return 'a' + i;
}

// x 桁になるまで自然数 n を 文字 c で埋める
string pad(int x, int n, char c)
{
  string s = to_string(n);
  return string(max(0, x - (int)s.size()), c) + s;
}

// ユークリッド距離の二乗
ll eudistance(ll x1, ll y1, ll x2, ll y2)
{
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

// マンハッタン距離
ll mandistance(ll x1, ll y1, ll x2, ll y2)
{
  return abs(x1 - x2) + abs(y1 - y2);
}
