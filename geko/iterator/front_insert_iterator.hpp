/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_ITERATOR_FRONT_INSERT_ITERATOR_HPP
#define GEKO_ITERATOR_FRONT_INSERT_ITERATOR_HPP

#include <memory> // for std::addressof
#include <geko/iterator/tags.hpp>
#include <geko/iterator/iterator.hpp>

namespace geko {
namespace iterator {

template<typename Container>
struct front_insert_iterator :
    public geko::iterator<
        geko::iterator::output_iterator_tag,
        void, void, void, void>
{
    // member type
    using container_type = Container;

    // ctor
    explicit front_insert_iterator(container_type& c) :
        container(std::addressof(c))
    {}

    // operators
    front_insert_iterator<container_type>& operator=(typename container_type::value_type const& value) {
        container->push_front(value);
        return *this;
    }
    front_insert_iterator<container_type>& operator=(typename container_type::value_type&& value) {
        container->push_front(std::move(value));
        return *this;
    }

    front_insert_iterator<container_type>& operator*() { return *this; }
    front_insert_iterator<container_type>& operator++() { return *this; }
    front_insert_iterator<container_type>& operator++(int) { return *this; }

protected:
    container_type* container;
};

}
}

#endif

