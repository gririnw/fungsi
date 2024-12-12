#include <iostream>
using namespace std;

int Sum( int start, int end)
 {
        if (start == end)     // ini basis
        { return end;}  
        else {return start + Sum(start+1, end);}  // ini bagian rekursif
 }
 int main ()
 {
        cout<<Sum(1,10)<<endl;
        return 0;
 }
