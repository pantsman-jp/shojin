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
  int m, ans = 1e9;
  string s1, s2, s3;
  cin >> m >> s1 >> s2 >> s3;
  rep(i, 0, 3 * m) rep(j, 0, 3 * m) rep(k, 0, 3 * m)
  {
    if (i != j and i != k and j != k and s1[i % m] == s2[j % m] and s2[j % m] == s3[k % m])
      ans = min(ans, max(i, max(j, k)));
  }
  if (ans < 1e9)
    cout << ans << endl;
  else
    cout << -1 << endl;
}