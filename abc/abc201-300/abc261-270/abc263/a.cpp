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
  vector<int> cnt(14);
  rep(_, 0, 5)
  {
    int x;
    cin >> x;
    cnt[x]++;
  }
  bool two = false, three = false;
  rep(i, 1, 14)
  {
    if (cnt[i] == 2)
      two = !two;
    if (cnt[i] == 3)
      three = !three;
  }
  if (two and three)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}