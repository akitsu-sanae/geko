/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ITERATOR_REVERSE_ITERATOR_HPP
#define GEKO_ITERATOR_REVERSE_ITERATOR_HPP

#include <geko/iterator/iterator.hpp>
#include <geko/iterator/iterator_traits.hpp>

namespace geko {
namespace iterator {

template<typename It>
    struct reverse_iterator :
        public geko::iterator::iterator<
        typename geko::iterator::iterator_traits<It>::iterator_category,
        typename geko::iterator::iterator_traits<It>::value_type,
        typename geko::iterator::iterator_traits<It>::difference_type,
        typename geko::iterator::iterator_traits<It>::pointer,
        typename geko::iterator::iterator_traits<It>::reference
        >
{

    // member types
    using iterator_type = It;
    using difference_type = typename iterator_traits<It>::difference_type;
    using pointer = typename iterator_traits<It>::pointer;
    using reference = typename iterator_traits<It>::reference;

    // ctors
    reverse_iterator() {}
    explicit reverse_iterator(iterator_type it) :
        current(it)
    {}
    reverse_iterator(reverse_iterator<It> const& other) :
        current(other.m_current)
    {}

    template<typename OtherIt>
    reverse_iterator(reverse_iterator<OtherIt> const& other) :
        current(other.base())
    {}

    // member functions
    iterator_type base() const { return current; }


    // operator member functions
    reference operator*() const {
        auto tmp = current;
        --tmp;
        return *tmp;
    }

    pointer operator->() const { return &(operator*()); }

    reverse_iterator& operator++() {
        current--;
        return *this;
    }
    reverse_iterator operator++(int) {
        auto tmp = *this;
        current--;
        return tmp;
    }
    reverse_iterator& operator--() {
        current++;
        return *this;
    }
    reverse_iterator operator--(int) {
        auto tmp = *this;
        current++;
        return tmp;
    }

    reverse_iterator operator+(difference_type n) const {
        return reverse_iterator{current - n};
    }
    reverse_iterator& operator+=(difference_type n) {
        current -= n;
        return *this;
    }
    reverse_iterator operator-(difference_type n) const {
        return reverse_iterator{current + n};
    }
    reverse_iterator& operator-=(difference_type n) {
        current += n;
        return *this;
    }
    reference operator[](difference_type n) const {
        return *(*this + n);
    }
protected:
    It current;
};

// non member functions

template<typename It>
inline bool operator==(reverse_iterator<It> const& lhs, reverse_iterator<It> const& rhs) {
    return lhs.base() == rhs.base();
}
template<typename It>
inline bool operator!=(reverse_iterator<It> const& lhs, reverse_iterator<It> const& rhs) {
    return !(lhs == rhs);
}
template<typename It>
inline bool operator<(reverse_iterator<It> const& lhs, reverse_iterator<It> const& rhs) {
    return rhs.base() < lhs.base();
}
template<typename It>
inline bool operator>(reverse_iterator<It> const& lhs, reverse_iterator<It> const& rhs) {
    return rhs < lhs;
}
template<typename It>
inline bool operator<=(reverse_iterator<It> const& lhs, reverse_iterator<It> const& rhs) {
    return !(lhs > rhs);
}
template<typename It>
inline bool operator>=(reverse_iterator<It> const& lhs, reverse_iterator<It> const& rhs) {
    return !(lhs < rhs);
}
template<typename It>
inline typename reverse_iterator<It>::difference_type
operator-(reverse_iterator<It> const& lhs, reverse_iterator<It> const& rhs) {
    return rhs.base() - lhs.base();
}
template<typename It>
inline reverse_iterator<It>
operator+(typename reverse_iterator<It>::difference_type n, reverse_iterator<It> const& rhs) {
    return reverse_iterator<It>(rhs.base() - n);
}
template<typename It1, typename It2>
inline bool operator==(reverse_iterator<It1> const& lhs, reverse_iterator<It2> const& rhs) {
    return lhs.base() == rhs.base();
}
template<typename It1, typename It2>
inline bool operator!=(reverse_iterator<It1> const& lhs, reverse_iterator<It2> const& rhs) {
    return !(lhs == rhs);
}
template<typename It1, typename It2>
inline bool operator<(reverse_iterator<It1> const& lhs, reverse_iterator<It2> const& rhs) {
    return rhs.base() < lhs.base();
}
template<typename It1, typename It2>
inline bool operator>(reverse_iterator<It1> const& lhs, reverse_iterator<It2> const& rhs) {
    return rhs < lhs;
}
template<typename It1, typename It2>
inline bool operator<=(reverse_iterator<It1> const& lhs, reverse_iterator<It2> const& rhs) {
    return !(rhs < lhs);
}
template<typename It1, typename It2>
inline bool operator >=(reverse_iterator<It1> const& lhs, reverse_iterator<It2> const& rhs) {
    return !(lhs < rhs);
}
template<typename It1, typename It2>
inline auto operator-(reverse_iterator<It1> const& lhs, reverse_iterator<It2> const& rhs) {
    return rhs.base() - lhs.base();
}

template<typename It>
inline constexpr auto make_reverse_iterator(It i) {
    return reverse_iterator<It>(i);
}


}
}

#endif

