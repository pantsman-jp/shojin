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
  vector<int> b, r;
  int k;
  rep(i, 0, s.size())
  {
    if (s[i] == 'B')
      b.push_back(i + 1);
    if (s[i] == 'R')
      r.push_back(i + 1);
    if (s[i] == 'K')
      k = i + 1;
  }
  if (((b[0] % 2 == 0 and b[1] % 2 != 0) or (b[0] % 2 != 0 and b[1] % 2 == 0)) and (r[0] < k and k < r[1]))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}