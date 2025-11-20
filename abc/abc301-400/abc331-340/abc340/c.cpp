#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

map<ll, ll> memo;

ll f(ll n)
{
  if (n == 1)
    return 0;
  if (memo[n] != 0)
    return memo[n];
  return memo[n] = f(n / 2) + f((n + 1) / 2) + n;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  cout << f(n) << endl;
}