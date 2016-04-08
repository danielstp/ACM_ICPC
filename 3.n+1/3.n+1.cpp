#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

int maxCiclos(int, int);
int contCiclos(long);

int main(int argc, char *argv[]){
    if(argc != 3) return 1;
    int i = atoi(argv[1]);
    int j = atoi(argv[2]);
    std::cout<<i<<' '<<j<<' '<< maxCiclos(i,j)<< std::endl;
}

int maxCiclos(int i, int j){
    int max = 0;
    if(i>j) std::swap(i,j);
    for(int c=i; c<=j;c++){
        int k = contCiclos(c);
        if(max < k) max = k;
    }
    return max;
}

int contCiclos(long i){
    //std::cout<<" i="<<i<<"; ";
    int c = 0;
    while( !( i == (i & -i) ) ){
        if(i&1) {
            i = (3*i+1)>>1;
            c+=2;
        } else {
            i>>=1;
            c++;
        }
    }
    if(i != 1) {
        c += std::log2(i)+1;
    }
    //std::cout<<"cont="<<c<<std::endl;
    return c;
}
