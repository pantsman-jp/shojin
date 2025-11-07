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
  vector<vector<int>> g = {{},
                           {2, 3},
                           {1, 4, 5},
                           {1, 6, 7},
                           {2, 8, 9},
                           {2, 10, 11},
                           {3, 12, 13},
                           {3, 14, 15},
                           {4},
                           {4},
                           {5},
                           {5},
                           {6},
                           {6},
                           {7},
                           {7}};
  int a, b;
  cin >> a >> b;
  if (find(all(g[a]), b) != g[a].end())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}