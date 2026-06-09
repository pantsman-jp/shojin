#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll nc2(ll n)
{
  return n * (n - 1) / 2;
}

int main()
{
  ll n;
  cin >> n;
  vector<ll> c(3);
  rep(_, n)
  {
    int a;
    cin >> a;
    c[a - 1]++;
  }
  cout << nc2(c[0]) + nc2(c[1]) + nc2(c[2]) << endl;
}
