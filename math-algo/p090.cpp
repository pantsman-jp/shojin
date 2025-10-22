#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x, ans = 0;
  cin >> n >> x;
  rep(a, 1, n + 1)
  {
    rep(b, a + 1, n + 1)
    {
      int c = x - a - b;
      if (b < c and c <= n)
        ans++;
    }
  }
  cout << ans << endl;
}