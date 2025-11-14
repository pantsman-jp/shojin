#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool check(string s)
{
  string t = s;
  reverse(all(t));
  return s == t;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, ans = 0;
  cin >> a >> b;
  rep(i, a, b + 1) if (check(to_string(i))) ans++;
  cout << ans << endl;
}