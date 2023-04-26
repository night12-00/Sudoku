#include "include.h"

void In(int n)
{
  while (n > 0)
  {
    cout << n << endl;
    n--;
  }
}

int main()
{
  int n = 99;
  In(n);

  cout << "Init Project";
  return 0;
}
