#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  vector<int> a(4);
  rep(i, 4)
  {
    cin >> a[i];
  }
  vector<int> cnt(5, 0);
  for (int x : a)
    cnt[x]++;
  int ans = 0;
  for (int i = 1; i <= 4; i++)
    ans += cnt[i] / 2;
  cout << ans << endl;
}