#ifndef __SKY_SORT_QUICK_SORT_HPP__
#define __SKY_SORT_QUICK_SORT_HPP__

#include "Sort.hpp"
namespace SkySort{

template<class T>
class QuickSort : public Sort<T>{
public:
    QuickSort(){}
    ~QuickSort(){}
    void DoSort(std::vector<T>& data) final{
        DoSort(data, 0, data.size()-1);
    }

private:
    void DoSort(std::vector<T> &data, int begin, int end){
        if (begin < end)
        {
            T base = data[begin];
            int i = begin;
            int j = end;
            while (i < j)
            {
                while (i < j && data[j] >= base)
                {
                    --j;
                }
                if (i >= j)
                    break;
                Sort<T>::SwapData(data[i], data[j]);
                // T temp = data[j];
                // data[j] = data[i];
                // data[i] = temp;
                ++i;

                while (i < j && data[i] <= base)
                {
                    ++i;
                }
                if (i >= j)
                    break;
                Sort<T>::SwapData(data[i], data[j]);
                // temp = data[j];
                // data[j] = data[i];
                // data[i] = temp;
                --j;
            }
            DoSort(data, 0, i-1);
            DoSort(data, i+1, end);
        }
    }
};


}

#endif