#include <iostream>

int main() {
    int N, K, M;
    int kd=0;
    std::cin >> N >> K >> M;
    if ((N>=K)&&(K>=M)){
        while (N>=K){
        int kz=N/K;
        kd+= kz*(K/M);
        N-=kz*(K/M)*M;
    }
    }
    else{
        kd=0;
    }
    std::cout<<kd;





}

