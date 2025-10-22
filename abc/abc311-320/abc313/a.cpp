#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int saikyo = 0;
  for (int i = 1; i < n; i++)
    saikyo = max(saikyo, p[i]);
  cout << max(0, saikyo + 1 - p[0]) << endl;
}
