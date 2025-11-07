#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(const vector<int> &pos1, const vector<int> &pos2)
{
  int dx = pos1[0] - pos2[0], dy = pos1[1] - pos2[1];
  return dx * dx + dy * dy;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> pts(n, vector<int>(2));
  for (int i = 0; i < n; ++i)
    cin >> pts[i][0] >> pts[i][1];
  vector<vector<int>> dist(n, vector<int>(n));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        dist[i][j] = -1;
      else
        dist[i][j] = calc(pts[i], pts[j]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    int ans = distance(dist[i].begin(), max_element(dist[i].begin(), dist[i].end()));
    cout << ans + 1 << endl;
  }
}
