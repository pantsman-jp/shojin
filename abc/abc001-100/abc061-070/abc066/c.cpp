#include <bits/stdc++.h>
using namespace std;
#define rep(i, n, b) for (int i = (n); i < (b); i++)
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
  deque<int> b;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    if (i % 2 == 0)
      b.push_back(a);
    else
      b.push_front(a);
  }
  if (n % 2 == 1)
    reverse(all(b));
  rep(i, 0, n) cout << b[i] << ' ';
  cout << endl;
}