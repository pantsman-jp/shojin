#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

ll ncr(ll n, ll r)
{
  if (r > n - r)
    r = n - r;
  ll ans = 1;
  rep(i, 0, r) ans = ans * (n - i) / (i + 1);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll l;
  cin >> l;
  cout << ncr(l - 1, 11) << endl;
}