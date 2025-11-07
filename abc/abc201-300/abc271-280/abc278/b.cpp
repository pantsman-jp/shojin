#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool check(int h, int m)
{
  return 0 <= h and h <= 23 and 0 <= m and m <= 59;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, m;
  cin >> h >> m;
  int a = h / 10, b = h % 10, c = m / 10, d = m % 10;
  while (true)
  {
    int a = h / 10, b = h % 10, c = m / 10, d = m % 10;
    int hh = a * 10 + c, mm = b * 10 + d;
    if (check(hh, mm))
    {
      cout << h << ' ' << m << endl;
      return 0;
    }
    m++;
    if (m == 60)
      h++, m = 0;
    if (h == 24)
      h = 0;
  }
}