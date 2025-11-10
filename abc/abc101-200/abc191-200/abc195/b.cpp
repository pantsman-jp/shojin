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
  int a, b, w;
  cin >> a >> b >> w;
  int ans1 = 1e9, ans2 = 0;
  rep(n, 1, 1000001) if (a * n <= 1000 * w and 1000 * w <= b * n) ans1 = min(ans1, n), ans2 = max(ans2, n);
  if (ans2 == 0)
    cout << "UNSATISFIABLE";
  else
    cout << ans1 << ' ' << ans2 << endl;
}