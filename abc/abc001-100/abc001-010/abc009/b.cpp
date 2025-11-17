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
  set<int> p;
  rep(_, 0, n)
  {
    int a;
    cin >> a;
    p.insert(a);
  }
  vector<int> p2(all(p));
  sort(all(p2), greater<int>());
  cout << p2[1] << endl;
}