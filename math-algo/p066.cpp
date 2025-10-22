#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n, k;
  cin >> n >> k;
  ll other = 0;
  for (ll a = 1; a < n + 1; a++)
    for (ll b = max(1LL, a - k + 1); b < min(n, a + k - 1) + 1; b++)
      for (ll c = max(1LL, a - k + 1); c < min(n, a + k - 1) + 1; c++)
        if (abs(b - c) <= k - 1)
          other++;
  cout << n * n * n - other << endl;
}
