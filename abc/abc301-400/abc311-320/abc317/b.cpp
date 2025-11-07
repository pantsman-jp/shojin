#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  rep(i, n - 1)
  {
    if (a[i + 1] - a[i] != 1)
    {
      cout << a[i] + 1 << endl;
      return 0;
    }
  }
}
