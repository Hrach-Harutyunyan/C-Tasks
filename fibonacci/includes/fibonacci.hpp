#ifndef __FIBONACCI__HPP__
#define __FIBONACCI__HPP__

#include <iostream>

extern int tailFibonacci (int N, int first = 1, int second = 1);


template <int N>
struct fibonacci
{
    enum {
        value = fibonacci<N - 1>::value + fibonacci<N - 2>::value
    };
}; 

template < >
struct fibonacci <1>
{
    enum {
        value = 1
    };
};

template < >
struct fibonacci <2>
{
    enum {
        value = 1
    };
};



#endif