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
  ll n, m;
  cin >> n >> m;
  if (n > m)
    swap(n, m);
  ll ans;
  if (n == 1)
  {
    if (m == 1)
      ans = 1;
    else
      ans = m - 2;
  }
  else
    ans = (n - 2) * (m - 2);
  cout << ans << endl;
}