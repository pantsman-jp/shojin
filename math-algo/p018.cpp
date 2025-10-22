#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  map<int, ll> count;
  rep(i, n)
  {
    int a;
    cin >> a;
    count[a]++;
  }
  cout << count[100] * count[400] + count[200] * count[300] << endl;
}
