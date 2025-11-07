#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  map<int, int> cnt;
  rep(i, 0, n) cnt[a[i]]++;
  int ans = 0;
  for (auto [num, c] : cnt)
  {
    if (c == 1)
      ans = max(ans, num);
    else
      continue;
  }
  if (ans != 0)
    cout << distance(a.begin(), find(a.begin(), a.end(), ans)) + 1 << endl;
  else
    cout << -1 << endl;
}