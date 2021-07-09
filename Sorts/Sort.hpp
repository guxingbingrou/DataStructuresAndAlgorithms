#ifndef __MY_SORT_SORT_HPP__
#define __MY_SORT_SORT_HPP__
#include <vector>
namespace MySort{

template<class T>
class Sort
{
public:
    Sort(/* args */){};
    virtual void DoSort(std::vector<T>& data) = 0;
    virtual ~Sort(){};
};




}



#endif