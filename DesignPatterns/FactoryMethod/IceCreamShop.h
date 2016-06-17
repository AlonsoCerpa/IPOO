#ifndef ICECREAMSHOP_H_INCLUDED
#define ICECREAMSHOP_H_INCLUDED

class IceCream
{
public:
    virtual ~IceCream() = 0;
    static IceCream *makeIceCream(int choice);
    virtual void getInfoIC() = 0;
};

////////////////////////////////////////////////////////////

class ChocolateIC : public IceCream
{
public:
    virtual void getInfoIC();
};

class VanillaIC : public IceCream
{
public:
    virtual void getInfoIC();
};

class LucumaIC : public IceCream
{
public:
    virtual void getInfoIC();
};

#endif // ICECREAMSHOP_H_INCLUDED
