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

ll nc2(ll n)
{
  return n * (n - 1) / 2;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  vector<vector<int>> x(n + 1, vector<int>(10));
  rep(i, 0, n)
  {
    x[i + 1] = x[i];
    x[i + 1][s[i] - '0'] ^= 1;
  }
  map<vector<int>, int> cnt;
  rep(i, 0, n + 1) cnt[x[i]]++;
  ll ans = 0;
  for (auto [_, c] : cnt)
    ans += nc2(c);
  cout << ans << endl;
}