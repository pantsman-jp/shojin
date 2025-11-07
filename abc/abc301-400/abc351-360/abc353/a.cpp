#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) { cin >> h[i]; }
  for (int i = 1; i < n; i++)
  {
    if (h[0] < h[i])
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
