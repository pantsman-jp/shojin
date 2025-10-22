#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  vector<ll> fib(n + 1);
  fib[1] = fib[2] = 1;
  for (ll i = 3; i < n + 1; i++)
    fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000007;
  cout << fib[n] % 1000000007 << endl;
}
