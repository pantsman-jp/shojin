#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int solve()
{
  ll n;
  cin >> n;
  vector<ll> s(n);
  rep(i, 0, n) cin >> s[i];
  if (s.back() <= 2 * s[0])
    return 2;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  rep(ti, 0, t) cout << solve() << endl;
}