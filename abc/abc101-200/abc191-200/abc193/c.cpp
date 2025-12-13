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
  ll n;
  cin >> n;
  set<ll> ab;
  for (ll a = 2; a * a <= n; a++)
  {
    ll m = a * a;
    while (m <= n)
      ab.insert(m), m *= a;
  }
  cout << n - ab.size() << endl;
}