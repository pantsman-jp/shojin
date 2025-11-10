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
  int s, t, ans = 0;
  cin >> s >> t;
  rep(a, 0, s + 1) rep(b, 0, s - a + 1) rep(c, 0, s - a - b + 1) if (a * b * c <= t) ans++;
  cout << ans << endl;
}