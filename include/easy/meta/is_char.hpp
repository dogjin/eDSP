/*
 * EasyMeta, Yet another header-only library for C++ meta-programming.
 * Copyright (C) 2018 Mohammed Boujemaoui Boulaghmoudi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along withº
 * this program.  If not, see <http://www.gnu.org/licenses/>
 *
 * Filename: is_char.hpp
 * Created at: 29/07/18
 * Created by: Mohammed Boujemaoui
 */

#ifndef EASYMETA_IS_CHAR_HPP
#define EASYMETA_IS_CHAR_HPP

#include <type_traits>

namespace easy { namespace meta {

    namespace {
        template <typename T, bool = std::is_same<T, char>::value || std::is_same<T, wchar_t>::value>
        struct _is_char : std::true_type {};

        template <typename T>
        struct _is_char<T, false> : std::false_type {};
    } // namespace

    template <typename T>
    struct is_char : _is_char<T>::type {};

    template <typename T>
    constexpr auto is_char_v = is_char<T>::value;

}} // namespace easy::meta

#endif //EASYMETA_IS_CHAR_HPP