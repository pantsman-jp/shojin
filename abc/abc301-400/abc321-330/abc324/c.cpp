#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int check1(string &s, string &t)
{
  if (s.size() != t.size())
    return false;
  int cnt = 0;
  rep(i, 0, s.size()) if (s[i] != t[i]) cnt++;
  return cnt < 2;
}

bool check2(string &s, string &t)
{
  if (s.size() != t.size() + 1)
    return false;
  int i = 0;
  rep(j, 0, t.size())
  {
    while (i < s.size() and s[i] != t[j])
      i++;
    if (i == s.size())
      return false;
    i++;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string t;
  cin >> n >> t;
  vector<int> ans;
  rep(i, 1, n + 1)
  {
    string s;
    cin >> s;
    if ((s.size() + 1 >= t.size()) and (check1(s, t) or check2(s, t) or check2(t, s)))
      ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (int i : ans)
    cout << i << ' ';
  cout << endl;
}