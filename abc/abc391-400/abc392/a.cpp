#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  vector<int> a(3);
  rep(i, 3)
  {
    cin >> a[i];
  }
  rep(i, 3)
  {
    if (a[i] * a[(1 + i) % 3] == a[(i + 2) % 3])
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
