#ifndef GEKO_ALGORITHM_MAX_ELEMENT
#define GEKO_ALGORITHM_MAX_ELEMENT

namespace geko{
namespace algorithm{

template<class ForwardIt>
inline constexpr ForwardIt
max_element(ForwardIt first,ForwardIt last){
    if(first == last)return last;

    ForwardIt max_it = first;
    ++first;
    while(first!=last){
        if(*max_it < *first)max_it = first;
        ++first;
    }
    return first;
}

template<class ForwardIt,class Comp>
inline constexpr ForwardIt
max_element(
        ForwardIt first,ForwardIt last,
        Comp comp)
{
    if(first == last)return last;

    ForwardIt max_it = first;
    ++first;
    while(first!=last){
        if(comp(*max_it,*first))max_it = first;
    }
    return first;
}

}   // namespace algorithm
}   // namespace geko

#endif
