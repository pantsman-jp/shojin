#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), s, ord(n + 1, -1);
  rep(i, n) cin >> a[i];
  ll c = 1, l = 0;
  {
    ll v = 1;
    while (ord[v] == -1)
    {
      ord[v] = s.size();
      s.push_back(v);
      v = a[v - 1];
    }
    c = s.size() - ord[v], l = ord[v];
  }
  if (k < l)
    cout << s[k] << endl;
  else
  {
    k -= l;
    k %= c;
    cout << s[l + k] << endl;
  }
}
