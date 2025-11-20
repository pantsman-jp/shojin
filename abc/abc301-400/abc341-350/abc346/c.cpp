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
  ll n, k;
  cin >> n >> k;
  set<ll> s;
  rep(_, 0, n)
  {
    ll a;
    cin >> a;
    if (a <= k)
      s.insert(a);
  }
  cout << k * (k + 1) / 2 - reduce(all(s)) << endl;
}