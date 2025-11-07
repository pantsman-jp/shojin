#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> c(n), d(m);
  vector<int> p(m + 1);
  rep(i, n) { cin >> c[i]; }
  rep(i, m) { cin >> d[i]; }
  rep(i, m + 1) { cin >> p[i]; }
  int ans = 0;
  for (string color : c)
  {
    auto i = find(d.begin(), d.end(), color);
    if (i == d.end())
      ans += p[0];
    else
      ans += p[distance(d.begin(), i) + 1];
  }
  cout << ans << endl;
}
