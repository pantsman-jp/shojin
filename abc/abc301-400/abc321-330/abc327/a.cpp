#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  rep(i, n - 1)
  {
    char c1 = s[i], c2 = s[i + 1];
    if ((c1 == 'a' and c2 == 'b') or (c1 == 'b' and c2 == 'a'))
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
