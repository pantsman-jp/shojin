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
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  int ans = 0;
  rep(i, 0, n) if (a[i] == b[i]) ans++;
  cout << ans << endl;
  ans = 0;
  rep(i, 0, n) rep(j, 0, n)
  {
    if (i == j)
      continue;
    if (a[i] == b[j])
      ans++;
  }
  cout << ans << endl;
}