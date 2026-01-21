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
// const ll mod = 998244353;
// const ll mod = 1000000007;

int h, w, k;
vector<string> s;
vector<vector<bool>> seen;

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int dfs(int i, int j, int cnt)
{
  if (cnt == k)
    return 1;
  int ans = 0;
  seen[i][j] = true;
  rep(d, 0, 4)
  {
    int ni = i + di[d], nj = j + dj[d];
    if (out(ni, nj, h, w) or s[ni][nj] == '#' or seen[ni][nj])
      continue;
    ans += dfs(ni, nj, cnt + 1);
  }
  seen[i][j] = false;
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w >> k;
  s.resize(h), seen.resize(h, vector<bool>(w));
  rep(i, 0, h) cin >> s[i];
  ll ans = 0;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '.') ans += dfs(i, j, 0);
  cout << ans << endl;
}