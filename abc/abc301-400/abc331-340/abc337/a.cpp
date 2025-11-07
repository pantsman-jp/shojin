#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  int sumx = 0, sumy = 0;
  rep(_, n)
  {
    int x, y;
    cin >> x >> y;
    sumx += x;
    sumy += y;
  }
  if (sumx > sumy)
    cout << "Takahashi" << endl;
  if (sumx == sumy)
    cout << "Draw" << endl;
  if (sumx < sumy)
    cout << "Aoki" << endl;
}
