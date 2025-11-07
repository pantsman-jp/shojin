#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  vector<int> s(8);
  rep(i, 8) { cin >> s[i]; }
  rep(i, 7)
  {
    if (s[i] > s[i + 1])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  rep(i, 8)
  {
    if (s[i] % 25 != 0 or s[i] < 100 or 675 < s[i])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
