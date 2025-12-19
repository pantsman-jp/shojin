#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int gcd_all(const vector<int> &xs)
{
  int ans = xs[0];
  rep(i, 1, xs.size()) ans = gcd(ans, xs[i]);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x;
  cin >> n >> x;
  vector<int> xs(n);
  rep(i, 0, n) cin >> xs[i], xs[i] = abs(xs[i] - x);
  cout << gcd_all(xs) << endl;
}