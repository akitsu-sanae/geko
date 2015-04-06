#ifndef GEKO_ALGORITHM_ANY_OF_HPP
#define GEKO_ALGORITHM_ANY_OF_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class Predicate>
inline constexpr bool
any_of(InputIt first,InputIt last,Predicate pred)
{
    while(first!=last){
        if(pred(*first))return true;
        ++first;
    }
    return false;
}

}   // namespace algorithm
}   // namespace geko

#endif
