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
  int l = 0, r = s.size() - 1;
  while (l < r and s[l] == 'a' and s[r] == 'a')
    ++l, --r;
  while (l < r and s[r] == 'a')
    --r;
  while (l < r and s[l] == s[r])
    ++l, --r;
  if (l >= r)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}