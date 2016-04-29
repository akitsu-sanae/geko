/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ALGORITHM_COPY_HPP
#define GEKO_ALGORITHM_COPY_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class OutputIt>
inline constexpr OutputIt
copy(InputIt first,InputIt last,OutputIt dist)
{
    while(first != last){
        *dist++ = *first++;
    }
    return dist;
}

}   // namespace algorithm
}   // namespace geko
#endif
