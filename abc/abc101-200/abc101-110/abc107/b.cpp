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
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h) cin >> a[i];
  vector<bool> row(h, true), line(w, true);
  rep(i, 0, h)
  {
    bool dlt = true;
    rep(j, 0, w)
    {
      if (a[i][j] == '#')
      {
        dlt = false;
        break;
      }
    }
    if (dlt)
      row[i] = false;
  }
  rep(j, 0, w)
  {
    bool dlt = true;
    rep(i, 0, h)
    {
      if (a[i][j] == '#')
      {
        dlt = false;
        break;
      }
    }
    if (dlt)
      line[j] = false;
  }
  rep(i, 0, h)
  {
    if (!row[i])
      continue;
    rep(j, 0, w) if (line[j]) cout << a[i][j];
    cout << endl;
  }
}