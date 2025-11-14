#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int wai(int n)
{
  if (n == 4 or n == 6 or n == 9 or n == 11)
    return 1;
  return 2;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x, y;
  cin >> x >> y;
  if (x == 2 or y == 2)
    cout << "No" << endl;
  else if (wai(x) == wai(y))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}