#include <iostream>

int main(){
    int n;
    int m;
    std::cin>>n;
    std::cin>>m;
    std::cout<<"\t";
    for (int i=1; i<=n; ++i){
        std::cout << i << "\t";
    }
    std::cout<<std::endl;
    int k=0;
    for (int i=1;i<=n; ++i){
        std::cout<<i<<"\t";
        for (int b=1; b<=n; ++b){
            std::cout<<(i*b)%m<<"\t";
            k+=1;
            if (k==n){
                std::cout<<std::endl;
                k=0;
            }

        }

    }
    
}