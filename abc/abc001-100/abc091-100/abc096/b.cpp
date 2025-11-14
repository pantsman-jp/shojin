#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int pow2(int n)
{
  if (n == 0)
    return 1;
  int half = pow2(n / 2);
  if (n % 2 == 0)
    return half * half;
  return 2 * half * half;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> xs(3);
  rep(i, 0, 3) cin >> xs[i];
  int k;
  cin >> k;
  cout << *max_element(all(xs)) * pow2(k) + reduce(all(xs)) - *max_element(all(xs)) << endl;
}