#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, ans = 0;
  cin >> n;
  rep(i, 1, n + 1) if (i % 3 != 0 and i % 5 != 0) ans += i;
  cout << ans << endl;
}