/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ALGORITHM_COPY_IF
#define GEKO_ALGORITHM_COPY_IF

namespace geko{
namespace algorithm{

template<
    class InputIt,class OutputIt,
    class Predicate
    >
inline constexpr OutputIt
copy_if(
        InputIt first,InputIt last,
        OutputIt dist,
        Predicate pred)
{
    while(first != last){
        if( pred(*first) )*dist++ = *first;
        first++;
    }
    return dist;
}

}   // namespace algorithms
}   // namespace geko

#endif
