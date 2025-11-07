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
  int n, a, b;
  cin >> n >> a >> b;
  int sum = a + b;
  for (int ans = 1; ans < n + 1; ans++)
  {
    int c;
    cin >> c;
    if (sum == c)
    {
      cout << ans << endl;
      return 0;
    }
  }
}