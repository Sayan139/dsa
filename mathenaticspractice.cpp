#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int absolutevalue(int n){
    if(n>=0){
        return n;
    }else{
        return (-1*n);
    }
}
void celcious_to_farenheight(int c){
    double f1=(9/5.0)*c;
    float res=f1+32;
    cout << res;
}
vector<int> quadratic_eqation_solver(int a,int b,int c){
    vector <int> root;
    int root1=0,root2=0;
    int temp =(pow(b,2)-4*a*c);
    if(temp<0){
        root.push_back(-1);
    }
    else{
        root1 = floor((-b + sqrt(temp)) / (2 * a));
        root2 = floor((-b - sqrt(temp)) / (2 * a));
        root.push_back(max(root1, root2));
        root.push_back(min(root1, root2));
    }
    return root;
}
long long factorial(int n){
    long long res=1;
    for(long long i=1; i<=n; i++){
        res=res*i;
    }
    return res;
}
int digitsInFactorial(int n){
    if(n<0){
        return 0;
    }
    if(n<=1){
        return 1;
    }
    double res=0;
    for(int i=1; i<=n; i++){
        res=res+log10(i);
    }
    return floor(res)+1;
}
bool isprime(int n){
    if(n==1)return false;
    if(n==2 || n==3)return true;
    if(n%2==0 || n%3==0)return false;
    for(int i=5; i*i<=n; i=i+6){
        if(n%i==0|| n%(i+2)==0)return false;
    }
    return true;
}
int exactly3Divisors(int n) {
    int res = 0;
    n=sqrt(n);
    for(int i = 2; i<=n; i++) {
        if(isprime(i)){
            res++;
        }
    }
    return res;
}
int main() {
    // int a, b, c;
    // cout << "enter the value of a: ";
    // cin  >> a; 
    // cout << "enter the value of b: ";
    // cin >> b ;
    // cout << "enter the value of c: ";
    // cin >> c;
    // vector<int> roots =quadratic_eqation_solver(a, b, c);
    // if (roots.size() == 1 && roots[0] == -1){
    //         cout << "Imaginary";
    // }
    // else{
    //     for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
    // }
    // cout << endl;
    // return 0;
    // long long  n;
    // cout << "enter the number : ";
    // cin >> n;
    // cout << factorial(n);
    // int n;
    // cout << "enter the number: ";
    // cin >> n;
    // cout << "digits of factorial is: " << digitsInFactorial(n);
    // int n;
    // cout << "enter the number: ";
    // cin >> n;
    // if(isprime(n)){
    //     cout << "its prime";
    // }else{
    //     cout << "its not prime";
    // }
    int n;
    cout << "enter the number: ";
    cin >> n;
    cout << "the numbers of number that have exactly 3 divisors are: " << exactly3Divisors(n);
}