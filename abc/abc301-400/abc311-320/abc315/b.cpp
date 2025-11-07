#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int m;
  cin >> m;
  vector<int> d(m);
  rep(i, m) cin >> d[i];
  int a = 0, rest = (reduce(d.begin(), d.end()) + 1) / 2;
  while (true)
  {
    if (rest <= d[a])
    {
      cout << a + 1 << ' ' << rest << endl;
      return 0;
    }
    else
    {
      rest -= d[a];
      a++;
    }
  }
}
