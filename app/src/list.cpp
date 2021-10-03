#include "list.h"

bool LinkedList::push_back(Data_msg* data) noexcept
{
    bool ret_value = true;
    if(head == nullptr)
    {
        Data_ptr* temp = static_cast<Data_ptr*>(malloc(sizeof(Data_ptr)));
        if(temp == nullptr)
        {
            return false;
        }
        temp->data = data;
        head = temp;
        tail = temp;
        size = 1;
    }
    else if(size < max_size)
    {
        Data_ptr* temp = static_cast<Data_ptr*>(malloc(sizeof(Data_ptr)));
        if(temp == nullptr)
        {
            return false;
        }
        temp->data = data;
        Data_ptr* tmp = tail;
        tail = temp;
        tmp->next = tail;
        ++ size;
    }
    else
    {
        ret_value = false;
    }
    return ret_value;
}
bool LinkedList::push_front(Data_msg* data) noexcept
{
    bool ret_value = true;
    if(head == nullptr)
    {
        Data_ptr* temp = static_cast<Data_ptr*>(malloc(sizeof(Data_ptr)));
        if(temp == nullptr)
        {
            return false;
        }
        temp->data = data;
        head = temp;
        tail = temp;
        size = 1;
    }
    else if(size < max_size)
    {
        Data_ptr* temp = static_cast<Data_ptr*>(malloc(sizeof(Data_ptr)));
        if(temp == nullptr)
        {
            return false;
        }
        temp->data = data;
        Data_ptr* tmp = head;
        head = temp;
        temp->next = tmp;
        ++size;
    }
    else
    {
        ret_value = false;
    }
    return ret_value;
}
Data_msg* LinkedList::pop_back() noexcept
{
    Data_msg* ret = tail->data;
    if(head == tail)
    {
        if(head != nullptr)
        {
            free(tail);
            size = 0;
            head = nullptr;
            tail = nullptr;
            return ret;
        }
        else
        {
            return nullptr;
        }
    }
    free(tail);
    --size;
    Data_ptr* tmp = head;
    while(tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tail = tmp;
    return ret;
}
Data_msg* LinkedList::pop_front() noexcept
{
    Data_msg* ret = head->data;
    if(head == tail)
    {
        if(head != nullptr)
        {
            free(head);
            size = 0;
            head = nullptr;
            tail = nullptr;
        return ret;
        }
        else
        {
            return nullptr;
        }
    }
    Data_ptr* tmp = head;
    head = head->next;
    free(tmp);
    --size;
    return ret;
}

LinkedList::~LinkedList()
{
    if(head == tail)
    {
        if(head != nullptr)
        {
            free(head->data);
            free(head);
            return;
        }
        else
        {
            return;
        }
    }
    Data_ptr* tmp = head;
    while(tmp != tail)
    {
        tmp = head->next;
        free(head->data);
        free(head);
    }
}