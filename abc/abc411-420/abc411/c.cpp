#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, q, ans = 0;
  cin >> n >> q;
  vector<int> c(n + 2);
  auto add = [&](int i, int x)
  {
    if (c[i] == 0 and c[i + 1] == 1)
      ans += x;
  };
  rep(qi, 0, q)
  {
    int a;
    cin >> a;
    add(a - 1, -1), add(a, -1);
    c[a] ^= 1;
    add(a - 1, 1), add(a, 1);
    cout << ans << endl;
  }
}