#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

ll lcm_all(vector<ll> xs)
{
  ll ans = xs[0];
  rep(i, 1, xs.size()) ans = ans / gcd(ans, xs[i]) * xs[i];
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> t(n);
  rep(i, 0, n) cin >> t[i];
  cout << lcm_all(t) << endl;
}