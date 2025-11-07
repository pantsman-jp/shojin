#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, k;
  cin >> n >> k;
  rep(_, n)
  {
    int a;
    cin >> a;
    if (a % k == 0)
      cout << a / k << ' ';
  }
  cout << endl;
}
