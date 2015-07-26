#include<iostream>

int fibo ( int a )
{
    if ( a<3)
        return 1;
    else return fibo(a-1)+fibo(a-2);
}

int main()
{
    std::cout<<fibo(50);
    return 0;
}
