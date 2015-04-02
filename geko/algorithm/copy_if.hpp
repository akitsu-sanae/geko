#ifndef GEKO_ALGORITHM_COPY_IF
#define GEKO_ALGORITHM_COPY_IF

namespace geko{
namespace algorithm{

template<
    class InputIt,class OutputIt,
    class Predicate
    >
inline constexpr OutputIt
copy_if(
        InputIt first,InputIt last,
        OutputIt dist,
        Predicate pred)
{
    while(first != last){
        if( pred(*first) )*dist++ = *first;
        first++;
    }
    return dist;
}

}   // namespace algorithms
}   // namespace geko

#endif
