#include <iostream>
using namespace std;

 int Sum (int N)
 {
    if (N == 1)
    { 
        return 1; 
    }
    else
    {
        return N + Sum (N-1);
    }
 }
 int main ()
 {   cout<< Sum(10) <<endl;
  }

