#include "SinglyLinkList.h"
#include <iostream>
#include <memory>

using namespace SkyStructure;

inline void print_all(std::shared_ptr<SinglyLinkList<int>>& list){
    std::cout << "*****************************************" << std::endl;
    std::cout << "size: " << list->Size()<< std::endl;
    auto temp = list->PopFrontNode();
    while(temp){
        std::cout << "  " << temp->m_data;
        temp = temp->m_next;
    }
    std::cout << "\n\n\n" << std::endl;
}

int main(){
    auto list1 = std::make_shared<SinglyLinkList<int>>();
    print_all(list1);

    auto list2 = std::make_shared<SinglyLinkList<int>>(5,2);
    print_all(list2);    

    auto list3 = std::make_shared<SinglyLinkList<int>>(*list2);
    print_all(list3); 

    list1 = list3;
    print_all(list1); 

    list1->PushBackNode(6);
    print_all(list1);   

    list1->InsertNode(10, list1->PopFrontNode());
    print_all(list1);   

    list1->InsertNode(15, list1->PopBackNode());   
    print_all(list1); 

    list1->DeleteNodes(10);
    print_all(list1); 

    list1->ClearList();
    print_all(list1);
}