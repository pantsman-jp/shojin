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
  string s;
  cin >> s;
  int n = s.size();
  if (check(s) and check(s.substr(0, (n - 1) / 2)) and check(s.substr((n + 1) / 2)))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}