#include "Sort.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include <iostream>
#include <memory>
#include <sys/time.h>
int main(){
    std::vector<int> data{1, 10, 3, 4, 66, 32, 45, 2, 10, 9, 9};
    std::unique_ptr<MySort::Sort<int>> sort = std::make_unique<MySort::BubbleSort<int>>();

    // struct timeval beforeSort, endSort;
    // gettimeofday(&beforeSort, nullptr);
    sort->DoSort(data);
    // gettimeofday(&endSort, nullptr);

    std::cout << "*********************BubbleSort************************** " << std::endl;
    for(auto d : data){
        std::cout << "BubbleSort: " << d << std::endl;
    }
    // std::cout << endSort.tv_sec*1000 + endSort.tv_usec/1000 - beforeSort.tv_sec*1000 - beforeSort.tv_usec/1000 << std::endl;
 
    sort = std::move(std::make_unique<MySort::QuickSort<int>>());
    sort->DoSort(data);
    // gettimeofday(&endSort, nullptr);
    std::cout << "*********************QuickSort************************** " << std::endl;
    for(auto d : data){
        std::cout << "QuickSort: " << d << std::endl;
    }
 
 
 
    return 0;
}