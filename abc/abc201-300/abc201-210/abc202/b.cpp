#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

char op(char c)
{
  if (c == '0')
    return '0';
  if (c == '1')
    return '1';
  if (c == '6')
    return '9';
  if (c == '8')
    return '8';
  return '6';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  reverse(all(s));
  for (char c : s)
    cout << op(c);
  cout << endl;
}