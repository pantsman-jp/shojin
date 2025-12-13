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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  int ans = 1 << 30;
  rep(bit, 0, 1 << (n - 1))
  {
    int now = 0, o = 0;
    rep(i, 0, n)
    {
      o |= a[i];
      if (bit >> i & 1)
        now ^= o, o = 0;
    }
    now ^= o;
    ans = min(ans, now);
  }
  cout << ans << endl;
}