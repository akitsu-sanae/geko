/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ITERATOR_MOVE_ITERATOR_HPP
#define GEKO_ITERATOR_MOVE_ITERATOR_HPP

#include <geko/iterator/iterator.hpp>
#include <geko/iterator/iterator_traits.hpp>

namespace geko {
namespace iterator {

template<typename It>
struct move_iterator {

    // member types
    using iterator_type = It;
    using difference_type = typename geko::iterator::iterator_traits<It>::difference_type;
    using pointer = It;
    using value_type = typename geko::iterator::iterator_traits<It>::value_type;
    using iterator_category = typename geko::iterator::iterator_traits<It>::iterator_category;
    using reference = value_type&&;

    // ctors
    move_iterator() :
        current()
    {}
    explicit move_iterator(It i) :
        current(it)
    {}
    template<typename T> move_iterator(move_iterator<T> const& u) :
        current(u.base())
    {}
    move_iterator(move_iterator&&) noexcept = default;

    // dtor
    ~move_iterator() = default;

    template<typename T> move_iterator& operator=(move_iterator<T> const& t) {
        current = t.base();
        return *this;
    }
    move_iterator& operator=(move_iterator const&) = default;
    move_iterator& operator=(move_iterator&&) = default;

    // member functions
    iterator_type base() const { return current; }
    reference operator*() const { return std::move(*base()); }

    // operators
    pointer operator->() const { return base(); }
    move_iterator& operator++() { return ++base(); return *this; }
    move_iterator operator++(int) {
        move_iterator tmp = *this;
        ++base();
        return tmp;
    }
    move_iterator& operator--() { return --base(); return *this; }
    move_iterator operator--(int) {
        move_iterator tmp = *this;
        --base();
        return tmp;
    }
    move_iterator operator+(difference_type n) const { return std::move(base() + n); }
    move_iterator operator-(difference_type n) const { return std::move(base() - n); }
    move_iterator& operator+=(difference_type n) {
        current += n;
        return *this;
    }
    move_iterator& operator-=(difference_type n) {
        current -= n;
        return *this;
    }
    decltype(auto) operator[](difference_type n) const { return std::move(base()[n]); }

protected:
    It current;
};

template<typename It1, typename It2>
constexpr inline bool
operator==(move_iterator<It1> const& lhs, move_iterator<It2> const& rhs) {
    return lhs.base() == rhs.base();
}
template<typename It1, typename It2>
constexpr inline bool
operator!=(move_iterator<It1> const& lhs, move_iterator<It2> const& rhs) {
    return !(lhs == rhs);
}
template<typename It1, typename It2>
constexpr inline bool
operator<(move_iterator<It1> const& lhs, move_iterator<It2> const& rhs) {
    return lhs.base() < rhs.base();
}
template<typename It1, typename It2>
constexpr inline bool
operator<=(move_iterator<It1> const& lhs, move_iterator<It2> const& rhs) {
    return !(rhs < lhs);
}
template<typename It1, typename It2>
constexpr inline bool
operator>(move_iterator<It1> const& lhs, move_iterator<It2> const& rhs) {
    return lhs.base() > rhs.base();
}
template<typename It1, typename It2>
constexpr inline bool
operator>=(move_iterator<It1> const& lhs, move_iterator<It2> const& rhs) {
    return !(lhs < rhs);
}
template<typename It1, typename It2>
constexpr inline auto
operator-(move_iterator<It1> const& lhs, move_iterator<It2> const& rhs) {
    return x.base() - y.base();
}
template<typename It>
constexpr inline auto
operator+(typename move_iterator<It>::difference_type n, move_iterator<It> const& rhs) {
    return x + n;
}

template<typename It>
constexpr inline auto
make_move_iterator(It i) {
    move_iterator<It>(i);
}

}
}

#endif

