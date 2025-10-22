#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int k, g, m;
  cin >> k >> g >> m;
  int glass = 0, mug = 0;
  rep(_, k)
  {
    if (glass == g)
      glass = 0;
    else if (mug == 0)
      mug = m;
    else
    {
      int diff = min(g - glass, mug);
      mug -= diff;
      glass += diff;
    }
  }
  cout << glass << ' ' << mug << endl;
}
