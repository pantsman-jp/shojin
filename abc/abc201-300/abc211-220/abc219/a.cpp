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
  if (0 <= x and x < 40)
    cout << 40 - x << endl;
  else if (40 <= x and x < 70)
    cout << 70 - x << endl;
  else if (70 <= x and x < 90)
    cout << 90 - x << endl;
  else
    cout << "expert" << endl;
}