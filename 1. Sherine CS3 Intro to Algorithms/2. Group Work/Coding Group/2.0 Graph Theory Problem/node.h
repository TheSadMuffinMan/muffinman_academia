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
            setEdge(tempEdge);

            // Initialize _adjacent.
        }

        // Getters
        int* getVertex() {return _vertex;}
        int getEdge() {return _edge;}
        int** getAdjacent() {return _adjacent;}

        // Setters
        void setVertex(int passedVertex) {_vertex = passedVertex;}
        void setEdge(int passedEdge) {_edge = passedEdge;}
        void setAdjacent(int** passedAdjacent) {_adjacent = passedAdjacent;}

        // Operator overloading for ease of class use.
        std::ostream& operator<<(std::ostream& outputStream, const T& passedNode)
        {
            printf("(x,y): (%d,%d)", _vertex[0], _vertex[1]);
            // outputStream << "(x,y): (" << _vertex[0] << "," << _vertex[1] << ")" << std::endl;
            return outputStream;

            // ADD MORE LATER ONCE NEEDED.
        }
    
    private:
        int _vertex[1];
        int _edge; // ***_edge[x,y] = _edge[Directed, Weight]***;
        int** _adjacent;
};