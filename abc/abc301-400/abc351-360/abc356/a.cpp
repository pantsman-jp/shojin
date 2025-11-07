#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> ans;
  for (int i = 1; i < l; i++)
    ans.push_back(i);
  for (int i = r; l <= i; i--)
    ans.push_back(i);
  for (int i = r + 1; i < n + 1; i++)
    ans.push_back(i);
  rep(i, n) { cout << ans[i] << ' '; }
  cout << endl;
}
