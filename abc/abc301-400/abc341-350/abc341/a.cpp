#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  string ans;
  rep(_, n) { ans += "10"; }
  cout << ans + '1' << endl;
}
