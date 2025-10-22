#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, int>> prereq(n);
  vector<vector<int>> rev(n + 1);
  for (int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    prereq[i] = {a, b};
    if (a > 0)
      rev[a - 1].push_back(i);
    if (b > 0)
      rev[b - 1].push_back(i);
  }
  vector<bool> acquired(n);
  vector<int> satisfied(n);
  queue<int> q;
  for (int i = 0; i < n; i++)
  {
    if (prereq[i].first == 0 && prereq[i].second == 0)
    {
      acquired[i] = true;
      q.push(i);
    }
  }
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    for (int nxt : rev[cur])
    {
      if (acquired[nxt])
        continue;
      satisfied[nxt]++;
      if (satisfied[nxt] == 1)
      {
        acquired[nxt] = true;
        q.push(nxt);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (acquired[i])
      ans++;
  cout << ans << endl;
}
