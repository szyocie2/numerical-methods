#include <iostream>
#include <iomanip>
using namespace std;

long double fib[100000];

int main(){
    int n;

    cout << "N = ";
    cin >> n;
    cout << setprecision(10000);


    fib[0] = 1;
    fib[1] = 1;
    
    for (int i = 2; i < n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }


    //for (int i = 0; i < n; i++)
    //{
    //    cout << endl << "wyraz nr" << i + 1 << ": " << fib[i];
    //}
    cout << endl << "wyraz nr " << n << " = " << fib[n - 1] << endl;

    return 0;
}