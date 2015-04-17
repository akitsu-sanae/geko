#ifndef GEKO_ALGORITHM_FIND_END_HPP
#define GEKO_ALGORITHM_FIND_END_HPP

#include "search.hpp"

namespace geko{
namespace algorithm{

template<class ForwardIt1,class ForwardIt2>
inline constexpr ForwardIt1
find_end(
        ForwardIt1 first,ForwardIt2 last,
        ForwardIt2 d_first,ForwardIt2 d_last)
{
    if(d_first == d_last)return last;
    ForwardIt1 res = last;
    while(true){
        ForwardIt1 result = geko::algorithm::search(first,last,d_first,d_last);
        if(result == last)return last;
        res = result;
        first = result;
        ++first;
    }
    return res;
}

template<class ForwardIt1,class ForwardIt2,class Predicate>
inline constexpr ForwardIt1
find_end(
        ForwardIt1 first,ForwardIt2 last,
        ForwardIt2 d_first,ForwardIt2 d_last,
        Predicate pred)
{
    if(d_first == d_last)return last;
    ForwardIt1 res = last;
    while(true){
        ForwardIt1 result = geko::algorithm::search(first,last,d_first,d_last,pred);
        if(result == last)return last;
        res = result;
        first = result;
        ++first;
    }
    return res;
}

}   // namespace algorithm
}   // namespace geko

#endif
