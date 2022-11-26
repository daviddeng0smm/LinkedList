#ifndef LL_H
#define LL_H
#include "STUDENT.H"
#include <iostream>

struct LLnode
{
    LLnode *fwdPtr;
    Student theData;
};

template <class T>
class LL
{
private:
    LLnode *header;

public:
    void push_front(T s);

    void push_back(T s);

    void display_list();

    int list_length();

    T retrieve_front(T s);

    T retrieve_back(T s);

    T search_list(int);

    void destroy_list();

    bool delete_node(int a);

    LL()
    {
        header = nullptr;
    }
};

template <class T>
void LL<T>::push_front(T s)
{
    LLnode *newNode = new LLnode();
    LLnode *temp;
    newNode->theData = s;
    newNode->theData.data = s.data;
    newNode->theData.key = s.key;
    temp = header;
    header = newNode;
    newNode->fwdPtr = temp;
}

template <class T>
void LL<T>::push_back(T s)
{
    LLnode *newNode = new LLnode();
    newNode->fwdPtr = nullptr;
    newNode->theData = s;
    newNode->theData.data = s.data;
    newNode->theData.key = s.key;
    LLnode *temp = header;
    if (temp != nullptr)
    {
        while (temp->fwdPtr != nullptr)
        {
            temp = temp->fwdPtr;
        }
        temp->fwdPtr = newNode;
    }
    else
        header = newNode;
}

template <class T>
void LL<T>::display_list()
{
    LLnode *temp = header;

    int counter = 0;
    if (temp == nullptr)
    {
        std::cout << "node " << counter << " address -> " << &temp << "Empty List" << std::endl;
    }
    else
    {
        while (temp != nullptr)
        {
            std::cout << "node " << counter << " address -> " << &temp->fwdPtr << " data " << temp->theData.data << " " << temp->theData.key << std::endl;
            temp = temp->fwdPtr;
            counter++;
        }
    }
}
template <class T>
int LL<T>::list_length()
{
    LLnode *temp = header;
    int counter = 0;
    if (temp == nullptr)
    {
        return counter;
    }
    while (temp != nullptr)
    {
        temp = temp->fwdPtr;
        counter += 1;
    }
    return counter;
}

template <class T>
T LL<T>::retrieve_front(T s)
{
    LLnode *temp = header;
    if (temp != nullptr)
    {
        return temp->theData;
    }
    else
        throw std::invalid_argument("empty list");
}

template <class T>
T LL<T>::retrieve_back(T s)
{
    LLnode *temp = header;
    if (temp != nullptr)
    {
        for (int i = 0; i < list_length() + 1; i++)
        {
            temp = temp->fwdPtr;
        }
    }
    else
        throw std::invalid_argument("empty list");
    return temp->theData;
}

template <class T>
void LL<T>::destroy_list()
{
    LLnode *temp = header;
    while (temp != nullptr)
    {
        temp = temp->fwdPtr;
        free(header);
        header = temp;
    }
}

template <class T>
T LL<T>::search_list(int a)
{
    LLnode *temp = header;

    while (temp != nullptr)
    {
        if (temp->theData.key == a)
        {
            return temp->theData;
        }
        else if (temp->fwdPtr == nullptr)
        {
            temp->theData.key = 0;
            temp->theData.data = "";
            return temp->theData;
        }
        temp = temp->fwdPtr;
    }
    return temp->theData;
}

template <class T>
bool LL<T>::delete_node(int a)
{
    bool deleted = false;
    LLnode *previous = nullptr;
    LLnode *current = header;
    LLnode *next = header->fwdPtr;

    if (current == nullptr && deleted == false)
    {
        throw std::invalid_argument("empty list");
        return deleted;
    }

    else if (current->theData.key = a && deleted == false)
    {
        free(header);
        header = next;
        deleted = true;
        return deleted;
    }
    else if (deleted == false)
    {
        while (current->theData.key != a && current != nullptr)
        {
            previous = current;
            current = current->fwdPtr;
            next = next->fwdPtr;
            if (current->theData.key = a)
            {
                free(current);
                previous->fwdPtr = next;
                deleted = true;
            }
        }
    }
    else
        return deleted;
}
#endif
