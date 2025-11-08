#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> move(vector<int> pos, int dir)
{
  if (dir == 0)
    return {pos[0], pos[1] + 1};
  if (dir == 1)
    return {pos[0] + 1, pos[1]};
  if (dir == 2)
    return {pos[0], pos[1] - 1};
  return {pos[0] - 1, pos[1]};
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string t;
  cin >> n >> t;
  int dir = 1;
  vector<int> pos = {0, 0};
  rep(i, 0, n)
  {
    if (t[i] == 'S')
      pos = move(pos, dir);
    else
      dir = (dir + 1) % 4;
  }
  cout << pos[0] << ' ' << pos[1] << endl;
}