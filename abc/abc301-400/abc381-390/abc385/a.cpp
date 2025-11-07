#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  vector<int> xs(3);
  rep(i, 3)
  {
    cin >> xs[i];
  }
  if (xs[0] == xs[1] && xs[1] == xs[2])
  {
    cout << "Yes" << endl;
    return 0;
  }
  rep(i, 3)
  {
    if (xs[i] + xs[(i + 1) % 3] == xs[(i + 2) % 3])
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
