#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> sum1(n + 1), sum2(n + 1);
  rep(i, 1, n + 1)
  {
    int c, p;
    cin >> c >> p;
    sum1[i] = sum1[i - 1], sum2[i] = sum2[i - 1];
    if (c == 1)
      sum1[i] += p;
    else
      sum2[i] += p;
  }
  int q;
  cin >> q;
  rep(i, 0, q)
  {
    int l, r;
    cin >> l >> r;
    cout << sum1[r] - sum1[l - 1] << ' ' << sum2[r] - sum2[l - 1] << '\n';
  }
}