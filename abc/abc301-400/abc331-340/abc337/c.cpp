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
  map<int, int> pos;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    pos[a] = i;
  }
  int now = -1;
  rep(_, 0, n)
  {
    int next = pos[now] + 1;
    cout << next << ' ';
    now = next;
  }
  cout << endl;
}