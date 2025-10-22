#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  int sum = 0;
  rep(_, n - 1)
  {
    int a;
    cin >> a;
    sum += a;
  }
  cout << -sum << endl;
}
