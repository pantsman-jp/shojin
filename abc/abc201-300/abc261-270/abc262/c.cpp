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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i], a[i]--;
  ll cnt = 0;
  rep(i, 0, n) if (a[i] == i) cnt++;
  ll ans = cnt * (cnt - 1) / 2;
  rep(i, 0, n)
  {
    if (a[i] <= i)
      continue;
    if (a[a[i]] == i)
      ans++;
  }
  cout << ans << endl;
}