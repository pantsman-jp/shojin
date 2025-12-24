#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

set<int> d;

bool check(int n)
{
  while (n > 0)
  {
    if (d.count(n % 10) != 0)
      return false;
    n /= 10;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  rep(i, 0, k)
  {
    int di;
    cin >> di;
    d.insert(di);
  }
  int ans = n;
  while (true)
  {
    if (check(ans))
    {
      cout << ans << endl;
      return 0;
    }
    ans++;
  }
}