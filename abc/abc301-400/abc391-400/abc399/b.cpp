#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  vector<int> rank(n);
  int r = 1;
  while (true)
  {
    int x = 0;
    for (int i = 0; i < n; i++)
    {
      if (rank[i])
        continue;
      x = max(x, p[i]);
    }
    if (!x)
      break;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
      if (p[i] == x)
      {
        rank[i] = r;
        k++;
      }
    }
    r += k;
  }
  for (int i = 0; i < n; i++)
    cout << rank[i] << endl;
}
