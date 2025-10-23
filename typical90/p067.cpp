#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

ll str8_to_long10(string n)
{
  ll ans = 0;
  rep(i, 0, n.size()) { ans = ans * 8 + int(n[i] - '0'); }
  return ans;
}

string long10_to_str9(ll n)
{
  if (n == 0)
    return "0";
  string ans;
  while (n > 0)
    ans = char(n % 9 + '0') + ans, n /= 9;
  return ans;
}

int main()
{
  string n;
  int k;
  cin >> n >> k;
  rep(i, 0, k)
  {
    n = long10_to_str9(str8_to_long10(n));
    rep(j, 0, n.size())
    {
      if (n[j] == '8')
        n[j] = '5';
    }
  }
  cout << n << endl;
}