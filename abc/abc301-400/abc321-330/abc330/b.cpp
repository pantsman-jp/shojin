#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, l, r;
  cin >> n >> l >> r;
  rep(i, n)
  {
    int a;
    cin >> a;
    cout << min(max(a, l), r) << ' ';
  }
  cout << endl;
}
