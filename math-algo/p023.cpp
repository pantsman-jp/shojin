#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  double b = 0, r = 0;
  rep(i, n)
  {
    int x;
    cin >> x;
    b += x;
  }
  rep(i, n)
  {
    int x;
    cin >> x;
    r += x;
  }
  cout << fixed << setprecision(10) << (b + r) / n << endl;
}
