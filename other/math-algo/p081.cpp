#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, ans = 0;
  cin >> n;
  for (int x : {10000, 5000, 1000})
    ans += n / x, n -= (n / x) * x;
  cout << ans << endl;
}