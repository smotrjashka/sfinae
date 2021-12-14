#ifndef SFINAEPP_SFINAE_TEMPL_H
#define SFINAEPP_SFINAE_TEMPL_H

#include <iostream>
#include <valarray>
#include <type_traits>

namespace sfinae_templ{


    template<typename T>
    struct is_container{
        static const bool val = false;
    };

    template<typename T>
    struct is_container<std::vector<T>>{
        static const bool val = true;
    };

    template<typename T>
    struct is_container<std::list<T>>{
        static const bool val = true;
    };

    template<typename T>
    struct is_string{
        static const bool val = false;
    };

    template<typename T,
            typename Fake = typename std::enable_if<
                std::is_integral<T>::value, void >::type,
                int N = 1
            >
    void print_virtual_ip(T ip_candidate){

        T ip_add = std::abs(ip_candidate);

        int max_octate_m = 256;
        long long max_ip_v4 = 255 *(pow(max_octate_m, 3) + pow(max_octate_m, 2) +  max_octate_m + 1);

        std::vector<int> octates;
        int number_of_octets = 4;
        if (ip_candidate > max_ip_v4){
            number_of_octets = 6;
        }
        for (int i = number_of_octets-1; i >= 0; i--) {

            if (ip_candidate > 0) {
                long z = static_cast<long>(pow(max_octate_m, i));
                int temp_i = ip_candidate / z;
                ip_candidate = ip_candidate % z;
                octates.emplace_back(temp_i);
            } else {
                octates.template emplace_back(0);
            }
        }

        for (int indx = 0; indx<octates.size(); indx++) {

            std::cout << octates[indx] << '.';

        }

        std::cout << '\b' << ' ' << std::endl;

    };

    template<typename T,
            typename Fake = typename std::enable_if<
                    is_container<T>::val, void >::type
    >
    void print_virtual_ip(T ip_candidate){
        for (auto it=ip_candidate.begin(); it != ip_candidate.end(); it++) {
            std::cout << *it << ".";
        }
        std::cout << '\b' << ' ' << std::endl;

    };

    void print_virtual_ip(std::string ip_candidate){
        std::cout << ip_candidate << std::endl;
    }

};

#endif //SFINAEPP_SFINAE_TEMPL_H
