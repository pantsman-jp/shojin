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
  int y;
  cin >> y;
  while (true)
  {
    if (y % 4 == 2)
    {
      cout << y << endl;
      return 0;
    }
    y++;
  }
}