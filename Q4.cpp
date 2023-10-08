#include <iostream>
using namespace std;

int fun(int n) {	//fun(95),fun(106),fun(96),fun(107),fun(97),fun(108),fun(98),fun(109),fun(99),fun(110),fun(100),fun(111),fun(101) 
    if (n > 100) {
    	cout<<n<<endl;
        return n - 10;	 //fun(106),fun(107),fun(108),fun(109),fun(108),fun(110),fun(111)
    }
    
    // A recursive function passing parameter as a recursive call or recursion inside the recursion
    
    cout<<n<< "\t";
    return fun(fun(n + 11)); //fun(fun(96)),fun(97),fun(98),fun(99),fun(100),fun(101)
}

int main() {
    int r;
    cout<<endl;
    r = fun(95);	//fun(95)
   
    cout << " " << r;	//91
   
    return 0;
}
