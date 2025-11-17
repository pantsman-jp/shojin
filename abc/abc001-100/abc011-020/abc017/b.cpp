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
  string x;
  cin >> x;
  if (x == "")
  {
    cout << "YES" << endl;
    return 0;
  }
  while (x.size() > 0)
  {
    if (x.size() >= 2 and x[0] == 'c' and x[1] == 'h')
      x = x.substr(2);
    else if (x[0] == 'o' or x[0] == 'k' or x[0] == 'u')
      x = x.substr(1);
    else
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}