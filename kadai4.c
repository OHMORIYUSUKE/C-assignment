#include<stdio.h>

int main();
int f(int);
int fibonacci(int);
int gcd(int,int);
int lcm(int,int);

int main(){
    int value,n,m;

    n = 5;
    value = f(n);
    printf("f(%d) = %d\n",n,value);

    n = 7;
    value = fibonacci(n);
    printf("fibonacci(%d) = %d\n",n,value);

    n = 105;
    m = 77;
    value = gcd(n,m);
    printf("gcd(%d , %d) = %d\n",n,m,value);

    value = lcm(n,m);
    printf("lcm(%d , %d) = %d\n",n,m,value);

    return 0;
}

int f(int n){
    if(n==0){
        return 1;
    }
    return n*f(n-1);
}

int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else{
        if(n==1){
            return 1;
        }
        else{
            return fibonacci(n-1)+fibonacci(n-2);
        }
    }
}

int gcd(int n,int m){
    if (n%m==0){
        return m;
    }
    else{
         return gcd(m,n%m);
        }
}

int lcm(int n,int m){
    return (m*n)/gcd(n,m);
}