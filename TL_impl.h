#pragma once

#include "TypeList.h"
#include "TypeUtil.h"

namespace TL {

/******** Length ********/
template <typename TypeListT>
struct Length
{
    static const unsigned value = 1 + Length<typename TypeListT::TailType>::value;
};

template <>
struct Length<NullType>
{
    static const unsigned value = 0;
};

/******** TypeAt ********/
template <typename TypeListT, unsigned Index>
struct TypeAt
{
    static_assert(!IsSame_v<typename TypeListT::TailType, NullType>, "Index is out of range.");
    using type = typename TypeAt<typename TypeListT::TailType, Index - 1>::type;
};

template <typename TypeListT>
struct TypeAt<TypeListT, 0U>
{
    using type = typename TypeListT::HeadType;
};

/******** IndexOf ********/
template <typename TypeListT, typename T, int Index = 0>
struct IndexOf
{
    static const int value = IsSame_v<typename TypeListT::HeadType, T> ? Index : IndexOf<typename TypeListT::TailType, T, Index + 1>::value;
};

template <typename T, int Index>
struct IndexOf<NullType, T, Index>
{
    static const int value = -1;
};

/******** Append ********/
template <typename TypeListT, typename T>
struct Append;

template <>
struct Append<NullType, NullType>
{
    using type = NullType;
};

template <typename T>
struct Append<NullType, T>
{
    using type = TypeList<T>;
};

template <typename ... Args>
struct Append<NullType, TypeList<Args ...> >
{
    using type = TypeList<Args ...>;
};

template <typename HeadT, typename T, typename ... Args>
struct Append<TypeList<HeadT, Args ...>, T>
{
    using type = TypeList<HeadT, typename Append<typename TypeList<HeadT, Args ...>::TailType, T>::type>;
};

/******** EraseOne ********/
template <typename TypeListT, typename T>
struct EraseOne;

template <typename T>
struct EraseOne<NullType, T>
{
    using type = NullType;
};

template <typename T, typename HeadT, typename ... Args>
struct EraseOne<TypeList<HeadT, Args ...>, T>
{
    using type = TypeList<HeadT, typename EraseOne<typename TypeList<HeadT, Args ...>::TailType, T>::type>;
};

template <typename T, typename ... Args>
struct EraseOne<TypeList<T, Args ...>, T>
{
    using type = typename TypeList<T, Args ...>::TailType;
};

/******** EraseAll ********/
template <typename TypeListT, typename T>
struct EraseAll;

template <typename T>
struct EraseAll<NullType, T>
{
    using type = NullType;
};

template <typename HeadT, typename T, typename ... Args>
struct EraseAll<TypeList<HeadT, Args ...>, T>
{
    using type = TypeList<HeadT, typename EraseAll<typename TypeList<HeadT, Args ...>::TailType, T>::type>;
};

template <typename T, typename ... Args>
struct EraseAll<TypeList<T, Args ...>, T>
{
    using type = typename EraseAll<typename TypeList<T, Args ...>::TailType, T>::type;
};

} // namesapce TL
