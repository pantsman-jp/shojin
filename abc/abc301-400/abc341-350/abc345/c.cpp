#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  map<char, ll> cnt;
  for (char c : s)
    cnt[c]++;
  ll total = s.size() * (s.size() - 1) / 2, same = 0;
  bool dup = false;
  for (auto [_, k] : cnt)
  {
    same += k * (k - 1) / 2;
    if (k >= 2)
      dup = true;
  }
  if (dup)
    cout << total - same + 1 << endl;
  else
    cout << total - same << endl;
}