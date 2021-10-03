#include "list.h"
#include <sstream>
#include <string>
#include <mcheck.h>

int main(int argc, char** argv)
{
    //mtrace();
    LinkedList* ja = new LinkedList();
    Data_msg* msg = static_cast<Data_msg*>(malloc(sizeof(Data_msg)));
    msg->para.first = 1;
    msg->para.second = 2;
    ja->push_back(msg);
    ja->pop_back();
    free(msg);
    delete ja;
    //muntrace();
    return 0;
}