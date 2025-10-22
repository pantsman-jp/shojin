#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  string ans;
  for (int i = 1; i < n + 1; i++)
  {
    if (i % 3 == 0)
      ans += 'x';
    else
      ans += 'o';
  }
  cout << ans << endl;
}
