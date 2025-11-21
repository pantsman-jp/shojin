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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
  int ans = -1;
  rep(i, 0, n)
  {
    int j = lower_bound(all(a), a[i] + m) - a.begin() - 1;
    ans = max(ans, j - i + 1);
  }
  cout << ans << endl;
}