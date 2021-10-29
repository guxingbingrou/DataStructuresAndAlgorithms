#ifndef __SKY_SORT_SORT_HPP__
#define __SKY_SORT_SORT_HPP__
#include <vector>
namespace SkySort{

template<class T>
class Sort
{
public:
    Sort(/* args */){};
    virtual void DoSort(std::vector<T>& data) = 0;
    static void SwapData(T& a, T& b){
        if(a == b)
            return;
        a = a + b;
        b = a - b;
        a = a - b;
    }
    virtual ~Sort(){};
};




}



#endif