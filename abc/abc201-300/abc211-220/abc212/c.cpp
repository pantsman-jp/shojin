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
  vector<int> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  sort(all(a)), sort(all(b));
  int ans = 1e9, i = 0, j = 0;
  while ((i < n) and (j < m))
  {
    ans = min(ans, abs(a[i] - b[j]));
    if (a[i] > b[j])
      j++;
    else
      i++;
  }
  cout << ans << endl;
}