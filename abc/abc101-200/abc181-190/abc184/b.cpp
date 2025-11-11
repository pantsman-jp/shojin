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
  int n, x;
  string s;
  cin >> n >> x >> s;
  for (char c : s)
  {
    if (c == 'o')
      x++;
    else if (c == 'x' and 0 < x)
      x--;
  }
  cout << x << endl;
}