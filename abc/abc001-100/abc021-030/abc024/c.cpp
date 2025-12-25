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
  int n, d, k;
  cin >> n >> d >> k;
  vector<int> l(d), r(d), s(k), t(k);
  rep(i, 0, d) cin >> l[i] >> r[i];
  rep(i, 0, k) cin >> s[i] >> t[i];
  vector<int> ans(k);
  rep(i, 0, d) rep(j, 0, k)
  {
    if (l[i] <= s[j] and s[j] <= r[i])
    {
      if (s[j] < t[j])
      {
        s[j] = min(t[j], r[i]);
        if (s[j] == t[j])
          ans[j] = i + 1;
      }
      else if (s[j] > t[j])
      {
        s[j] = max(t[j], l[i]);
        if (s[j] == t[j])
          ans[j] = i + 1;
      }
    }
  }
  rep(i, 0, k) cout << ans[i] << endl;
}