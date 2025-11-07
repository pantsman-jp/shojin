#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int a, b, sum_a = 0, sum_b = 0;
  rep(_, 9)
  {
    cin >> a;
    sum_a += a;
  }
  rep(_, 8)
  {
    cin >> b;
    sum_b += b;
  }
  cout << sum_a - sum_b + 1 << endl;
}
