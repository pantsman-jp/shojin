#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  int sum = 0;
  rep(_, n)
  {
    int a;
    cin >> a;
    sum += a;
  }
  cout << sum % 100 << endl;
}
