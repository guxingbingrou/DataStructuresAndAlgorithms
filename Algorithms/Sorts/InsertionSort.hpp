#ifndef __SKY_SORT_INSERTION_SORT_HPP__
#define __SKY_SORT_INSERTION_SORT_HPP__

#include "Sort.hpp"
namespace SkySort{

template<class T>
class InsertionSort : public Sort<T>{
public:
    InsertionSort(){}
    ~InsertionSort(){}
    void DoSort(std::vector<T>& data) final{
        for(int i=1 ; i<data.size(); ++i){
            T current = data[i];
            int preindex = i-1;
            while(preindex>=0 && data[preindex] > current){
                data[preindex+1] = data[preindex];
                --preindex;
            }
            data[preindex+1] = current;
        }
    }
};


}

#endif