#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int f(int x)
{
  int ans = 0;
  string s = to_string(x);
  sort(all(s), greater<>());
  ans = stoi(s);
  reverse(all(s));
  return ans - stoi(s);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  int ans = n;
  rep(_, 0, k) ans = f(ans);
  cout << ans << endl;
}