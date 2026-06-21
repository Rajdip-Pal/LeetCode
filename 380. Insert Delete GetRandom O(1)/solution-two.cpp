#include <iostream>
#include <vector>
#include <unordered_map>

class RandomizedSet
{
    std::unordered_map<int, bool> __collection;
    std::unordered_map<int, bool>::iterator __iterator;

public:
    RandomizedSet() {}

    bool insert(const int &val)
    {
        if (__collection.find(val) != __collection.end())
            return false;
        return __collection[val] = true;
    }

    bool remove(int val)
    {
        if (__collection.find(val) == __collection.end())
            return false;
        return __collection.erase(val);
    }

    int getRandom()
    {
        __iterator = __collection.begin();
        std::advance(__iterator, rand() % __collection.size());
        return __iterator->first;
    }
};
