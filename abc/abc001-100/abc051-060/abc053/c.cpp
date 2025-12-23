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
  ll x;
  cin >> x;
  ll ans = x / 11 * 2, r = x % 11;
  if (r > 0)
    ans++;
  if (r > 6)
    ans++;
  cout << ans << endl;
}