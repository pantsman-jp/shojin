#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<int, int> cnt;
  rep(i, 0, 4 * n - 1)
  {
    int a;
    cin >> a;
    cnt[a]++;
  }
  for (auto [ans, c] : cnt)
  {
    if (c == 3)
    {
      cout << ans << endl;
      return 0;
    }
  }
}