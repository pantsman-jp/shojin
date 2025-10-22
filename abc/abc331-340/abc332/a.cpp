#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, s, k;
  cin >> n >> s >> k;
  int ans = 0;
  rep(_, n)
  {
    int p, q;
    cin >> p >> q;
    ans += p * q;
  }
  if (ans < s)
    ans += k;
  cout << ans << endl;
}
