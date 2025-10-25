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
  vector<int> count(n + 1);
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    count[a]++;
  }
  ll ans = 0;
  rep(i, 1, n + 1)
  {
    ll c = count[i];
    ans += c * (c - 1) / 2 * (n - c);
  }
  cout << ans << endl;
}