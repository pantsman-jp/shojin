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
  vector<string> a(h);
  rep(i, 0, h) cin >> a[i];
  cout << string(w + 2, '#') << endl;
  rep(i, 0, h) cout << '#' << a[i] << '#' << endl;
  cout << string(w + 2, '#') << endl;
}