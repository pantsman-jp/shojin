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
  char a, b;
  cin >> a >> b;
  vector<string> s = {string((int)(a - '0'), b), string((int)(b - '0'), a)};
  sort(all(s));
  cout << s[0] << endl;
}