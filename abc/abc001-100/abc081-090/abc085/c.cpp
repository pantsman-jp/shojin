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
  int n, y;
  cin >> n >> y;
  rep(a, 0, n + 1) rep(b, 0, n - a + 1)
  {
    int c = n - a - b;
    if (10000 * a + 5000 * b + 1000 * c == y)
    {
      cout << a << ' ' << b << ' ' << c << endl;
      return 0;
    }
  }
  cout << "-1 -1 -1" << endl;
}