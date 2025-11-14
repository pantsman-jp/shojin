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
  int a, b, c, x, ans = 0;
  cin >> a >> b >> c >> x;
  rep(i, 0, a + 1) rep(j, 0, b + 1) rep(k, 0, c + 1) if (500 * i + 100 * j + 50 * k == x) ans++;
  cout << ans << endl;
}