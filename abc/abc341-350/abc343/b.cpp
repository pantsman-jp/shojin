#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      int a;
      cin >> a;
      if (a == 1)
        cout << j + 1 << ' ';
    }
    cout << endl;
  }
}
