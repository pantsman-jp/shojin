#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  double ans = 0;
  for (int i = 1; i < n + 1; i++)
    ans += 1.0 / i;
  cout << fixed << setprecision(10) << n * ans << endl;
}
