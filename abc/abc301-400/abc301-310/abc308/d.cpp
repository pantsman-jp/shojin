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

int h, w;
vector<string> s;
vector<vector<bool>> seen;

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

char next(char c)
{
  if (c == 's')
    return 'n';
  if (c == 'n')
    return 'u';
  if (c == 'u')
    return 'k';
  if (c == 'k')
    return 'e';
  return 's';
}

bool dfs(int i, int j)
{
  if (i == h - 1 and j == w - 1)
    return true;
  seen[i][j] = true;
  rep(d, 0, 4)
  {
    int ni = i + di[d], nj = j + dj[d];
    if (out(ni, nj, h, w) or seen[ni][nj] or next(s[i][j]) != s[ni][nj])
      continue;
    if (dfs(ni, nj))
      return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w;
  s.resize(h);
  rep(i, 0, h) cin >> s[i];
  seen.resize(h, vector<bool>(w));
  yn(s[0][0] == 's' and dfs(0, 0));
}