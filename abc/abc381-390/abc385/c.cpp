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
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];
  int ans = 1;
  rep(d, 1, n)
  {
    rep(r, 0, d)
    {
      int num = 1, prev = -1;
      for (int i = r; i < n; i += d)
      {
        if (h[i] == prev)
          num++, ans = max(ans, num);
        else
          num = 1, prev = h[i];
      }
    }
  }
  cout << ans << endl;
}