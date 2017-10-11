#pragma once

#include "TypeList.h"

template <typename T, typename U>
struct IsSame
{
    static const bool value = false;
};

template <typename T>
struct IsSame<T, T>
{
    static const bool value = true;
};

template <typename TypeListT1, typename TypeListT2>
struct IsSameTypeList
{
    static const bool value = IsSameTypeList<typename TypeListT1::HeadType, typename TypeListT2::HeadType>::value &&
                              IsSameTypeList<typename TypeListT1::TailType, typename TypeListT2::TailType>::value;
};

template <typename HeadT, typename ... Args>
struct IsSameTypeList<TL::TypeList<HeadT, Args ...>, TL::NullType>
{
    static const bool value = false;
};

template <typename HeadT, typename ... Args>
struct IsSameTypeList<TL::NullType, TL::TypeList<HeadT, Args ...> >
{
    static const bool value = false;
};

template <typename T>
struct IsSameTypeList<T, T>
{
    static const bool value = true;
};

template <typename T, typename U>
inline constexpr bool IsSame_v = IsSame<T, U>::value;

template <typename TypeListT1, typename TypeListT2>
inline constexpr bool IsSameTypeList_v = IsSameTypeList<TypeListT1, TypeListT2>::value;
