#pragma once

template <class VertexType>
struct ItemType
{
    ItemType()
    {
        distance = 0;
    }
    // "<" means shorter distance.
    bool operator<(ItemType otherItem);
    bool operator==(ItemType otherItem);
    bool operator<=(ItemType otherItem);

    VertexType fromVertex;
    VertexType toVertex;
    int distance; // Same as weight in this implementation.
    // bool isMarked = false;
};


template <class VertexType>
bool ItemType<VertexType>::operator<(ItemType otherItem)
{
    if (otherItem.distance < distance)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class VertexType>
bool ItemType<VertexType>::operator==(ItemType otherItem)
{
    return (otherItem.distance == distance);
}

template <class VertexType>
bool ItemType<VertexType>::operator<=(ItemType otherItem)
{
    if (otherItem.distance <= distance)
    {
        return true;
    }
    else
    {
        return false;
    }
}
