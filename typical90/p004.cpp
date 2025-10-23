#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  vector<int> row(h), line(w);
  rep(i, 0, h) row[i] = reduce(all(a[i]));
  rep(j, 0, w) rep(i, 0, h) line[j] += a[i][j];
  rep(i, 0, h)
  {
    rep(j, 0, w) { cout << row[i] + line[j] - a[i][j] << ' '; }
    cout << endl;
  }
}
