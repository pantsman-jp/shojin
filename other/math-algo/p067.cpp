#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll h, w;
  cin >> h >> w;
  vector<vector<ll>> a(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> a[i][j];
  vector<ll> row(h), line(w);
  rep(i, h) row[i] = accumulate(a[i].begin(), a[i].end(), 0LL);
  rep(j, w) rep(i, h) line[j] += a[i][j];
  rep(i, h)
  {
    rep(j, w) { cout << row[i] + line[j] - a[i][j] << ' '; }
    cout << endl;
  }
}
