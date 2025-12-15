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
  vector<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n)
  {
    if ((x[k] - x[j]) * (y[j] - y[i]) == (x[j] - x[i]) * (y[k] - y[j]))
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}