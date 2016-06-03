#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <vector>
#include <map>

using std::vector;
using std::map;

class Graph
{
public:
    Graph(const vector<int> &starts, const vector<int> &ends);
    unsigned numOutgoing(const int nodeID) const;
    const vector<int> &adjacent(const int nodeID) const;
private:
    map<int, vector<int> > outgoingEdges;
};

#endif // GRAPH_H_INCLUDED
