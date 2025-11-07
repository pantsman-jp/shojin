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
  int k;
  cin >> x >> k;
  ll pow10 = 1;
  rep(i, 0, k)
  {
    ll t = pow10 * 10;
    x = (x + pow10 * 5) / t * t, pow10 *= 10;
  }
  cout << x << endl;
}