#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  double sum_a = 0, sum_b = 0;
  rep(_, n)
  {
    double a;
    cin >> a;
    sum_a += a;
  }
  rep(_, n)
  {
    double b;
    cin >> b;
    sum_b += b;
  }
  cout << fixed << setprecision(10) << sum_a / 3 + 2 * sum_b / 3 << endl;
}
