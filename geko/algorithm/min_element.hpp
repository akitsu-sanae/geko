/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_MIN_ELEMENT
#define GEKO_ALGORITHM_MIN_ELEMENT

namespace geko{
namespace algorithm{

template<class ForwardIt>
inline constexpr ForwardIt
min_element(ForwardIt first,ForwardIt last){
    if(first == last)return last;

    ForwardIt min_it = first;
    ++first;
    while(first!=last){
        if(*min_it > *first)min_it = first;
        ++first;
    }
    return first;
}

template<class ForwardIt,class Comp>
inline constexpr ForwardIt
min_element(
        ForwardIt first,ForwardIt last,
        Comp comp)
{
    if(first == last)return last;

    ForwardIt min_it = first;
    ++first;
    while(first!=last){
        if(comp(*min_it,*first))min_it = first;
        ++first;
    }
    return first;
}

}   // namespace algorithm
}   // namespace geko

#endif
