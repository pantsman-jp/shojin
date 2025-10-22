#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int ans = 0;
  rep(i, n) { cin >> a[i]; }
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        for (int l = k + 1; l < n; l++)
        {
          for (int m = l + 1; m < n; m++)
          {
            if (a[i] + a[j] + a[k] + a[l] + a[m] == 1000)
              ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
