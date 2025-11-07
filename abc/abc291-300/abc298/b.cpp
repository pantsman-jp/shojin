#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool check(int n, vector<vector<int>> &a, vector<vector<int>> &b)
{
  rep(i, 0, n) rep(j, 0, n) if (a[i][j] == 1 && b[i][j] != 1) return false;
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
  rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
  rep(i, 0, n) rep(j, 0, n) cin >> b[i][j];
  rep(k, 0, 4)
  {
    if (check(n, a, b))
    {
      cout << "Yes" << endl;
      return 0;
    }
    vector<vector<int>> c(n, vector<int>(n));
    rep(i, 0, n) rep(j, 0, n) c[j][n - 1 - i] = a[i][j];
    a = c;
  }
  cout << "No" << endl;
}