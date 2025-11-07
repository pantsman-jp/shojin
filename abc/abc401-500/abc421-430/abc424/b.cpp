#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> count(n);
  vector<bool> end(n);
  for (int i = 0; i < k; i++)
  {
    int a, b;
    cin >> a >> b;
    count[a - 1]++;
    for (int i = 0; i < n; i++)
    {
      if ((count[i] == m) && !end[i])
      {
        cout << i + 1 << " ";
        end[i] = true;
      }
    }
  }
  cout << endl;
}
