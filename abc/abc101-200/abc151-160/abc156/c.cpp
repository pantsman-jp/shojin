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
  vector<int> x(n);
  rep(i, 0, n) cin >> x[i];
  sort(all(x));
  int ans = 1e9;
  rep(p, x[0], x[n - 1] + 1)
  {
    int cost = 0;
    rep(i, 0, n) cost += (x[i] - p) * (x[i] - p);
    ans = min(ans, cost);
  }
  cout << ans << endl;
}