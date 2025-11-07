#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  vector<int> c(n);
  rep(i, n)
  {
    cin >> c[i];
    a[i].resize(c[i]);
    rep(j, c[i]) cin >> a[i][j];
  }
  int x;
  cin >> x;
  int mn = 100;
  rep(i, n)
  {
    if (find(a[i].begin(), a[i].end(), x) != a[i].end())
      mn = min(mn, c[i]);
  }
  vector<int> ans;
  rep(i, n)
  {
    if (find(a[i].begin(), a[i].end(), x) != a[i].end() and c[i] == mn)
      ans.push_back(i + 1);
  }
  int k = ans.size();
  cout << k << endl;
  rep(i, k) cout << ans[i] << ' ';
  cout << endl;
}
