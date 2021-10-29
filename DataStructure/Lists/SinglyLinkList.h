#ifndef __SKY_STRUCTURE_SINGLY_LINK_LIST_H__
#define __SKY_STRUCTURE_SINGLY_LINK_LIST_H__
#include <cstddef>

namespace SkyStructure
{


template <class T>
class SinglyNode
{
public:
    SinglyNode(T data){m_data = data;}
    ~SinglyNode() = default;
    SinglyNode* m_next = nullptr;
    T m_data;
};

template <class T>
class SinglyLinkList
{
private:

    size_t m_size = 0;
public:
    SinglyLinkList() = default;
    SinglyLinkList(T data, int num=1);
    ~SinglyLinkList();

    SinglyLinkList(const SinglyLinkList<T>& rhs);
    SinglyLinkList<T>& operator=(const SinglyLinkList<T>& rhs);

    SinglyLinkList(SinglyLinkList<T>&& rhs);
    SinglyLinkList<T>& operator=(SinglyLinkList<T>&& rhs);

    bool InsertNode(T data, SinglyNode<T>* node);
    void PushBackNode(T data);
    void PushBackNode(SinglyNode<T>* node);
    inline SinglyNode<T>* PopBackNode(){return m_tail;}
    inline SinglyNode<T>* PopFrontNode(){return m_head;}
    bool DeleteNodes(T data); //delete the first Node that value equls data ;
    bool DeleteNode(SinglyNode<T>* node);
    void ClearList();
    SinglyNode<T>* m_head = nullptr;
    SinglyNode<T>* m_tail = nullptr;
    inline size_t Size() const{return m_size;}
    inline bool Empty() const{return m_size==0;}

};


    
} // namespace SkyStructure


#endif
