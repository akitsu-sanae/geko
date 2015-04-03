#ifndef GEKO_ALGORITHM_FIND_HPP
#define GEKO_ALGORITHM_FIND_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class T>
inline constexpr InputIt
find(
        InputIt first,InputIt last,
        const T& value)
{
    for(;first!=last;++first){
        if(*first==value)return first;
    }
    return last;
}

}   // namespace algorithm
}   // namespace geko

#endif
