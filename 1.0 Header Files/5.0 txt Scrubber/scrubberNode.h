#pragma once

template <class DataType>
class Node
{
    public:
        Node();
        // ~Node();
        void setData(DataType);
        void setLeft(Node<DataType>*);
        void setRight(Node<DataType>*);
        DataType getData();
        Node<DataType>* getLeft();
        Node<DataType>* getRight();

    private:
        DataType _data;
        Node<DataType>* _left;
        Node<DataType>* _right;
};

template <class DataType>
Node<DataType>::Node()
{
    _left = nullptr;
    _right = nullptr;
}

template <class DataType>
void Node<DataType>::setData(DataType passedData)
{
    _data = passedData;
}

template <class DataType>
void Node<DataType>::setLeft(Node<DataType>* passedLeft)
{
    _left = passedLeft;
}

template <class DataType>
void Node<DataType>::setRight(Node<DataType>* passedRight)
{
    _right = passedRight;
}

template <class DataType>
DataType Node<DataType>::getData()
{
    return _data;
}

template <class DataType>
Node<DataType>* Node<DataType>::getLeft()
{
    return _left;
}

template <class DataType>
Node<DataType>* Node<DataType>::getRight()
{
    return _right;
}