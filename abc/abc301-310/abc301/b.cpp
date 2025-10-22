#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) { cin >> a[i]; }
  for (int i = 1; i < a.size(); i++)
  {
    if (a[i - 1] + 1 < a[i])
      a.insert(a.begin() + i, a[i - 1] + 1);
    if (a[i - 1] - 1 > a[i])
      a.insert(a.begin() + i, a[i - 1] - 1);
  }
  for (int x : a)
    cout << x << ' ';
  cout << endl;
}