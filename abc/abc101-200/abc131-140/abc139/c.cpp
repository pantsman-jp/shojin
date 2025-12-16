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
  int ans = 0, cnt = 0;
  rep(i, 0, n - 1)
  {
    if (h[i + 1] <= h[i])
      cnt++, ans = max(ans, cnt);
    else
      cnt = 0;
  }
  cout << ans << endl;
}