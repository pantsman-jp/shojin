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
  int x, y;
  cin >> x >> y;
  rep(c, 0, x + 1)
  {
    int t = x - c;
    if (2 * c + 4 * t == y)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}