#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

char op(char c)
{
  if (c == 'Z')
    return 'A';
  return c + 1;
}

char ops(int n, char c)
{
  if (n == 0)
    return c;
  return ops(n - 1, op(c));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  for (char c : s)
    cout << ops(n, c);
  cout << endl;
}