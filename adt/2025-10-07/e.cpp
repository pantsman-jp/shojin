#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n, n--;
  if (n == 0)
  {
    cout << 0 << endl;
    return 0;
  }
  vector<char> evens = {'0', '2', '4', '6', '8'};
  string ans;
  while (n > 0)
    ans = evens[n % 5] + ans, n /= 5;
  cout << ans << endl;
}
