// #include <iostream>
// using namespace std;
 
// int main()
// {
//    int a{5};
//    cout << &a << endl;
    
// }


// #include <iostream>
// using namespace std;
// int sum(int a[], int n){
//     int res = 0;
//     for (int i=0; i<n; i++){
//         res += a[i];
//     }
//     return res;
// }

// int SumRec(int* a, int n){
//     if (n == 0){
//         return 0;
//     }
//     else {
//         return a[n-1] + SumRec(a, n-1);
//     }

    
// }

// int main(){
//     int a[] = {1, 1, 1, 1, 1};
//     int n = sizeof(a)/sizeof(a[0]);
//     cout << SumRec(a, n) << endl;

// }

// #include <iostream>
// using namespace std;

// int cnt(int arr[], int n){
//     if(n == 0) return 0;
//     else{
//         return 1 + cnt(arr, n-1);
//     }
// }

// int main(){
//     int a[] = {1, 1, 1, 1, 1};
//     int n = sizeof(a)/sizeof(a[0]);
//     cout << cnt(a, n) << endl;

// }


#include <iostream>
using namespace std;

int Max(int arr[], int n){
    if(n == 1) return arr[0];
    
    int Maximum = Max(arr, n-1);
    return (arr[n-1] > Maximum) ? arr[n-1] : Maximum;
    
}

int main(){
    int a[] = {1, 1, 1, 2, 9};
    int n = sizeof(a)/sizeof(a[0]);
    cout << Max(a, n) << endl;
}


















