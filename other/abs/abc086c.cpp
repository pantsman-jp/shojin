#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  vector<int> t(n + 1), x(n + 1), y(n + 1);
  t[0] = 0, x[0] = 0, y[0] = 0;
  for (int i = 1; i <= n; i++)
    cin >> t[i] >> x[i] >> y[i];
  rep(i, n)
  {
    int dt = t[i + 1] - t[i], dx = abs(x[i + 1] - x[i]), dy = abs(y[i + 1] - y[i]);
    if (dx + dy > dt or (dx + dy) % 2 != dt % 2)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
