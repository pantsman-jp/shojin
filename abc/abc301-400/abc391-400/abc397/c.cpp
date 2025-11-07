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
  vector<int> cntl(n + 1), cntr(n + 1);
  set<int> uniql, uniqr;
  rep(i, 0, n) uniql.insert(a[i]), cntl[i + 1] = uniql.size();
  for (int i = n - 1; -1 < i; i--)
    uniqr.insert(a[i]), cntr[i] = uniqr.size();
  int ans = 0;
  rep(i, 1, n) ans = max(ans, cntl[i] + cntr[i]);
  cout << ans << endl;
}