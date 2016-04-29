/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_SEARCH_HPP
#define GEKO_ALGORITHM_SEARCH_HPP

namespace geko{
namespace algorithm{

template<class ForwardIt1,class ForwardIt2>
inline constexpr ForwardIt1
search(
        ForwardIt1 first,ForwardIt1 last,
        ForwardIt2 t_first,ForwardIt2 t_last)
{
    while(true){
        ForwardIt1 it = first;
        ForwardIt2 t_it = t_first;
        while(true){
            if(t_it == t_last)return first;
            if(it == last)return last;
            if(!(*it == *t_it))break;
            ++it;
            ++t_it;
        }
        ++first;
    }
}

template<class ForwardIt1,class ForwardIt2,class Predicate>
inline constexpr ForwardIt1
search(
        ForwardIt1 first,ForwardIt1 last,
        ForwardIt2 t_first,ForwardIt2 t_last,
        Predicate pred)
{
    while(true){
        ForwardIt1 it = first;
        ForwardIt2 t_it = t_first;
        while(true){
            if(t_it == t_last)return first;
            if(it == last)return last;
            if(!(*it == *t_it))break;
            ++it;
            ++t_it;
        }
        ++first;
    }
}

}   // namespace algorithm
}   // namespace geko

#endif
