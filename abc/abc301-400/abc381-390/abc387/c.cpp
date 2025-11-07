#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

ll pw(ll x, int p)
{
  ll res = 1;
  rep(i, 0, p) res *= x;
  return res;
}

ll f(ll r)
{
  r++;
  vector<int> digits;
  for (char c : to_string(r))
    digits.push_back(c - '0');
  int n = digits.size();
  ll res = 0;
  rep(k, 1, n) rep(h, 1, 10) res += pw(h, k - 1);
  rep(h, 1, digits[0]) res += pw(h, n - 1);
  int h = digits[0];
  rep(i, 1, n)
  {
    if (digits[i] >= h)
    {
      res += pw(h, n - i);
      break;
    }
    res += pw(h, n - i - 1) * digits[i];
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll l, r;
  cin >> l >> r;
  cout << f(r) - f(l - 1) << endl;
}