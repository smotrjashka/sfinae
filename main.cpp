#include <iostream>
#include <vector>
#include <list>
#include "sfinae_templ.h"

int main() {
    std::cout << "Hello, HW3!" << std::endl;
    sfinae_templ::print_virtual_ip(char(-1));
    sfinae_templ::print_virtual_ip(short(0));
    sfinae_templ::print_virtual_ip(int(2130706433));
    sfinae_templ::print_virtual_ip(long(8875824491850138409));
    sfinae_templ::print_virtual_ip(std::string("192.168.8.2"));
    sfinae_templ::print_virtual_ip(std::vector<int>{192, 168, 1, 1});
    sfinae_templ::print_virtual_ip(std::list<int>{192, 1, 7, 8});
    return 0;
}
