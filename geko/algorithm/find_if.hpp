#ifndef GEKO_ALGORITHM_FIND_IF_HPP
#define GEKO_ALGORITHM_FIND_IF_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class Predicate>
inline constexpr InputIt
find_if(InputIt first,InputIt last,Predicate pred){
    for(;first!=last;++first){
        if( pred(*first)  )return first;
    }
    return last;
}

}   // namespace algorithm
}   // namespace geko

#endif
