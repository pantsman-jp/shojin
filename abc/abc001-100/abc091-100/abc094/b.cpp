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
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> a(m);
  rep(i, 0, m) cin >> a[i];
  int ans = 0;
  rep(i, 0, m) if (a[i] < x) ans++;
  ans = min(ans, m - ans);
  cout << ans << endl;
}