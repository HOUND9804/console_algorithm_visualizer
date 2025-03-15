#ifndef MY_UNORDERED_MAP_H
#define MY_UNORDERED_MAP_H

typedef unsigned long long size_t;  // Define size_t explicitly, this is the standard size for most systems

template <typename Key, typename Value, size_t TableSize = 1000>
class My_Unordered_Map {
public:
    My_Unordered_Map() {}

    bool contains(const Key& key) const {
        size_t index = customHash(key) % TableSize;
        for (size_t i = 0; i < TableSize; ++i) {
            size_t probeIndex = (index + i) % TableSize;
            if (table[probeIndex].occupied && table[probeIndex].key == key) {
                return true;
            }
        }
        return false;
    }

    void insert(const Key& key, const Value& value) {
        size_t index = customHash(key) % TableSize;
        for (size_t i = 0; i < TableSize; ++i) {
            size_t probeIndex = (index + i) % TableSize;
            if (!table[probeIndex].occupied || table[probeIndex].key == key) {
                table[probeIndex] = {key, value, true};
                return;
            }
        }
    }

    Value& operator[](const Key& key) {
        size_t index = customHash(key) % TableSize;
        for (size_t i = 0; i < TableSize; ++i) {
            size_t probeIndex = (index + i) % TableSize;
            if (table[probeIndex].occupied && table[probeIndex].key == key) {
                return table[probeIndex].value;
            }
            if (!table[probeIndex].occupied) {
                table[probeIndex] = {key, Value(), true};
                return table[probeIndex].value;
            }
        }
        static Value dummyValue; // Return a static dummy value if key not found
        return dummyValue;
    }

private:
    struct KeyValuePair {
        Key key;
        Value value;
        bool occupied = false;

        KeyValuePair() = default;
        KeyValuePair(const Key& k, const Value& v, bool occ) : key(k), value(v), occupied(occ) {}
    };

    // Custom hash function for pairs (assumes Key is a pair)
    size_t customHash(const Key& key) const {
        size_t hash1 = std::hash<typename Key::first_type>{}(key.first);
        size_t hash2 = std::hash<typename Key::second_type>{}(key.second);
        return hash1 ^ (hash2 << 1); // Better hash mixing
    }

    KeyValuePair table[TableSize];  // Fixed-size array
};

#endif // MY_UNORDERED_MAP_H

