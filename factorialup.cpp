#include <iostream>
using namespace std;

int fact(int start, int end)
{
	if (start == end) //ini basis
	{
		cout<<end<<"=";
		return end;
	}
	else
	{
		cout<<start<<"x";
		return start*fact(start+1, end); //ini rekursif
	}
}

int main(){
	cout<<fact(1,10)<<endl;
	return 0;
}
