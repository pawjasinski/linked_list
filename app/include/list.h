#ifndef __LIST__H__
#define __LIST__H__
#include <stdlib.h>
#include <utility>

#define MAX_SIZE 100

struct Data_msg
{
    std::pair<int,int> para{0,0};
};

struct Data_ptr
{
    Data_msg* data = nullptr;
    Data_ptr* next = nullptr;
};

class LinkedList
{
private:
Data_ptr* head;
Data_ptr* tail;
int size;
int max_size;
public:
LinkedList(): size(0), max_size(MAX_SIZE), head(nullptr), tail(nullptr) {}
~LinkedList();
bool push_back(Data_msg* data) noexcept;
bool push_front(Data_msg* data) noexcept;
Data_msg* pop_back() noexcept;
Data_msg* pop_front() noexcept;
inline int getsize() noexcept
{
    return size;
}
inline int setsize(int new_size) noexcept
{
    this->size = new_size;
    return this->size;
}
};


#endif // __LIST__H__