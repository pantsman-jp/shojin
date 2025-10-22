#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> a(7);
  for (int i = 0; i < 7; i++)
    cin >> a[i];
  vector<int> count(14, 0);
  for (int x : a)
    count[x]++;
  for (int i = 1; i < 14; i++)
  {
    if (count[i] > 2)
    {
      for (int j = 1; j < 14; j++)
      {
        if (i == j)
          continue;
        if (count[j] > 1)
        {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}
