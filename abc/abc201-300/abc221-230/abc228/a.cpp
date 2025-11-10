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
  int s, t, x;
  cin >> s >> t >> x;
  if (s < t)
  {
    if (s <= x and x < t)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  else
  {
    if (x < t or s <= x)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}