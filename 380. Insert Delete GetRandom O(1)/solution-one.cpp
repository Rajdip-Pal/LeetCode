#include <iostream>
#include <unordered_set>

class RandomizedSet
{
    std::unordered_set<int> __collection;
    std::unordered_set<int>::iterator it;

public:
    RandomizedSet() {}

    bool insert(const int &val)
    {
        return __collection.insert(val).second;
    }

    bool remove(int val)
    {
        return __collection.erase(val);
    }

    int getRandom()
    {
        it = __collection.begin();
        std::advance(it, rand() % __collection.size());
        return *it;
    }
};
