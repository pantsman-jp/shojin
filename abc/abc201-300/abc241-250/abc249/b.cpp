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
  bool small = false, big = false;
  for (char c : s)
  {
    cnt[c]++;
    if (cnt[c] == 2)
    {
      cout << "No" << endl;
      return 0;
    }
    if (isupper(c))
      big = true;
    if (islower(c))
      small = true;
  }
  if (small and big)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}