#include "list.h"

LinkedList::LinkedList(const LinkedList& t)
{
    this->max_size = t.max_size;
    this->size = t.size;
}

LinkedList& LinkedList::operator=(const LinkedList& t)
{
    this->max_size = t.max_size;
    this->size = t.size;
}

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
    if(head == tail)
    {
        if(head != nullptr)
        {
            Data_msg* ret = tail->data;
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
    else
    {
        Data_msg* ret = tail->data;
        Data_ptr* tmp = head->next;
        while(tmp == tail)
        {
            tmp = tmp->next;
        }
        free(tail);
        tmp->next = nullptr;
        tail = tmp;
        --size;
        return ret;
    }
}
Data_msg* LinkedList::pop_front() noexcept
{
    if(head == tail)
    {
        if(head != nullptr)
        {
            Data_msg* ret = head->data;
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
    Data_msg* ret = head->data;
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