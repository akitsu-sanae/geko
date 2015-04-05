#ifndef GEKO_ALGORITHM_MIN_ELEMENT
#define GEKO_ALGORITHM_MIN_ELEMENT

namespace geko{
namespace algorithm{

template<class ForwardIt>
inline constexpr ForwardIt
min_element(ForwardIt first,ForwardIt last){
    if(first == last)return last;

    ForwardIt min_it = first;
    ++first;
    while(first!=last){
        if(*min_it > *first)min_it = first;
        ++first;
    }
    return first;
}

template<class ForwardIt,class Comp>
inline constexpr ForwardIt
min_element(
        ForwardIt first,ForwardIt last,
        Comp comp)
{
    if(first == last)return last;

    ForwardIt min_it = first;
    ++first;
    while(first!=last){
        if(comp(*min_it,*first))min_it = first;
        ++first;
    }
    return first;
}

}   // namespace algorithm
}   // namespace geko

#endif
