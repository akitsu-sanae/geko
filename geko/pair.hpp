/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_PAIR_HPP
#define GEKO_PAIR_HPP

#include <type_traits>
#include <utility>

namespace geko {

template<typename T1, typename T2>
struct pair {
    using first_type = T1;
    using second_type = T2;

    // ctor
    constexpr pair(){}

    template<typename T, typename U>
    constexpr pair(T const& f, U const& s) :
        first(f),
        second(s)
    {}
    template<typename T, typename U>
    pair(T&& f, U&& s) :
        first(std::move(f)),
        second(std::move(s))
    {}
    template<typename T, typename U>
    pair(pair<T, U> const& rhs) :
        first(rhs.first),
        second(rhs.second)
    {}
    template<typename T, typename U>
    pair(pair<T, U>&& rhs) :
        first(std::move(rhs.first)),
        second(std::move(rhs.second))
    {}

    pair(pair<first_type, second_type> const& rhs) :
        first(rhs.first),
        second(rhs.second)
    {}
    pair(pair<first_type, second_type>&& rhs) :
        first(std::move(rhs.first)),
        second(std::move(rhs.second))
    {}


    // member function

    template<typename T, typename U>
    pair<first_type, second_type>& operator=(pair<T, U> const& rhs) {
        first = rhs.first;
        second = rhs.second;
        return *this;
    }
    template<typename T, typename U>
    pair<first_type, second_type> operator=(pair<T, U>&& rhs) {
        first = std::move(rhs.first);
        second = std::move(rhs.second);
        return *this;
    }
    pair<first_type, second_type>& operator=(pair<first_type, second_type> const& rhs) {
        first = rhs.first;
        second = rhs.second;
        return *this;
    }
    pair<first_type, second_type>& operator=(pair<first_type, second_type>&& rhs) {
        first = std::move(rhs.first);
        second = std::move(rhs.second);
        return *this;
    }

    void swap(pair<first_type, second_type>& other) noexcept {
        auto tmp = std::move(other);
        other = std::move(*this);
        *this = std::move(tmp);
    }

    first_type first;
    second_type second;
};

template<typename T1, typename T2>
inline static auto make_pair(T1&& v1, T2&& v2) {
    using return_type = pair<typename std::decay<T1>::type, typename std::decay<T2>::type>;
    return return_type{std::forward<T1>(v1), std::forward<T2>(v2)};
}

template<typename T1, typename T2>
inline static bool operator==(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs) {
    return lhs.first == rhs.first && lhs.second == rhs.second;
}
template<typename T1, typename T2>
inline static bool operator!=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs) {
    return !(lhs == rhs);
}
template<typename T1, typename T2>
inline static bool operator<(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs) {
    if (lhs.first != rhs.first)
        return lhs.first < rhs.first;
    else
        return lhs.second < rhs.second;
}
template<typename T1, typename T2>
inline static bool operator<=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs) {
    if (lhs.first != rhs.first)
        return lhs.first <= rhs.first;
    else
        return lhs.second <= rhs.second;
}
template<typename T1, typename T2>
inline static bool operator>(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs) {
    if (lhs.first != rhs.first)
        return lhs.first > rhs.first;
    else
        return lhs.second > rhs.second;
}
template<typename T1, typename T2>
inline static bool operator>=(pair<T1, T2> const& lhs, pair<T1, T2> const& rhs) {
    if (lhs.first != rhs.first)
        return lhs.first >= rhs.first;
    else
        return lhs.second >= rhs.second;
}

}

#endif

