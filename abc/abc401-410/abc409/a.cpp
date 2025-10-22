#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string t, a;
  cin >> n >> t >> a;
  rep(i, n)
  {
    if (t[i] == 'o' and a[i] == 'o')
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
