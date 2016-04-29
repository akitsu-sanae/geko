/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_FOR_EACH_HPP
#define GEKO_ALGORITHM_FOR_EACH_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class Function>
inline constexpr Function for_each(
        InputIt first,InputIt last,
        Function f
        )
{
    for(;first != last;++first){
        f(*first);
    }
    return f;
}

}   // namespace algorithm
}   // namespace geko

#endif
