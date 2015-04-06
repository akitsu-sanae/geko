#ifndef GEKO_ALGORITHM_NONE_OF_HPP
#define GEKO_ALGORITHM_NONE_OF_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class Predicate>
inline constexpr bool
none_of(InputIt first,InputIt last,Predicate pred)
{
    while(first!=last){
        if(pred(*first))return false;
        ++first;
    }
    return true;
}

}   // namepsace algorithm
}   // namespace geko

#endif
