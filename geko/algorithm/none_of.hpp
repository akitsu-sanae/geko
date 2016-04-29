/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_NONE_OF_HPP
#define GEKO_ALGORITHM_NONE_OF_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class Predicate>
inline constexpr bool
none_of(InputIt first,InputIt last,Predicate pred)
{
    while(first!=last){
        if(pred(*first))return false;
        ++first;
    }
    return true;
}

}   // namepsace algorithm
}   // namespace geko

#endif
