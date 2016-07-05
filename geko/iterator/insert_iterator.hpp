/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ITERATOR_INSERT_ITERATOR_HPP
#define GEKO_ITERATOR_INSERT_ITERATOR_HPP

#include <geko/memory/addressof.hpp>
#include <geko/iterator/tags.hpp>
#include <geko/iterator/iterator.hpp>

template<typename Container>
struct insert_iterator :
    public geko::iterator<
        geko::iterator::output_iterator_tag,
        void, void, void, void>
{
    // member type
    using container_type = Container;

    // ctor
    explicit insert_iterator(container_type& c, typename container_type::iterator i) :
        container(geko::memory::addressof(c)),
        iter(i)
    {}

    // operators
    insert_iterator<container_type>& operator=(typename container_type::value_type const& value) {
        iter = container->insert(iter, value);
        ++iter;
        return *this;
    }
    insert_iterator<container_type>& operator=(typename container_type::value_type&& value) {
        iter = container->insert(iter, std::move(value));
        ++iter;
        return *this;
    }

    // for satisfy the requirement of OutputIterator
    insert_iterator<container_type>& operator*() { return *this; }
    insert_iterator<container_type>& operator++() { return *this; }
    insert_iterator<container_type>& operator++(int) { return *this; }

protected:
    container_type* container;
    typename container_type::iterator iter;
};

template<typename Container>
inline constexpr insert_iterator<Container> inserter(Container& c, typename Container::iterator i) {
    return insert_iterator<Container>(c, i);
}

#endif

