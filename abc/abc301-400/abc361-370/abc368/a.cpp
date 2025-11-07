#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n), ans(n);
  rep(i, n) { cin >> a[i]; }
  for (int i = n - k; i < n; i++)
    ans[i + k - n] = a[i];
  for (int i = k; i < n; i++)
    ans[i] = a[i - k];
  rep(i, n) { cout << ans[i] << ' '; }
  cout << endl;
}
