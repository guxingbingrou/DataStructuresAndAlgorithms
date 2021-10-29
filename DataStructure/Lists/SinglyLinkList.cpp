#include "SinglyLinkList.h"

namespace SkyStructure{

template<class T>
SinglyLinkList<T>::SinglyLinkList(T data, int num){
    m_head = new SinglyNode<T>(data);
    m_tail = m_head;
    ++m_size;
    --num;
    while(num-- > 0){
        m_tail->m_next = new SinglyNode<T>(data);
        m_tail = m_tail->m_next;
        ++m_size;
    }
}


template<class T>
SinglyLinkList<T>::~SinglyLinkList(){
    ClearList();
}


template<class T>
SinglyLinkList<T>::SinglyLinkList(const SinglyLinkList<T>& rhs){
    if(&rhs == this)
        return;

    auto tempNode = rhs.m_head;
    while(tempNode){
        PushBackNode(tempNode->m_data);
        tempNode = tempNode->m_next;
    }
}

template<class T>
SinglyLinkList<T>& SinglyLinkList<T>::operator=(const SinglyLinkList<T>& rhs){
    if(&rhs == this)
        return *this;
    ClearList();

    auto tempNode = rhs.m_head;
    while(tempNode){
        PushBackNode(tempNode->m_data);
        tempNode = tempNode->m_next;
    }
    return *this;
}

template<class T>
SinglyLinkList<T>::SinglyLinkList(SinglyLinkList<T>&& rhs){
    if(&rhs == this)
        return ;
    m_head = rhs.m_head;
    m_tail = rhs.m_tail;
    m_size = rhs.Size();
    rhs.m_head = nullptr;
    rhs.m_tail = nullptr;
    rhs.ClearList();
}

template<class T>
SinglyLinkList<T>& SinglyLinkList<T>::operator=(SinglyLinkList<T>&& rhs){
    if(&rhs == this)
        return *this;
    ClearList();
    m_head = rhs.m_head;
    m_tail = rhs.m_tail;
    m_size = rhs.Size();
    rhs.m_head = nullptr;
    rhs.m_tail = nullptr;
    rhs.ClearList();     
    return *this; 
}

template<class T>
bool SinglyLinkList<T>::InsertNode(T data, SinglyNode<T>* node){
    if(node == m_head){
        auto newNode = new SinglyNode<T>(data);
        auto temp = m_head;
        m_head = newNode;
        m_head->m_next = temp;
        ++m_size;
        return true;
    }

    auto temp = m_head;
    while(temp && temp->m_next){
        if(temp->m_next == node){
            auto newNode = new SinglyNode<T>(data);
            newNode->m_next = temp->m_next;
            temp->m_next = newNode;
            ++ m_size;
            return true;
        }
        temp = temp->m_next;
    }

    return false;


}

template<class T>
void SinglyLinkList<T>::PushBackNode(T data){
    auto newNode = new SinglyNode<T>(data); 
    PushBackNode(newNode);
}

template<class T>
void SinglyLinkList<T>::PushBackNode(SinglyNode<T>* node){
    if(!m_head){
        m_head = m_tail = node;
    }
    else{
        m_tail->m_next = node;
        m_tail = m_tail->m_next;
    }
    ++m_size;
}

template<class T>
bool SinglyLinkList<T>::DeleteNodes(T data){
    if(Empty()) return false;
    if(m_head->m_data == data){
        auto temp = m_head;
        m_head = m_head->m_next;
        delete temp;
        --m_size;
        return true;
    }

    auto temp = m_head;
    while(temp->m_next){
        if(temp->m_next->m_data == data){
            auto tt = temp->m_next;
            temp->m_next = temp->m_next->m_next;
            delete tt;
            --m_size;
            return true;
        }
    }

    return false;
}

template<class T>
bool SinglyLinkList<T>::DeleteNode(SinglyNode<T>* node){
    if(Empty()) return false;
    if(m_head == node){
        auto temp = m_head;
        m_head = m_head->m_next;
        delete temp;
        --m_size;
        return true;
    }

    auto temp = m_head;
    while(temp->m_next){
        if(temp->m_next == node){
            auto tt = temp->m_next;
            temp->m_next = temp->m_next->m_next;
            delete tt;
            --m_size;
            return true;
        }
    }

    return false;
}

template<class T>
void SinglyLinkList<T>::ClearList(){
    while(m_head){
        auto temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

template class SinglyLinkList<int>;


}
