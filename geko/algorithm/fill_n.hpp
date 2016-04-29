/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_FILL_N_HPP
#define GEKO_ALGORITHM_FILL_N_HPP

namespace geko{
namespace algorithm{

template<class OutputIt,class Size,class T>
inline constexpr OutputIt
fill_n(OutputIt first,Size count,const T& value){
    while(count-- > 0){
        *first++ = value;
    }
    return first;
}

}   // namespace algorithm
}   // namespace geko

#endif
