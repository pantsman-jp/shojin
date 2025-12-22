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
  int n;
  cin >> n;
  set<int> cnt;
  int free = 0;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    if (a >= 3200)
      free++;
    else
      cnt.insert(a / 400);
  }
  int base = cnt.size();
  int mn = (base == 0) ? 1 : base;
  int mx = base + free;
  cout << mn << " " << mx << endl;
}