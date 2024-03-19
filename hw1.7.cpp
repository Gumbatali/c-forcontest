#include <iostream>

int main() {
    std::cout << "\t0\t1\t2\t3\t4\t5\t6\t7\t8\t9\tA\tB\tC\tD\tE\tF"<<std::endl;


    int n=0;
    int k=2;
    std::cout<<k;
    for (int i=32;i<128;++i){
        std::cout<<"\t"<<char(i);
        n+=1;
        if ((n>15) && (k<7)){
            std::cout<<std::endl;
            std::cout<< k+1;
            n=0;
            k+=1;

        }
    }

    return 0;
}
