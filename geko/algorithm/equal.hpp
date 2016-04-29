/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/


#ifndef GEKO_ALGORITHM_EQUAL_HPP
#define GEKO_ALGORITHM_EQUAL_HPP

namespace geko{
namespace algorithm{

template<class InputIt1,class InputIt2>
inline constexpr bool
equal(
        InputIt1 first1,InputIt1 last1,
        InputIt2 first2,InputIt2 last2)
{
    while(first1!=last1){
        if(!(*first1 == *first2))return false;
        ++first1;
        ++first2;
    }
    return true;
}

}   // namespace algorithm
}   // namespace geko

#endif
