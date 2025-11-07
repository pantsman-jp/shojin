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
  rep(i, 0, 3) cnt[s[i]]++;
  for (auto [c, n] : cnt)
  {
    if (n == 1)
    {
      cout << c << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}