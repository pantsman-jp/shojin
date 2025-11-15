#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n2i(char c)
{
  if (c == 'a')
    return 0;
  if (c == 'b')
    return 1;
  return 2;
}

char i2c(int n)
{
  if (n == 0)
    return 'A';
  if (n == 1)
    return 'B';
  return 'C';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<string> s(3);
  rep(i, 0, 3) cin >> s[i];
  int now = 0;
  while (true)
  {
    if (s[now].empty())
    {
      cout << i2c(now) << endl;
      return 0;
    }
    char head = s[now][0];
    s[now].erase(0, 1);
    now = n2i(head);
  }
}