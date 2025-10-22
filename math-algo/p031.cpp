#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n + 1), dp1(n + 1), dp2(n + 1);
  for (int i = 1; i < n + 1; i++)
    cin >> a[i];
  for (int i = 1; i < n + 1; i++)
  {
    dp1[i] = dp2[i - 1] + a[i];
    dp2[i] = max(dp1[i - 1], dp2[i - 1]);
  }
  cout << max(dp1[n], dp2[n]) << endl;
}
