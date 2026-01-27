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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector ans(n, vector<string>(n));
  int c = n / 2;
  ans[c][c] = "T";
  int top = 0, bottom = n - 1, left = 0, right = n - 1;
  int cur = 1;
  while (top <= bottom and left <= right)
  {
    rep(j, left, right + 1)
    {
      if (top == c and j == c)
        continue;
      ans[top][j] = to_string(cur++);
    }
    top++;
    rep(i, top, bottom + 1)
    {
      if (i == c and right == c)
        continue;
      ans[i][right] = to_string(cur++);
    }
    right--;
    if (top <= bottom)
    {
      rrep(j, left, right + 1)
      {
        if (bottom == c and j == c)
          continue;
        ans[bottom][j] = to_string(cur++);
      }
      bottom--;
    }
    if (left <= right)
    {
      rrep(i, top, bottom + 1)
      {
        if (i == c and left == c)
          continue;
        ans[i][left] = to_string(cur++);
      }
      left++;
    }
  }
  rep(i, 0, n)
  {
    rep(j, 0, n) cout << ans[i][j] << " ";
    cout << endl;
  }
}