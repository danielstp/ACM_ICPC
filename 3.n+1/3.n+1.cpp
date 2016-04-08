#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <boost/pool/pool_alloc.hpp>

int maxCiclos(int, int);
int contCiclos(long);

int main(int argc, char *argv[]){
    if(argc != 3) return 1;
    int i = atoi(argv[1]);
    int j = atoi(argv[2]);
    std::cout<<i<<' '<<j<<' '<< maxCiclos(i,j)<< std::endl;
    boost::singleton_pool<boost::fast_pool_allocator_tag, sizeof(std::pair<const long, int>)>::release_memory();
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
    static std::map<long,int,std::less< long >, boost::pool_allocator<std::pair<const long,int> > > cache;
    std::vector<int  > lista;
    int conCache = 0;
    int c = 0;
    while( !( i == (i & -i) ) ){
        if(cache.count(i)){
            //std::cout<<"en cache "<< cache[i]<< "; c="<<c;
            conCache=cache[i];
            break;
        } else {
            lista.push_back(i);
            //std::cout<<" i="<<i;
        }
        if(i&1) {
            i = (3*i+1);
            c++;
        } else {
            i>>=1;
            c++;
        }
    }
    if(conCache){
        c += conCache;
    } else {
        if(i != 1) {
            c += std::log2(i)+1;
        }
    }
    for(int d = 0; d < lista.size();d++){
        cache[lista[d]] = c-d;
    }
    //std::cout<<"cont="<<c<<std::endl;
    return c;
}
