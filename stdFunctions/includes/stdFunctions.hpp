#ifndef __STDFUNCTIONS__HPP__
#define __STDFUNCTIONS__HPP__

#include <iostream>
#include <vector>

template <typename Iter, typename OutputIter, typename Predicat>
OutputIter transform(Iter begin, Iter end, OutputIter start, Predicat pred) {
    while(begin != end) {
        *start = pred(*begin);
        ++begin;
        ++start;
    }
    return start;
}

template <typename Iter, typename outputIter, typename predicate>
outputIter copy_if (Iter begin, Iter end, outputIter start, predicate pred) {
    for (; begin != end; begin ++) {
        if(pred(*begin)) {
            *start = *begin;
            start ++;
        }
    }
    return start;
}

template <typename T, typename U>
struct Pair
{
public:
    Pair();
    Pair(T first, U second);
    Pair(const Pair<T, U>&);    
    ~Pair() { };

public:
    Pair<T, U>& operator = (const Pair<T, U>& );
    template <typename T1, typename T2>
    friend bool operator == (const Pair<T1, T2>&, const Pair<T1, T2>&);
    template <typename T1, typename T2>
    friend bool operator != (const Pair<T1, T2>&, const Pair<T1, T2>&);
    template <typename T1, typename T2>
    friend bool operator < (const Pair<T1, T2>&, const Pair<T1, T2>&);
    template <typename T1, typename T2>
    friend bool operator <= (const Pair<T1, T2>&, const Pair<T1, T2>&);
    template <typename T1, typename T2>
    friend bool operator > (const Pair<T1, T2>&, const Pair<T1, T2>&);
    template <typename T1, typename T2>
    friend bool operator >= (const Pair<T1, T2>&, const Pair<T1, T2>&);

public:
    void swap(Pair <T, U>&);

public:
    T first_data;
    U second_data;
};

template <typename T, typename U>
Pair<T, U>::Pair() : first_data {T()}, second_data{U()} { }

template <typename T, typename U>
Pair<T, U>::Pair(T first, U second) : first_data{first}, second_data{second} { }

template <typename T, typename U>
Pair<T, U>::Pair(const Pair<T, U>& other) : first_data {other.first_data}, second_data {other.second_data} { };    

template <typename T, typename U>
Pair<T, U>& Pair<T, U>::operator = (const Pair<T, U>& other) {
    if(this != &other) {
        this->first_data = other.first_data;
        this->second_data = other.second_data;
    }
    return *this;
}

template <typename T, typename U>
bool operator == (const Pair<T, U>& thiss, const Pair<T, U>& other) {
    return thiss.first_data == other.first_data && thiss.second_data == other.second_data;
}

template <typename T, typename U>
bool operator != (const Pair<T, U>& thiss, const Pair<T, U>& other) {
    return !(thiss == other);
}

template <typename T, typename U>
bool operator < (const Pair<T, U>& thiss, const Pair<T, U>& other) {
    if(thiss.first_data == other.first_data) {
        return thiss.second_data < other.second_data;
    }
    return thiss.first_data < other.first_data;
}

template <typename T, typename U>
bool operator <= (const Pair<T, U>& thiss, const Pair<T, U>& other) {
    return thiss == other || thiss < other;
}

template <typename T, typename U>
bool operator > (const Pair<T, U>& thiss, const Pair<T, U>& other) {
    return !(thiss <= other);
}

template <typename T, typename U>
bool operator >= (const Pair<T, U>& thiss, const Pair<T, U>& other) {
    return !(thiss < other);
}

template <typename T, typename U>
void Pair<T, U>::swap(Pair <T, U>& other) {
    if(this != &other) {
        using std::swap;
        swap(this->first_data, other.first_data);
        swap(this->second_data, other.second_data);
    }
}

#endif