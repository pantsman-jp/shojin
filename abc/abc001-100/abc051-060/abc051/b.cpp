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
  int k, s;
  cin >> k >> s;
  int ans = 0;
  rep(x, 0, k + 1) rep(y, 0, k + 1)
  {
    int z = s - x - y;
    if (0 <= z and z <= k)
      ans++;
  }
  cout << ans << endl;
}