#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, m, sum = 0;
  cin >> n >> m;
  rep(i, n)
  {
    int a = 0;
    cin >> a;
    sum += a;
  }
  if (sum <= m)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
