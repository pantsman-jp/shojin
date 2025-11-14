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
  int n;
  cin >> n;
  int p = 0, w = 0, g = 0, y = 0, kinds = 0;
  rep(_, 0, n)
  {
    string s;
    cin >> s;
    if (s == "P")
      p = 1;
    else if (s == "W")
      w = 1;
    else if (s == "G")
      g = 1;
    else if (s == "Y")
      y = 1;
    kinds = p + w + g + y;
  }
  if (kinds == 4)
    cout << "Four" << endl;
  else
    cout << "Three" << endl;
}