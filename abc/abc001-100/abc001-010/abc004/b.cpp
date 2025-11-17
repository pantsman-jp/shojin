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
  vector<string> c(4);
  rep(i, 0, 4) rep(j, 0, 4)
  {
    char ch;
    cin >> ch;
    c[3 - i] += ch;
  }
  rep(i, 0, 4)
  {
    reverse(all(c[i]));
    rep(j, 0, 4) cout << c[i][j] << ' ';
    cout << endl;
  }
}