#ifndef GEKO_ALGORITHM_TRANSFORM_HPP
#define GEKO_ALGORITHM_TRANSFORM_HPP

namespace geko{
namespace algorithm{

template<class InputIt,class OutputIt,class Operation>
inline constexpr OutputIt
transform(
        InputIt first,InputIt last,
        OutputIt t_first,
        Operation op)
{
    while(first!=last){
        *t_first++ = op(*first++);
    }
    return t_first;
}

template<
    class InputIt1,class InputIt2,
    class OutputIt,
    class Operation>
inline constexpr OutputIt
transform(
        InputIt1 first1,InputIt1 last1,
        InputIt2 first2,OutputIt t_first,
        Operation op)
{
    while(first1!=last1){
        *t_first++ = op(*first1++,*first2++);
    }
    return t_first;
}

}   // namespace algorithm
}   // namespace geko

#endif
