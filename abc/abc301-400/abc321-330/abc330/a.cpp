#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, l;
  cin >> n >> l;
  int ans = 0;
  rep(_, n)
  {
    int a;
    cin >> a;
    if (a >= l)
      ans++;
  }
  cout << ans << endl;
}
