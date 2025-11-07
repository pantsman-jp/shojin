#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n)
  {
    cin >> a[i];
  }
  int k;
  cin >> k;
  int ans = 0;
  for (int m : a)
  {
    if (k <= m)
      ++ans;
  }
  cout << ans << endl;
}
