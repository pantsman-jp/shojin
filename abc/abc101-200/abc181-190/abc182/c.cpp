#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int solve(ll n)
{
  vector<int> a;
  while (n > 0)
    a.push_back(n % 10), n /= 10;
  int ans = 1e9, k = a.size();
  rep(bit, 0, 1 << k)
  {
    int sum = 0, cnt = 0;
    rep(i, 0, k)
    {
      if (bit & (1 << i))
        cnt++;
      else
        sum += a[i];
    }
    if (cnt < k and sum % 3 == 0)
      ans = min(ans, cnt);
  }
  if (ans < 1e9)
    return ans;
  return -1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  cout << solve(n) << endl;
}