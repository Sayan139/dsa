#include <iostream>
#include <string>
using namespace std;

void kthbitset(int n, int k){
    int x = (n >> (k - 1));
    if ((n & x) != 0){
        cout << "its bits are set";
    } else {
        cout << "its not set";
    }
}

int countsetbits(int n){
    int res = 0;
    while (n > 0){
        n = n & (n - 1);
        res++;
    }
    return res;
}

bool ispowof2(int n){
    if (n == 0){
        return false;
    }
    return ((n & (n - 1)) == 0);
}

int findodd1(int arr[], int n){
    int res = arr[0];
    for (int i = 1; i <= n - 1; i++){
        res = res ^ arr[i];
    }
    return res;
}

void findodd2(int arr[], int n){
    cout << "'the odd occurring numbers are: " << endl;
    int x = arr[0];
    for (int i = 1; i < n; i++){
        x = x ^ arr[i];
    }
    int k = (x & (~(x - 1)));
    int res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++){
        if ((arr[i] & k) != 0){
            res1 = res1 ^ arr[i];
        } else {
            res2 = res2 ^ arr[i];
        }
    }
    cout << "the first number is: " << res1 << endl;
    cout << "the second number is: " << res2 << endl;
}

void printpowerset(string s){
    int n = s.length();
    int psize = (1 << n);
    for (int i = 0; i < psize; i++){
        for (int j = 0; j < n; j++){
            if ((i & (1 << j)) != 0){
                cout << s[j];
            }
        }
        cout << endl;
    }
}
// Utility function to check number of elements
// having set msb as of pattern
int checkBit(int pattern, int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if ((pattern & arr[i]) == pattern)
            count++;
    return count;
}
 
// Function for finding maximum and value pair
int maxAND(int arr[], int n)
{
    int res = 0, count;
 
    // iterate over total of 32bits from msb to lsb
    for (int bit = 31; bit >= 0; bit--) {
        // find the count of element having same pattern as
        // obtained by adding bits on every iteration.
        count = checkBit(res | (1 << bit), arr, n);
 
        // if count >= 2 set particular bit in result
        if (count >= 2)
            res = res | (1 << bit); // this is the pattern we continued
        }
 
    return res;
}
int main(){
    // string s = "abc";
    // printpowerset(s);
    int arr[] = { 4, 8, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum AND Value = " << maxAND(arr, n);
}
