#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.rbegin(), a.rend());
  int alice = 0, bob = 0;
  rep(i, n)
  {
    if (i % 2 == 0)
      alice += a[i];
    else
      bob += a[i];
  }
  cout << alice - bob << endl;
}