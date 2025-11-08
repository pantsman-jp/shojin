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
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  rep(i, 0, n)
  {
    a[i].resize(i + 1);
    rep(j, 0, i + 1)
    {
      if (j == 0 or j == i)
        a[i][j] = 1;
      else
        a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
  }
  rep(i, 0, n)
  {
    rep(j, 0, i + 1) cout << a[i][j] << ' ';
    cout << endl;
  }
}