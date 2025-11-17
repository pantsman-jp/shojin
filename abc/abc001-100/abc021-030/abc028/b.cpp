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
  for (char c : {'A', 'B', 'C', 'D', 'E', 'F'})
    if (c == 'F')
      cout << cnt[c];
    else
      cout << cnt[c] << ' ';
  cout << endl;
}