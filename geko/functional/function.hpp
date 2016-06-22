/*============================================================================
  Copyright (C) 2015-2016 akitsu sanae
  https://github.com/akitsu-sanae/geko
  Distributed under the Boost Software License, Version 1.0. (See accompanying
  file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
============================================================================*/

#ifndef GEKO_FUNCTIONAL_FUNCTION_HPP
#define GEKO_FUNCTIONAL_FUNCTION_HPP

#include <memory>

namespace geko {
namespace functional {

template<typename> struct function;

template<typename R, typename ... Args>
struct function<R (Args...)> {
    template<typename F>
    function(F const& f) {
        m_holder = std::make_unique<function_holder<F>>(f);
    }

    using result_type = R;
    struct bad_function_call {};

    auto operator()(Args&& ... args) const {
        if (m_holder)
            return m_holder->invoke(std::forward<Args>(args) ...);
        throw bad_function_call{};
    }

private:
    struct function_holder_base {
        virtual result_type invoke(Args&& ...) const = 0;
        virtual ~function_holder_base() {};
    };

    template<typename F>
    struct function_holder : function_holder_base {
        explicit function_holder(F const& f) :
            f(f)
        {}
        result_type invoke(Args&& ... args) const override {
            return f(std::forward<Args>(args) ...);
        }
        F const& f;
    };

    std::unique_ptr<function_holder_base> m_holder;
};


}
}

#endif

