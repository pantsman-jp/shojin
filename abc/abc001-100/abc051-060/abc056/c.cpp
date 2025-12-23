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
  int x;
  cin >> x;
  rep(i, 1, x + 1)
  {
    if (i * (i + 1) / 2 >= x)
    {
      cout << i << endl;
      return 0;
    }
  }
}