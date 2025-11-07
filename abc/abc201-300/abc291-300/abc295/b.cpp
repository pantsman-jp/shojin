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
  int r, c;
  cin >> r >> c;
  vector<string> b(r);
  rep(i, 0, r) cin >> b[i];
  rep(i, 0, r)
  {
    rep(j, 0, c)
    {
      char x = b[i][j];
      rep(i2, 0, r) rep(j2, 0, r)
      {
        int d;
        if (isdigit(b[i2][j2]))
          d = b[i2][j2] - '0';
        else
          d = -1;
        if (abs(i - i2) + abs(j - j2) <= d)
          x = '.';
      }
      cout << x;
    }
    cout << endl;
  }
}