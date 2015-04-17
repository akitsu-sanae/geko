#ifndef GEKO_ALGORITHM_FIND_FIRST_OF
#define GEKO_ALGORITHM_FIND_FIRST_OF

namespace geko{
namespace algorithm{

template<class InputIt,class ForwardIt>
inline constexpr InputIt
find_first_of(
        InputIt first,InputIt last,
        ForwardIt t_first,ForwardIt t_last)
{
    while(first!=last){
        ForwardIt it = t_first;
        while(it!=t_last){
            if(*first==*it)return first;
            ++it;
        }
        ++first;
    }
    return last;
}

template<class InputIt,class ForwardIt,class Predicate>
inline constexpr InputIt
find_first_of(
        InputIt first,InputIt last,
        ForwardIt t_first,ForwardIt t_last,
        Predicate pred)
{
    while(first!=last){
        ForwardIt it = t_first;
        while(it!=t_last){
            if( pred(*first,*it)  )return first;
            ++it;
        }
        ++first;
    }
    return last;
}

}   // namespace algorithm
}   // namespace geko

#endif
