#pragma once

template <class VertexType>
struct ItemType
{
    // "<" means shorter distance.
    bool operator<(ItemType otherItem);
    bool operator==(ItemType otherItem);
    bool operator<=(ItemType otherItem);
    void operator=(ItemType otherItem);

    VertexType fromVertex;
    VertexType toVertex;
    int distance = 0; // Same as weight in this implementation.
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

template <class VertexType>
void ItemType<VertexType>::operator=(ItemType otherItem)
{
    otherItem.distance = distance;
    otherItem.fromVertex = fromVertex;
    otherItem.toVertex = toVertex;
}
