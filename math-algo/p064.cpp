#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, k;
  cin >> n >> k;
  ll sum = 0;
  rep(_, n)
  {
    int a;
    cin >> a;
    sum += a;
  }
  if (sum % 2 != k % 2)
    cout << "No" << endl;
  else if (sum > k)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}
