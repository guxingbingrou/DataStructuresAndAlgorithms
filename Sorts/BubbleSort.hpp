#ifndef __MY_SORT_BUBBLE_SORT_HPP__
#define __MY_SORT_BUBBLE_SORT_HPP__

#include "Sort.hpp"
namespace MySort{

template<class T>
class BubbleSort : public Sort<T>{
public:
    BubbleSort(){}
    ~BubbleSort(){}
    void DoSort(std::vector<T>& data) final{
        for(int i=0 ; i<data.size()-1; ++i){
            for(int j=0; j<data.size()-i-1; ++j){
                if(data[j] > data[j+1]){
                    T temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;

                }
            }
        }
    }
};


}

#endif