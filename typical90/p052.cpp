#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ll ans = 1;
  rep(i, 0, n)
  {
    int sum = 0;
    rep(j, 0, 6)
    {
      int a;
      cin >> a;
      sum += a;
    }
    ans = (ans * sum) % 1000000007;
  }
  cout << ans << endl;
}
