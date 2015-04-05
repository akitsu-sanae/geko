#ifndef GEKO_ALGORITHM_COUNT_HPP
#define GEKO_ALGORITHM_COUNT_HPP

#include<cstddef> // std::size_t

namespace geko{
namespace algorithm{

// TODO: use iterator_traits<InoutIt>::difference_type, not std::size_t
template<class InputIt,class T>
inline constexpr std::size_t
count(InputIt first,InputIt last,const T& value){
    std::size_t result = 0;
    while(first!=last){
        if(*first == value)result++;
        ++first;
    }
    return result;
}

}   // namespace algorithm
}   // namespace geko


#endif
