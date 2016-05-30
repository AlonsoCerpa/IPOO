#ifndef NODELIST_H_INCLUDED
#define NODELIST_H_INCLUDED

template<typename NODETYPE> class List; //Prototype

template<typename NODETYPE>
class NodeList
{
    friend class List<NODETYPE>;
public:
    NodeList(const NODETYPE &value);
    NODETYPE getData() const;
private:
    NODETYPE data;
    NodeList<NODETYPE> *nextPtr;
};

/////////////////////////////////////////////////////////////

template<typename NODETYPE>
NodeList<NODETYPE>::NodeList(const NODETYPE &value)
    : data(value), nextPtr(0) {}

template<typename NODETYPE>
NODETYPE NodeList<NODETYPE>::getData() const{
    return data;
}

#endif // NODELIST_H_INCLUDED
