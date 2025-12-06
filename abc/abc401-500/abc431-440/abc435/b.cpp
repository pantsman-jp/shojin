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
  vector<int> a(n), sum(n + 1);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) sum[i + 1] = sum[i] + a[i];
  int ans = 0;
  rep(l, 0, n) rep(r, l, n)
  {
    int total = sum[r + 1] - sum[l];
    bool ok = true;
    rep(i, l, r + 1)
    {
      if (total % a[i] == 0)
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