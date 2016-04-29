/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ALGORITHM_COPY_N_HPP
#define GEKO_ALGORITHM_COPY_N_HPP

namespace geko{
namespace algorithm{

template<class InputIt,typename Size,typename OutputIt>
inline constexpr OutputIt
copy_n(InputIt first,Size count,OutputIt dist){
    if(count<=0)return dist;
    *dist++ = *first;
    for(Size i=static_cast<Size>(1);i<count;++i){
        *dist++ = *++first;
    }
    return dist;
}

}   // namespace algorithm
}   // namespace geko

#endif
