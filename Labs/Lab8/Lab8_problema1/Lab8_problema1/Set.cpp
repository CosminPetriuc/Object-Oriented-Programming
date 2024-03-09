#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

template<typename TElem>
class Set
{
    //DO NOT CHANGE THIS PART
    friend class SetIterator;

private:
    //array of elements
    std::vector<TElem> e;
    

public:
    //implicit constructor
    Set()
    {

    }

    //adds an element to the set
    //returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
    bool add(TElem elem)
    {
        for (int i = 0; i < e.size(); i++)//traverse the array
        {
            if (this->e[i] == elem)
                return false;
        }
        e.push_back(elem);
        return true;
    }

    //removes an element from the set
    //returns true if e was removed, false otherwise
    void del(TElem elem)
    {
        int i = 0;
        bool found = false;
        while (i < e.size() && !found)// O(n)
        {
            if (this->e[i] == elem)//O(1)
            {
                found = true;
                e.erase(i);
            }
            else
                i++;
        }
    }
    

    //checks whether an element belongs to the set or not
    bool search(TElem elem) const
    {
        for (int i = 0; i < e.size(); i++) {
            if (this->e[i] == elem) {
                return true;
            }
        }
        return false;
    }

    //returns the number of elements;
    int size() const
    {
        return (int)e.size();
    }

    //check whether the set is empty or not;
    bool isEmpty() const
    {
        return e.size() == 0;
    }

    // destructor
    ~Set()
    {
        e.clear();
    }

};