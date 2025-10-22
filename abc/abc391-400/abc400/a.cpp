#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int a;
  cin >> a;
  if (400 % a == 0)
    cout << 400 / a << endl;
  else
    cout << -1 << endl;
}
