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
  int n, m, t;
  cin >> n >> m >> t;
  vector<int> a(m), b(m);
  rep(i, 0, m) cin >> a[i] >> b[i];
  int batt = n;
  batt -= a[0];
  if (batt <= 0)
  {
    cout << "No" << endl;
    ;
    return 0;
  }
  rep(i, 0, m)
  {
    batt += b[i] - a[i];
    if (batt > n)
      batt = n;
    if (i + 1 < m)
    {
      batt -= a[i + 1] - b[i];
      if (batt <= 0)
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  batt -= t - b[m - 1];
  if (batt > 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}