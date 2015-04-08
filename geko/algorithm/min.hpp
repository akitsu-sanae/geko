#ifndef GEKO_ALGORITHM_MIN_HPP
#define GEKO_ALGORITHM_MIN_HPP

namespace geko{
namespace algorithm{

template<class T>
inline constexpr const T&
min(const T& a,const T& b){
    return (a>b)? b :a;
}

template<class T,class Compare>
inline constexpr const T&
min(const T& a,const T& b,Compare comp){
    return (comp(a,b))? b: a;
}

}   // namespace algorithm
}   // namespace geko

    #endif
