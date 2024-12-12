#include <iostream>
using namespace std;

int JumlahDuaAngka( int angka1, int angka2)
{
     int jumlah;
     jumlah = angka1 + angka2;
     return jumlah;
}

int SelisihDuaAngka( int angka1, int angka2)
{
     int selisih;
     selisih = angka1 - angka2;
     return selisih;
}
int main ()
{
         int a, b;
         a = 10;
         b = -5;
         cout<< JumlahDuaAngka(a, b)<<endl;
  
         int selisih;
         selisih = SelisihDuaAngka (20, 11) ;
         cout<< selisih<<endl;   
         return 0;                
}
