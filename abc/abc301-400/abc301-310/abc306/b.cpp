#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
  ull ans = 0, base = 1;
  rep(_, 64)
  {
    int a;
    cin >> a;
    ans += a * base;
    base *= 2;
  }
  cout << ans << endl;
}
