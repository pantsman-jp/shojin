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
  if (x > y)
    cout << 0 << endl;
  else if ((y - x) % 10 == 0)
    cout << (y - x) / 10 << endl;
  else
    cout << (y - x) / 10 + 1 << endl;
}