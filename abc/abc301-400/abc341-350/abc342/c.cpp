#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

map<char, char> c2c;

void op()
{
  char c, d;
  cin >> c >> d;
  for (char x = 'a'; x <= 'z'; x++)
    if (c2c[x] == c)
      c2c[x] = d;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  string s;
  cin >> n >> s >> q;
  for (char c = 'a'; c <= 'z'; c++)
    c2c[c] = c;
  rep(_, 0, q) op();
  for (char c : s)
    cout << c2c[c];
  cout << endl;
}