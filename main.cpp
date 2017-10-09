#include <iostream>

#include "TL.h"
#include "TestUtils.h"

using T1 = TL::TypeList<int, int, int*, char, double, bool>;
using T2 = TL::TypeList<unsigned char, unsigned short, unsigned int, unsigned long int, unsigned long long int>;
using T3 = TL::TypeList<char*>;

void testLength()
{
    std::cout << "== Length ==" << std::endl;
    PB((TL::Length_v<T1> == 6));
    PB((TL::Length_v<T2> == 5));
    PB((TL::Length_v<T3> == 1));
}

void testTypeAt()
{
    std::cout << "== TypeAt ==" << std::endl;
    PB((IsSame_v<TL::TypeAt_t<T1, 0>, int>));
    PB((IsSame_v<TL::TypeAt_t<T1, 1>, int>));
    PB((IsSame_v<TL::TypeAt_t<T1, 2>, int*>));
    PB((!IsSame_v<TL::TypeAt_t<T1, 5>, int*>));
    PB((IsSame_v<TL::TypeAt_t<T1, 5>, bool>));
}

void testIndexOf()
{
    std::cout << "== IndexOf ==" << std::endl;
    PB((TL::IndexOf_v<T1, int> == 0));
    PB((TL::IndexOf_v<T1, int*> == 2));
    PB((TL::IndexOf_v<T1, bool> == 5));
    PB((TL::IndexOf_v<T1, long double> == -1));
    PB((TL::IndexOf_v<T3, char*> == 0));
}

template <typename T1, typename T2>
void debug(T1, T2)
{}

void testAppend()
{
    std::cout << "== Append ==" << std::endl;
    PB((IsSame_v<TL::TypeList<int, int, int*, char, double, bool, char>, TL::Append_t<T1, char> >));

    debug(TL::TypeList<int, int, int*, char, double, bool, char>(), TL::Append_t<T1, char>() );

    PB((IsSame_v<TL::TypeList<unsigned char, unsigned short, unsigned int, unsigned long int, unsigned long long int, char>, TL::Append_t<T2, char> >));
    PB((IsSame_v<TL::TypeList<char*, char>, TL::Append_t<T3, char> >));
}

void testEraseOne()
{
    std::cout << "== EraseOne ==" << std::endl;
    PB((IsSame_v<TL::TypeList<int, int*, char, double, bool>, TL::EraseOne_t<T1, int> >));
    PB((IsSame_v<TL::TypeList<int, int, char, double, bool>, TL::EraseOne_t<T1, int*> >));
    PB((IsSame_v<TL::TypeList<int, int, int*, char, double>, TL::EraseOne_t<T1, bool> >));
    PB((IsSame_v<TL::NullType, TL::EraseOne_t<T3, char*> >));
}

void testEraseAll()
{
    std::cout << "== EraseAll ==" << std::endl;
    PB((IsSame_v<TL::TypeList<int*>, TL::EraseAll_t<TL::TypeList<int, int, int*, int>, int> >));
    PB((IsSame_v<TL::TypeList<bool, char>, TL::EraseAll_t<TL::TypeList<bool, char, int*>, int> >));
    PB((IsSame_v<TL::TypeList<bool>, TL::EraseAll_t<TL::TypeList<int, bool>, int> >));
    PB((IsSame_v<TL::NullType, TL::EraseAll_t<TL::TypeList<int, int>, int> >));
}

int main()
{
    testLength();
    testTypeAt();
    testIndexOf();
    testAppend();
    testEraseOne();
    testEraseAll();
}
