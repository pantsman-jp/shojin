#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int s(string s)
{
  int ans = 0;
  for (char c : s)
    ans += c - '0';
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a, b, ans = 0;
  cin >> n >> a >> b;
  rep(i, 1, n + 1)
  {
    int sum = s(to_string(i));
    if (a <= sum and sum <= b)
      ans += i;
  }
  cout << ans << endl;
}