#pragma once

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

template <typename T, typename U>
inline constexpr bool IsSame_v = IsSame<T, U>::value;
