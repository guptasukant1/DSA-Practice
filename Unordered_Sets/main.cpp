#include<bits/stdc++.h>
using namespace std;

struct badHash {
    size_t operator()(int x) const {
        return 1;
    }
};

int main() {
    unordered_set<int> s;
    // Uses hash<T> internally. For int -> Identity function. strings -> character combinations per bucket using multiplication
    // and bit mixing. Hash fns should be -fast -spread values evenly -minimise collisions.
    // Collisions: Multiple values per bucket. Rehash(recalculation of hashes and bucket allocation) occurs with each insertion
    // Bucket count => Initial Bucket Array -> each insert computes hash -> index = hash % bucket_count
    // -> if load factor > threshold (usually 1) then rehash. 
    // load_factor = size / bucket_count
    // index = hash_value / bucket_count
    for(int i = 1; i <= 12; i++) {
        s.insert(i); // * Insertion is not ordered or sorted, it is random.
    }

    for(auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;
    int n = 11;
    if(s.find(n) != s.end()) cout << "The element exists" << endl;
    else cout << "Element does not exist" << endl;

    cout << endl;
    s.erase(s.begin());
    for(auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    cout << s.bucket_count() << endl;
    cout << s.load_factor() << endl;
    cout << s.max_load_factor() << endl;


    unordered_set<int, badHash> s1;
    for(int i = 1; i <= 10000; i++) {
        s1.insert(i);
    }
    // 10000 elements all assigned to the same bucket as the hash value for the hash fn is constant.
    // If hash value is fixed, then in order to maintain the 
    // load_factor(calculated per insert along with hash recalc which does not happen here) under 1 ->
    // the bucket count must be increased
    // Hash flooding -> all values in 1 bucket, remaining buckets empty
    // Bucket count tends to prime nos as modulo of prime distributes the values/patterns evenly
    cout << "Size: " << s1.size() << endl;
    cout << "Bucket count: " << s1.bucket_count() << endl;
    cout << "Load factor: " << s1.load_factor() << endl;

    for (int i = 0; i < s1.bucket_count(); i++) {
        if (s1.bucket_size(i) > 0) {
            cout << "Bucket " << i << " has "
                << s1.bucket_size(i) << " elements\n";
        } 
    }
    // badHash uses 
    // RETURNS: BUCKET 2 HAS 10000 ELEMENTS. It is a gamble by hash fn to get O(1) access. Trees guarentee O(log n)
}