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
  map<string, int> cnt = {{"H", 0}, {"2B", 0}, {"3B", 0}, {"HR", 0}};
  rep(_, 0, 4)
  {
    string s;
    cin >> s;
    cnt[s]++;
  }
  for (auto [_, c] : cnt)
  {
    if (c != 1)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}