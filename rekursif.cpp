#include <iostream>
using namespace std;

int Fact (int x)    // Deklarasi fungsi factorial
 {
        if (x == 0)     // Ini adalah BASIS(kondisi berhenti
        {
			return 1;
		} // kalau tidak ada basis brarti jadi infinite looping 
        else 
		{
		return x * Fact(x-1);
		}  // Ini bagian REKURSI
 }
 int main () // main program
 {
        cout<<Fact(5)<<endl;
        return 0;
 }

