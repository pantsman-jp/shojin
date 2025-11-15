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
  ll a, b, x;
  cin >> a >> b >> x;
  if (a == 0)
    cout << b / x + 1 << endl;
  else
    cout << b / x - (a - 1) / x << endl;
}