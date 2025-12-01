#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int x = 0, y = 0;

void move(char c)
{
  if (c == 'R')
    x++;
  else if (c == 'L')
    x--;
  else if (c == 'U')
    y++;
  else
    y--;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  map<P, int> cnt;
  cnt[make_pair(x, y)]++;
  for (char c : s)
  {
    move(c), cnt[make_pair(x, y)]++;
    if (cnt[make_pair(x, y)] == 2)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}