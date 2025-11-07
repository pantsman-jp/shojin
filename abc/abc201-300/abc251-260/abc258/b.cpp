#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> dx = {1, 1, 1, 0, 0, -1, -1, -1}, dy = {1, 0, -1, 1, -1, 1, 0, -1};

int main()
{
  int n;
  cin >> n;
  ll ans = 0;
  vector<vector<ll>> a(n, vector<ll>(n));
  rep(i, 0, n) rep(j, 0, n)
  {
    char c;
    cin >> c;
    a[i][j] = c - '0';
  }
  rep(i, 0, n) rep(j, 0, n)
  {
    for (int k = 0; k < 8; k++)
    {
      ll tmp = 0, x = i, y = j;
      for (int l = 0; l < n; l++)
      {
        tmp *= 10;
        tmp += a[x][y];
        x += dx[k], y += dy[k];
        x %= n, x += n;
        y %= n, y += n;
        x %= n, y %= n;
      }
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}