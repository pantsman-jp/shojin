#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool is_even(int n)
{
  return n % 2 == 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> evens, odds;
  rep(_, 0, n)
  {
    int a;
    cin >> a;
    if (is_even(a))
      evens.push_back(a);
    else
      odds.push_back(a);
  }
  sort(all(evens), greater<int>()), sort(all(odds), greater<int>());
  int ans = -1;
  if (evens.size() > 1)
    ans = max(ans, evens[0] + evens[1]);
  if (odds.size() > 1)
    ans = max(ans, odds[0] + odds[1]);
  cout << ans << endl;
}