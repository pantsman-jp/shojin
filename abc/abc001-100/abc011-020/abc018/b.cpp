#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

string s;

void solve()
{
  int l, r;
  cin >> l >> r;
  l--, r--;
  reverse(s.begin() + l, s.begin() + r + 1);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> s >> n;
  rep(_, 0, n) solve();
  cout << s << endl;
}