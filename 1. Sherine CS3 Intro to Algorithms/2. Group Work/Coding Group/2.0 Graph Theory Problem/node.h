/*
Unfortunately because this class is templated, we must include all implementation inside of the class itself.
*/
#pragma once

// ***ADJACENT NOT COMPLETE*** (unsure of what it needs to do).
template <class T>
class Node
{
    public:
        Node()
        {
            int tempVertex[1];
            for (int i = 0; i < 2; i++)
            {
                tempVertex[i] = 0;
            }
            setVertex(tempVertex);

            int tempEdge[1];
            for (int i = 0; i < 2; i++)
            {
                tempEdge[i] = 0;
            }
        }

        // Getters
        int getVertex() {return _vertex;}
        int getEdge() {return _edge;}
        int** getAdjacent() {return _adjacent;}

        // Setters
        void setVertex(int passedVertex) {_vertex = passedVertex;}
        void setEdge(int passedEdge) {_edge = passedEdge;}
        void setAdjacent(int** passedAdjacent) {_adjacent = passedAdjacent;}
    
    private:
        int _vertex, _edge; // ***_edge[x,y] = _edge[Directed, Weight]***;
        int** _adjacent;
};