#include "gateway.h"
#include <iostream>
using namespace std;
#include<unistd.h>


void gateway_task()
{
while(1)
{
    std::cout << "Gateway forwarding data" << std::endl;
    sleep(3);
}
}

