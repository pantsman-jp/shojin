#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  vector<int> ans = {6, 2, 4, 8};
  cout << ans[n % 4] << endl;
}
