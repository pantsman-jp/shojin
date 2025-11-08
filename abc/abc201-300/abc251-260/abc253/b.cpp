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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector<int> token;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == 'o') token.push_back(i), token.push_back(j);
  cout << abs(token[0] - token[2]) + abs(token[1] - token[3]) << endl;
}