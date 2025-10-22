#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  ll ans = 0;
  map<int, ll> count;
  for (ll j = 0; j < n; j++)
  {
    ans += count[j - a[j]];
    count[j + a[j]] += 1;
  }
  cout << ans << endl;
}
