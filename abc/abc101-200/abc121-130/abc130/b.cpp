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
  int n, x;
  cin >> n >> x;
  vector<int> l(n + 1), d(n + 1);
  rep(i, 1, n + 1) cin >> l[i];
  d[1] = 0;
  rep(i, 2, n + 2) d[i] = d[i - 1] + l[i - 1];
  int ans = 0;
  rep(i, 1, n + 2) if (d[i] <= x) ans++;
  cout << ans << endl;
}