#ifndef GEKO_ALGORITHM_COUNT_IF_HPP
#define GEKO_ALGORITHM_COUNT_IF_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class Predicate>
inline constexpr std::size_t
count_if(InputIt first,InputIt last,Predicate pred){
    std::size_t result = 0;
    while(first!=last){
        if( pred(*first)  )result++;
        ++first;
    }
    return result;
}

}   // namespace algorithm
}   // namespace geko

#endif
