#ifndef __SKY_SORT_SHELL_SORT_HPP__
#define __SKY_SORT_SHELL_SORT_HPP__

#include "Sort.hpp"
namespace SkySort{

template<class T>
class ShellSort : public Sort<T>{
public:
    ShellSort(){}
    ~ShellSort(){}
    void DoSort(std::vector<T>& data) final{
        int degree = data.size()/2;
        while(degree >= 1){
            for(int i=degree; i<data.size(); ++i){
                T current = data[i];
                int j=i;
                while(j>degree && current < data[j-degree])
                {
                    data[j] = data[j-degree];
                    j -= degree;
                }
                data[j] = current;
            }
            degree /= 2;
        }
    }
};


}

#endif