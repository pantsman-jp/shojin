#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, q;
  cin >> n >> q;
  vector<int> cnt(n + 1, 1);
  int min = 1;
  rep(i, q)
  {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int v = min; v < x + 1; ++v)
    {
      if (cnt[v] > 0)
      {
        ans += cnt[v];
        cnt[y] += cnt[v];
        cnt[v] = 0;
      }
    }
    while (min <= n && cnt[min] == 0)
      ++min;
    cout << ans << endl;
  }
}
