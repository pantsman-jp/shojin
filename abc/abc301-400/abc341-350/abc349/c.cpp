#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool is_substr(string s, string t)
{
  int i = 0, j = 0;
  while (i < s.size() and j < t.size())
  {
    if (s[i] == t[j])
      j++;
    i++;
  }
  return j == t.size();
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  cin >> s >> t;
  string newt = t;
  if (t.back() == 'X')
    newt.pop_back();
  rep(i, 0, t.size()) newt[i] = tolower(t[i]);
  if (is_substr(s, newt))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}