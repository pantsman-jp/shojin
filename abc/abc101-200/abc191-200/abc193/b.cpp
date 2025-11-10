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
  ll ans = inf;
  rep(i, 0, n)
  {
    ll a, p, x;
    cin >> a >> p >> x;
    if (x > a and p < ans)
      ans = p;
  }
  if (ans == inf)
    ans = -1;
  cout << ans << endl;
}