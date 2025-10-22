#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  int ans = 0;
  rep(_, n)
  {
    string s;
    cin >> s;
    if (s == "Takahashi")
      ans++;
  }
  cout << ans << endl;
}
