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
