#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> x(n, vector<bool>(n)), y(n, vector<bool>(n));
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    x[a][b] = x[b][a] = true;
  }
  rep(i, 0, m)
  {
    int c, d;
    cin >> c >> d;
    c--, d--;
    y[c][d] = y[d][c] = true;
  }
  vector<int> p(n);
  rep(i, 0, n) p[i] = i;
  do
  {
    bool ok = true;
    rep(i, 0, n) rep(j, 0, n) if (x[i][j] != y[p[i]][p[j]]) ok = false;
    if (ok)
    {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(all(p)));
  cout << "No" << endl;
}