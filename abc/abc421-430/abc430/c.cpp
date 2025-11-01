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
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  vector<int> suma(n + 1), sumb(n + 1);
  suma[0] = 0, sumb[0] = 0;
  rep(i, 0, n)
  {
    suma[i + 1] = suma[i];
    sumb[i + 1] = sumb[i];
    if (s[i] == 'a')
      suma[i + 1]++;
    else
      sumb[i + 1]++;
  }
  ll ans = 0, la = 1, lb = 1;
  rep(r, 1, n + 1)
  {
    while (la <= r and suma[r] - suma[la - 1] >= a)
      la++;
    while (lb <= r and sumb[r] - sumb[lb - 1] >= b)
      lb++;
    if (la > lb)
      ans += la - lb;
  }
  cout << ans << endl;
}