#ifndef __SKY_SORT_SELECTION_SORT_HPP__
#define __SKY_SORT_SELECTION_SORT_HPP__

#include "Sort.hpp"

namespace SkySort{

template<class T>
class SelectionSort : public Sort<T>{
public:
    SelectionSort(){}
    ~SelectionSort(){}
    void DoSort(std::vector<T>& data) final{
        for(int i=0; i<data.size()-1; ++i){
            int minIndex = i;
            for(int j=i+1; j<data.size(); ++j){
                if(data[j] < data[minIndex]){
                    minIndex = j;
                }
            }
            Sort<T>::SwapData(data[i], data[minIndex]);

        }
    }
};


}

#endif