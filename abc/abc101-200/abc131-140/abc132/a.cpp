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
  map<char, int> cnt;
  for (char c : s)
    cnt[c]++;
  bool ok = true;
  for (auto [c, n] : cnt)
    if (n != 2)
      ok = false;
  if (cnt.size() == 2 and ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}