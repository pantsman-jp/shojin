#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;
const ll mod = 998244353;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c;
  cin >> a >> b >> c;
  ll sum_a = (a * (a + 1) / 2) % mod;
  ll sum_b = (b * (b + 1) / 2) % mod;
  ll sum_c = (c * (c + 1) / 2) % mod;
  cout << (((sum_a * sum_b) % mod) * sum_c) % mod << endl;
}