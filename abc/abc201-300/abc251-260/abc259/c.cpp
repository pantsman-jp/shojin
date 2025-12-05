#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<pair<char, int>> rle(string s)
{
  vector<pair<char, int>> ans;
  int cnt = 1;
  char now = s[0];
  rep(i, 1, s.size())
  {
    if (s[i] == now)
      cnt++;
    else
      ans.push_back({now, cnt}), now = s[i], cnt = 1;
  }
  ans.push_back({now, cnt});
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  cin >> s >> t;
  vector<pair<char, int>> ns = rle(s), nt = rle(t);
  if (ns.size() != nt.size())
  {
    cout << "No" << endl;
    return 0;
  }
  rep(i, 0, ns.size())
  {
    auto [cs, ls] = ns[i];
    auto [ct, lt] = nt[i];
    if (cs != ct or ls > lt or (ls == 1 and lt > 1))
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}