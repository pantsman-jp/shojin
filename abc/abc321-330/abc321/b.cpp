#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> a(n - 1);
  rep(i, n - 1) { cin >> a[i]; }
  rep(p, 101)
  {
    vector<int> b(n - 1);
    rep(i, n - 1) { b[i] = a[i]; }
    b.push_back(p);
    sort(b.begin(), b.end());
    int sum = 0;
    for (int i = 1; i < n - 1; i++)
      sum += b[i];
    if (sum >= x)
    {
      cout << p << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
