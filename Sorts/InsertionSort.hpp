#ifndef __MY_SORT_INSERTION_SORT_HPP__
#define __MY_SORT_INSERTION_SORT_HPP__

#include "Sort.hpp"
namespace MySort{

template<class T>
class InsertionSort : public Sort<T>{
public:
    InsertionSort(){}
    ~InsertionSort(){}
    void DoSort(std::vector<T>& data) final{
        for(int i=i ; i<data.size()-1; ++i){
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