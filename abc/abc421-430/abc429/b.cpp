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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n)
  {
    int sum = 0;
    rep(j, 0, n)
    {
      if (j == i)
        continue;
      else
        sum += a[j];
    }
    if (sum == m)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}