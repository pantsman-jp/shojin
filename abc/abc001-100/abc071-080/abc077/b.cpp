#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool is_square(ll n)
{
  for (ll i = 1; i * i <= n; i++)
    if (i * i == n)
      return true;
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  while (true)
  {
    if (is_square(n))
    {
      cout << n << endl;
      return 0;
    }
    n--;
  }
}