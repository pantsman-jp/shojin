#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, m, p;
  cin >> n >> m >> p;
  int ans = 0;
  while (m <= n)
    ans++, m += p;
  cout << ans << endl;
}
