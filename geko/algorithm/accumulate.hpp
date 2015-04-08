#ifndef GEKO_ALGORITHM_ACCUMULATE_HPP
#define GEKO_ALGORITHM_ACCUMULATE_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class T>
inline constexpr T
accumulate(InputIt first,InputIt last,T value){
    while(first!=last){
        value = value + *first;
        ++first;
    }
    return value;
}

template<class InputIt,class T,class Operator>
inline constexpr T
accumulate(InputIt first,InputIt last,T value,Operator op){
    while(first!=last){
        value = op(value,*first);
        ++first;
    }
    return value;
}

}   // namespace algorithm
}   // namespace geko

#endif
