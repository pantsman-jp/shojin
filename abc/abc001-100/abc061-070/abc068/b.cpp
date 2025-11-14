#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int calc(int x)
{
  int ans = 0;
  while (x % 2 == 0)
    ans++, x /= 2;
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int max_val = -1, ans = -1;
  rep(x, 1, n + 1)
  {
    int num = calc(x);
    if (max_val < num)
      max_val = num, ans = x;
  }
  cout << ans << endl;
}