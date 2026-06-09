#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  double ans = 0;
  rep(_, n)
  {
    double p, q;
    cin >> p >> q;
    ans += q / p;
  }
  cout << fixed << setprecision(10) << ans << endl;
}
