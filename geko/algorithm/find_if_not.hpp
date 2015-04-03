#ifndef GEKO_ALGORITHM_FIND_IF_NOT_HPP
#define GEKO_ALGORITHM_FIND_IF_NOT_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class Predicate>
inline constexpr InputIt
find_if_not(InputIt first,InputIt last,Predicate pred){
    for(;first!=last;++first){
        if( !pred(*first)  )return first;
    }
    return last;
}

}   // namespace algorithm
}   // namespace geko

#endif
