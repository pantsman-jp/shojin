#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

ll calc(ll a, ll b, ll c, ll x)
{
  return (x / (a + c) * a + min(a, x % (a + c))) * b;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c, d, e, f, x;
  cin >> a >> b >> c >> d >> e >> f >> x;
  ll tak = calc(a, b, c, x), aok = calc(d, e, f, x);
  if (tak > aok)
    cout << "Takahashi" << endl;
  else if (tak < aok)
    cout << "Aoki" << endl;
  else
    cout << "Draw" << endl;
}