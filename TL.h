#pragma once

#include "TL_impl.h"

namespace TL {

template <typename T>
inline constexpr unsigned Length_v = Length<T>::value;

template <typename T, int I>
using TypeAt_t = typename TypeAt<T, I>::type;

template <typename TypeListT, typename T>
inline constexpr int IndexOf_v = IndexOf<TypeListT, T>::value;

template <typename TypeListT, typename T>
using Append_t = typename Append<TypeListT, T>::type;

template <typename TypeListT, typename T>
using EraseOne_t = typename EraseOne<TypeListT, T>::type;

template <typename TypeListT, typename T>
using EraseAll_t = typename EraseAll<TypeListT, T>::type;

} // namesapce TL
