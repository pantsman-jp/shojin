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
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];
  int ans = 1;
  rep(i, 1, n)
  {
    bool ok = true;
    rep(j, 0, i)
    {
      if (h[j] > h[i])
      {
        ok = false;
        break;
      }
    }
    if (ok)
      ans++;
  }
  cout << ans << endl;
}