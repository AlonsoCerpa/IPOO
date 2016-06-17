#ifndef CELLPHONES_H_INCLUDED
#define CELLPHONES_H_INCLUDED

class Cellphone
{
public:
    Cellphone();
    virtual ~Cellphone() = 0;
    virtual void getDescription() const = 0;
    static int totalCellp;
protected:
    int id;
};

///////////////////////////////////////////////////////////

class SamsungCheapCellp : public Cellphone
{
public:
    void getDescription() const;
};

class SamsungExpensiveCellp : public Cellphone
{
public:
    void getDescription() const;
};

class LGCheapCellp : public Cellphone
{
public:
    void getDescription() const;
};

class LGExpensiveCellp : public Cellphone
{
public:
    void getDescription() const;
};

//////////////////////////////////////////////////////////

class Factory
{
public:
    virtual ~Factory() = 0;
    virtual Cellphone* createCheapCellp() = 0;
    virtual Cellphone* createExpensiveCellp() = 0;
};

//////////////////////////////////////////////////////////

class SamsungFactory : public Factory
{
public:
    Cellphone* createCheapCellp();
    Cellphone* createExpensiveCellp();
};

class LGFactory : public Factory
{
public:
    Cellphone* createCheapCellp();
    Cellphone* createExpensiveCellp();
};

#endif // CELLPHONES_H_INCLUDED
