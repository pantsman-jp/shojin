#include <iostream>
using namespace std;

int main()
{
  long long x;
  cin >> x;
  if ((x + 9) < 0 and (x + 9) % 10 != 0)
    cout << (x + 9) / 10 - 1 << endl;
  else
    cout << (x + 9) / 10 << endl;
}
