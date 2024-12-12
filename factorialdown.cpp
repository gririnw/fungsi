#include <iostream>
using namespace std;

int Fact (int x)
 {
        if (x == 0)     // this is basis
        { return 1;}  
        else {return x * Fact(x-1);}  // this is reccursion part
 }
 int main ()
 {
        cout<<Fact(5)<<endl;
        return 0;
 }
