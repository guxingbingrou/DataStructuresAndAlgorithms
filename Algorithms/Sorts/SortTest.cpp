#include "Sort.hpp"
#include "BubbleSort.hpp"
#include "QuickSort.hpp"
#include "InsertionSort.hpp"
#include "ShellSort.hpp"
#include "SelectionSort.hpp"
#include <iostream>
#include <memory>

void resetData(std::vector<int>& data){
    data.clear();
    data.emplace_back(1);
    data.emplace_back(10);
    data.emplace_back(3);
    data.emplace_back(7);
    data.emplace_back(2);
    data.emplace_back(3);
    data.emplace_back(4);
    data.emplace_back(5);
    data.emplace_back(80);
    data.emplace_back(23);
    data.emplace_back(45);
    data.emplace_back(66);
    data.emplace_back(11);
}
int main(){
    std::vector<int> data;

    
    std::cout << "*********************BubbleSort************************** " << std::endl;
    resetData(data);
    std::unique_ptr<SkySort::Sort<int>> sort = std::make_unique<SkySort::BubbleSort<int>>();
    sort->DoSort(data);
    for(auto d : data){
        std::cout << "BubbleSort: " << d << std::endl;
    }
 
    std::cout << "*********************QuickSort************************** " << std::endl;
    resetData(data);
    sort = std::move(std::make_unique<SkySort::QuickSort<int>>());
    sort->DoSort(data);
    for(auto d : data){
        std::cout << "QuickSort: " << d << std::endl;
    }

    std::cout << "*********************InsertionSort************************** " << std::endl;
    resetData(data);
    sort = std::move(std::make_unique<SkySort::InsertionSort<int>>());
    sort->DoSort(data);
    for(auto d : data){
        std::cout << "InsertionSort: " << d << std::endl;
    }


    std::cout << "*********************ShellSort************************** " << std::endl;
    resetData(data);
    sort = std::move(std::make_unique<SkySort::ShellSort<int>>());
    sort->DoSort(data);
    for(auto d : data){
        std::cout << "ShellSort: " << d << std::endl;
    }

    std::cout << "*********************SelectionSort************************** " << std::endl;
    resetData(data);
    sort = std::move(std::make_unique<SkySort::SelectionSort<int>>());
    sort->DoSort(data);
    for(auto d : data){
        std::cout << "SelectionSort: " << d << std::endl;
    }

    return 0;
}