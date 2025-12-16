#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool is_prime(int n)
{
  if (n < 2)
    return false;
  for (ll i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

int solve(int x)
{
  if (is_prime(x))
    return x;
  if (x % 2 == 0)
    return solve(x + 1);
  return solve(x + 2);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x;
  cin >> x;
  cout << solve(x) << endl;
}