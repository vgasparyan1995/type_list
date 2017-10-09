#pragma once

namespace TL {

struct NullType { };

template <typename HeadT, typename ... Args>
struct TypeList
{
    using HeadType = HeadT;
    using TailType = TypeList<Args ...>;
};

template <typename HeadT, typename TailHeadT, typename ... Args>
struct TypeList<HeadT, TypeList<TailHeadT, Args ...> >
{
    using HeadType = HeadT;
    using TailType = TypeList<TailHeadT, Args ...>;
};

template <typename HeadT>
struct TypeList<HeadT, NullType>
{
    using HeadType = HeadT;
    using TailType = NullType;
};

template <typename HeadT>
struct TypeList<HeadT>
{
    using HeadType = HeadT;
    using TailType = NullType;
};

} // namespace TL
