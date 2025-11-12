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
  int k, x;
  cin >> k >> x;
  bool isTop = true;
  rep(ans, -1e6, 1e6 + 1) if (abs(ans - x) < k) cout << ans << ' ';
  cout << endl;
}