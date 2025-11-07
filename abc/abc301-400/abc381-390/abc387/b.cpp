#include <iostream>
using namespace std;

int main()
{
  int x;
  cin >> x;
  int ans = 0, prod = 1;
  for (int i = 1; i < 10; i++)
  {
    for (int j = 1; j < 10; j++)
    {
      prod = i * j;
      if (prod != x)
        ans += prod;
    }
  }
  cout << ans << endl;
}
