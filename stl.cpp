#include <bits/stdc++.h>
using namespace std;

// ============================================================
//  BASICS
// ============================================================

void print() {
    cout << "print function";
}

int sum(int a, int b) {
    return a + b;
}


// ============================================================
//  STRING  
// ============================================================

void explainString() {
    string s = "hello";

    s.push_back('!');    // "hello!"
    s.pop_back();        // "hello"
    s += " world";       // "hello world"
    s.append(" world");  // same as +=

    cout << s.length();  // or s.size()
    cout << s[0];        // 'h'
    cout << s.front();   // 'h'
    cout << s.back();    // 'd'

    // substr(start, length)
    cout << s.substr(0, 5); // "hello"

    // find — returns index, or string::npos if not found
    int pos = s.find("world"); // 6
    if (pos != string::npos) cout << "found at " << pos;

    s.erase(5, 6);        // erase 6 chars from index 5
    s.insert(5, " C++");  // insert at index 5

    sort(s.begin(), s.end()); // sort characters

    // convert
    int n    = stoi("42");    // string → int
    string t = to_string(42); // int → string

    // begin, end, rbegin, rend, clear, empty, swap — same as vector
}


// ============================================================
//  PAIR
// ============================================================

void explainPair() {
    pair<int, int> p = {1, 5};
    cout << p.first << " " << p.second;           // 1 5

    pair<int, pair<int, int>> p1 = {2, {4, 7}};   // nested pair
    cout << p1.first << " " << p1.second.first << " " << p1.second.second; // 2 4 7

    pair<int, int> arr[] = {{2, 3}, {4, 6}, {5, 8}};
    cout << arr[1].second;                         // 6
}


// ============================================================
//  VECTOR  (dynamic array)
// ============================================================

void explainVector() {
    vector<int> v;
    v.push_back(1);    // {1}
    v.emplace_back(2); // {1,2}  — faster than push_back

    vector<pair<int, int>> vp;
    vp.push_back({3, 7});  // must wrap in braces
    vp.emplace_back(2, 5); // auto-constructs pair

    vector<int> v2(5);      // {0,0,0,0,0}
    vector<int> v3(5, 13);  // {13,13,13,13,13}
    vector<int> v4(v3);     // copy of v3

    vector<int> v5 = {1, 4, 2, 5, 9};

    // --- iterators ---
    auto it = v5.begin();  // points to first element
    it++;
    cout << *it;           // 4
    it = it + 2;
    cout << *it;           // 5

    // v5.end()   → past-the-last  (iterate with it--)
    // v5.rbegin()→ last element   (iterate with it++)
    // v5.rend()  → before-first   (iterate with it--)

    cout << v5.back();     // last element: 9
    cout << v5[0];         // 1
    cout << v5.at(1);      // 4  (same as [], rarely used)

    // --- loops ---
    for (auto it = v5.begin(); it != v5.end(); it++)
        cout << *it << " ";

    for (auto x : v5)      // range-for (preferred)
        cout << x << " ";

    // --- erase ---
    v5.erase(v5.begin() + 1);        // remove index 1
    v5.erase(v5.begin() + 1, v5.begin() + 3); // remove [1, 3)

    // --- insert ---
    v5.insert(v5.begin(), 30);        // {30, ...}
    v5.insert(v5.begin() + 1, 2, 25); // insert 25 twice at index 1
    v5.insert(v5.begin(), v4.begin(), v4.end()); // prepend v4

    cout << v5.size();
    v5.pop_back();   // remove last
    v5.swap(v4);     // swap contents
    v5.clear();
    cout << v5.empty(); // 1
}


// ============================================================
//  LIST  (doubly linked list)
// ============================================================

void explainList() {
    list<int> ls;
    ls.push_back(2);    // {2}
    ls.emplace_back(5); // {2,5}
    ls.push_front(3);   // {3,2,5}
    ls.emplace_front(6);// {6,3,2,5}
    // begin, end, rbegin, rend, clear, insert, size, swap — same as vector
}


// ============================================================
//  DEQUE  (double-ended queue)
// ============================================================

void explainDeque() {
    deque<int> dq;
    dq.push_back(2);    // {2}
    dq.emplace_back(5); // {2,5}
    dq.push_front(3);   // {3,2,5}
    dq.emplace_front(6);// {6,3,2,5}
    dq.pop_back();      // {6,3,2}
    dq.pop_front();     // {3,2}
    dq.back();
    dq.front();
    // begin, end, rbegin, rend, clear, insert, size, swap — same as vector
}


// ============================================================
//  STACK  (LIFO)
// ============================================================

void explainStack() {
    stack<int> st;
    st.push(1);    // {1}
    st.push(2);    // {1,2}
    st.push(3);    // {1,2,3}
    st.push(3);    // {1,2,3,3}
    st.emplace(5); // {1,2,3,3,5}

    cout << st.top(); // 5  ← top is last-in
    st.pop();         // {1,2,3,3}
    cout << st.top(); // 3

    cout << st.size();  // 4
    cout << st.empty(); // 0

    stack<int> st1, st2;
    st1.swap(st2);
}


// ============================================================
//  QUEUE  (FIFO)
// ============================================================

void explainQueue() {
    queue<int> q;
    q.push(1);    // {1}
    q.push(2);    // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() += 5;   // {1,2,9}
    cout << q.back(); // 9
    cout << q.front();// 1
    q.pop();          // removes front → {2,9}
    cout << q.front();// 2
    // size, swap, empty — same as stack
}


// ============================================================
//  PRIORITY QUEUE  (heap)
// ============================================================

void explainPriorityQueue() {
    // --- max heap (default) ---
    priority_queue<int> maxpq;
    maxpq.push(5);    // {5}
    maxpq.push(2);    // {5,2}
    maxpq.emplace(8); // {8,5,2}
    cout << maxpq.top(); // 8
    maxpq.pop();
    cout << maxpq.top(); // 5

    // --- min heap ---
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(5);    // {5}
    minpq.push(2);    // {2,5}
    minpq.emplace(8); // {2,5,8}
    cout << minpq.top(); // 2

    // size, swap, empty — same as stack
}


// ============================================================
//  SET  (sorted + unique)
// ============================================================

void explainSet() {
    set<int> st;
    st.insert(1);  // {1}
    st.emplace(2); // {1,2}
    st.insert(2);  // {1,2}   duplicate ignored
    st.insert(4);  // {1,2,4}
    st.insert(3);  // {1,2,3,4}

    // begin, end, rbegin, rend, empty, size, swap — same as above

    auto it = st.find(3); // iterator to 3
    auto it2 = st.find(6);// points to end() — not found

    st.erase(5);          // no-op if not present
    int cnt = st.count(4);// 0 or 1

    auto it3 = st.find(2);
    st.erase(it3);         // O(1) with iterator

    auto it4 = st.find(1);
    auto it5 = st.find(4);
    st.erase(it4, it5);    // erase [it4, it5)

    auto lb = st.lower_bound(2); // first element >= 2
    auto ub = st.upper_bound(4); // first element >  4
    // all operations O(log n)
}


// ============================================================
//  MULTISET  (sorted, allows duplicates)
// ============================================================

void explainMultiset() {
    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); // {1,1,1}

    ms.erase(1);               // removes ALL 1s
    int cnt = ms.count(1);     // 3 (before erase)

    ms.erase(ms.find(1));                        // remove one 1
    ms.erase(ms.find(1), next(ms.find(1), 2));   // remove two 1s

    // other funcs same as set
}


// ============================================================
//  UNORDERED SET  (unique, no order)
// ============================================================

void explainUSet() {
    unordered_set<int> st; // underscore required
    // lower_bound / upper_bound NOT available
    // rest same as set
    // O(1) avg, O(n) worst case (rare hash collision)
}


// ============================================================
//  MAP  (sorted by key, unique keys)
// ============================================================

void explainMap() {
    map<int, int> mp;
    map<int, pair<int, int>> mp2;
    map<pair<int, int>, int> mp3;

    mp[1] = 2;
    mp.emplace(3, 1);
    mp.insert({2, 4});
    mp3[{2, 3}] = 10;

    for (auto& [key, val] : mp)   // structured binding (C++17)
        cout << key << " " << val;

    cout << mp[1]; // 2
    cout << mp[5]; // 0 — inserts default value if missing!

    auto it = mp.find(3);
    cout << (*it).second; // same as it->second (changed from original)

    auto it2 = mp.find(5); // returns end() if not found

    auto lb = mp.lower_bound(2);
    auto ub = mp.upper_bound(3);

    // erase, swap, size, empty — same as set
}


// ============================================================
//  MULTIMAP  (sorted, duplicate keys allowed)
// ============================================================

void explainMultimap() {
    // same as map, but mp[key] is NOT available (ambiguous)
}


// ============================================================
//  UNORDERED MAP  (unique keys, no order)
// ============================================================

void explainUnorderedMap() {
    // same tradeoff as unordered_set vs set: O(1) avg, O(n) worst
}


// ============================================================
//  ALGORITHMS
// ============================================================

bool cmpBySecondDescFirst(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second < b.second; // sort by second asc
    return a.first > b.first;                             // tie-break: first desc
}

void explainAlgo() {
    int a[] = {3, 1, 4, 1, 5};
    int n = 5;

    sort(a, a + n);                  // array sort
    sort(a + 2, a + 4);             // sort subrange [2, 4)
    sort(a, a + n, greater<int>()); // descending  ← note: ()

    vector<int> v = {3, 1, 4};
    sort(v.begin(), v.end());

    pair<int, int> pa[] = {{2, 1}, {1, 2}, {4, 1}};
    sort(pa, pa + 3, cmpBySecondDescFirst);

    // --- bit tricks ---
    int num = 7;                           // binary: 111
    int cnt = __builtin_popcount(num);     // 3  — count set bits (int)

    long long big = 23942931226161LL;
    int cnt2 = __builtin_popcountll(big);  // count set bits (long long)

    // --- permutations ---
    string s = "123";
    sort(s.begin(), s.end()); // must start sorted for all permutations
    do {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end())); // 123 132 213 231 312 321

    // --- other ---
    int mx = *max_element(a, a + n); // max value in array
    int mn = *min_element(a, a + n); // min value in array
    bool sorted = is_sorted(a, a + n);

    // --- INT limits (image: "Tools: INT_MAX/MIN") ---
    cout << INT_MAX;  // 2147483647
    cout << INT_MIN;  // -2147483648
    cout << LLONG_MAX; // long long max
}


// ============================================================
//  COMMON PROBLEMS
// ============================================================

void problems() {
    // ---- 1. Reverse a string ----
    string s = "Hello";

    // Option A: in-place
    reverse(s.begin(), s.end());

    // Option B: new string (preserves original)
    string rev(s.rbegin(), s.rend());

    // Option C: two-pointer manual
    int l = 0, r = s.size() - 1;
    while (l < r) {
        swap(s[l++], s[r--]);
    }

    // ---- 2. Max / Min in Array ----
    int a[] = {3, 1, 4, 1, 5, 9};
    int n = 6;
    cout << *max_element(a, a + n); // 9
    cout << *min_element(a, a + n); // 1

    // ---- 3. Char Frequencies ----
    string str = "hello world";
    map<char, int> freq;
    for (char c : str)
        freq[c]++;
    for (auto& [ch, cnt] : freq)
        cout << ch << ": " << cnt << "\n";
    // unordered_map<char,int> for O(1) avg if order doesn't matter

    // ---- 4. Check if Sorted ----
    cout << is_sorted(a, a + n); // 0 (false)

    // ---- 5. FizzBuzz ----
    for (int i = 1; i <= 20; i++) {
        if      (i % 15 == 0) cout << "FizzBuzz\n";
        else if (i % 3  == 0) cout << "Fizz\n";
        else if (i % 5  == 0) cout << "Buzz\n";
        else                  cout << i << "\n";
    }
}


// ============================================================
//  MAIN
// ============================================================

int main() {
    ios_base::sync_with_stdio(false); // faster I/O — do NOT mix with scanf/printf
    cin.tie(NULL);                    // don't flush cout before every cin
    // use "\n" instead of endl (endl flushes buffer — slow)

    print();
    cout << sum(2, 9);

    // containers
    explainString();
    explainPair();
    explainVector();
    explainList();
    explainDeque();
    explainStack();
    explainQueue();
    explainPriorityQueue();
    explainSet();
    explainMultiset();
    explainUSet();
    explainMap();
    explainMultimap();
    explainUnorderedMap();

    // algorithms
    explainAlgo();

    // problems
    problems();

    return 0;
}
