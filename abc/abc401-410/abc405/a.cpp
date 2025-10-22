#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int r, x;
  cin >> r >> x;
  if ((x == 1 && 1600 <= r && r < 3000) || (x == 2 && 1200 <= r && r < 2400))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
