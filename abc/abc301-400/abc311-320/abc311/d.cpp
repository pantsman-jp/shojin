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
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// const ll mod = 998244353;
// const ll mod = 1000000007;

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

int n, m;
vector<string> s;
vector<vector<bool>> seen, is_start;

bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

void dfs(int i, int j)
{
  if (is_start[i][j])
    return;
  is_start[i][j] = true;
  seen[i][j] = true;
  rep(d, 0, 4)
  {
    int ni = i, nj = j;
    while (s[ni + di[d]][nj + dj[d]] == '.')
    {
      ni += di[d];
      nj += dj[d];
      seen[ni][nj] = true;
    }
    dfs(ni, nj);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  s.resize(n);
  rep(i, 0, n) cin >> s[i];
  seen.resize(n, vector<bool>(m));
  is_start.resize(n, vector<bool>(m));
  dfs(1, 1);
  int ans = 0;
  rep(i, 0, n) rep(j, 0, m) if (seen[i][j]) ans++;
  cout << ans << endl;
}