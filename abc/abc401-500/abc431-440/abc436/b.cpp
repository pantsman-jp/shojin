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
  vector a(n, vector<int>(n));
  int r = 0, c = (n - 1) / 2, k = 1;
  a[r][c] = k;
  rep(_, 0, n * n - 1)
  {
    if (a[(r - 1 + n) % n][(c + 1) % n] == 0)
    {
      a[(r - 1 + n) % n][(c + 1) % n] = k + 1;
      r = (r - 1 + n) % n, c = (c + 1) % n;
    }
    else
    {
      a[(r + 1) % n][c] = k + 1;
      r = (r + 1) % n;
    }
    k++;
  }
  rep(i, 0, n)
  {
    rep(j, 0, n) cout << a[i][j] << ' ';
    cout << endl;
  }
}