#include <iostream>
#include <vector>
using namespace std;
int countnum(int n){
    int res=0;
    while(n!=0){
        res++;
        n=n/10;
    }
    return res;
}
int palindrome(int n){
	int tab=n;
	int res=0;
	while(tab!=0){
		int lb=tab%10;
		res=(res*10)+lb;
		tab=tab/10;
	}
	return (res==n);
}
int factorial(int n){
    int res=1;
    for(int i=1; i<=n; i++){
        res=res*i;
    }
    return res;
}
int trailingzeroes(int n){
    int res=0;
    for(int i=5; i<=n; i=i*5){
        res=res+(n/i);
    }
    return res;
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int isprime(int n){
    if(n==1) return false;
    if(n==2 || n==3)return true;
    if(n%2==0 || n%3==0)return false;
    for(int i=5; i*i<=n; i=i+6){
        if(n%i==0 || n%(i+2)==0)return false;
    }
    return true;
}
void primefactors(int n){
    cout << "the prime factors are: ";
    if(n<1)return ;
    while(n%2==0){
        cout << 2 << " ";
        n=n/2;
    }
    while(n%3==0){
        cout << 3 << " ";
        n=n/3;
    }
    for(int i=5; i*i<=n; i=i+6){
        while(n%i==0){
            cout << i << " ";
            n=n/i;
        }
        while(n%(i+2)==0){
            cout << (i+2) << " ";
            n=n/(i+2);
        }
    }
    if(n>3){
        cout << n << " ";
    }
}
void alldivisors(int n){
    cout << "All divisors of " << n << " are: ";
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            cout << i << " ";
            if (i != n/i) // Avoid duplicate for perfect squares
                cout << n/i << " ";
        }
    }
}
void sieve(int n){
    vector<int> isprimenum(n+1, true); // Initialize all numbers as prime
    for(int i=2; i*i<=n; i++){
        if(isprimenum[i] == true){
            for(int j=i*i; j<=n; j=j+i){
                isprimenum[j] = false; // Mark multiples of prime numbers as not prime
            }
        }
    }
    cout << "Prime numbers up to " << n << " are: ";
    for(int i=2; i<=n; i++){
        if(isprimenum[i] == true){
            cout << i << " ";
        }
    }
    cout << endl;
}
int main(){
   // int n;
   // cout << "enter the number: ";
   // cin >> n;
   // cout << "the number of digits are: " << countnum(n);
   // int n;
   // cout << "enter the number: ";
   // cin >> n;
   // if(palindrome(n)==1){
// 	   cout << "its palindrome";
   // }else{
// 	   cout << "its not palindrome";
   // }
    // int n;
    // cout << "enter the number: ";
    // cin >> n;
    // cout << "the factorial is : " << factorial(n);
    // int n;
    // cout << "enter the number: "; 
    // cin >> n;
    // cout << "the trailing zeroes are : " << trailingzeroes(n);
    // int a,b;
    // cout << "enter the number: ";
    // cin >> a;
    // cout << "enter the second number: ";
    // cin >> b;
    // cout << "the gcd is: " << gcd(a,b);
    // int a,b;
    // cout << "enter the number: ";
    // cin >> a;
    // cout << "enter the second number: ";
    // cin >> b;
    // cout << "the lcm is: " << lcm(a,b);
    // int n;
    // cout << "enter the number: ";
    // cin >> n;
    // if(isprime(n)==1){
    //     cout << "its prime";
    // }else{
    //     cout << "its not prime";
    // }
    // int n;
    // cout << "enter the number you want the prime factors of : ";
    // cin >> n;
    // primefactors(n);
    // int n;
    // cout << "enter the number you want the all divisors of : ";
    // cin >> n;
    // alldivisors(n);
    int n;
    cout << "enter the number : ";
    cin >> n;
    sieve(n);
}
