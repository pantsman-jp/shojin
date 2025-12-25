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
  int n, m;
  cin >> n >> m;
  rep(a, 0, n + 1)
  {
    int b = 4 * n - m - 2 * a;
    int c = n - a - b;
    if (b >= 0 and c >= 0)
    {
      cout << a << ' ' << b << ' ' << c << endl;
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl;
}