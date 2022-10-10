#include<iostream>
int main(){
    int x;
    std::cin>>x;
    if (x%5==0)
        std::cout<<x/5;
    else std::cout<<x/5+1;
}
