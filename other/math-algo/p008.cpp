#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, s;
  cin >> n >> s;
  int ans = 0;
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < n + 1; j++)
    {
      if (i + j <= s)
        ans++;
    }
  }
  cout << ans << endl;
}
