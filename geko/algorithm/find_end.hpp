/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/



#ifndef GEKO_ALGORITHM_FIND_END_HPP
#define GEKO_ALGORITHM_FIND_END_HPP

#include <geko/algorithm/search.hpp>

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
