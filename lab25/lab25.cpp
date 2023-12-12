#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// Попереднє оголошення шаблонної функції
template<typename T>
T Sqr(const T& value);

template <typename T1, typename T2>
pair<T1, T2> Sqr(const pair<T1, T2>& p);

template <typename T>
vector<T> Sqr(const vector<T>& v);

template <typename K, typename V>
map<K, V> Sqr(const map<K, V>& m);

// Означення шаблонної функції для чисел
template <typename T>
T Sqr(const T& value) {
    return value * value;
}

// Означення шаблонної функції для пари
template <typename T1, typename T2>
pair<T1, T2> Sqr(const pair<T1, T2>& p) {
    return make_pair(Sqr(p.first), Sqr(p.second));
}

// Означення шаблонної функції для вектора
template <typename T>
vector<T> Sqr(const vector<T>& v) {
    vector<T> result;
    result.reserve(v.size());
    for (const auto& elem : v) {
        result.push_back(Sqr(elem));
    }
    return result;
}

// Означення шаблонної функції для мапу
template <typename K, typename V>
map<K, V> Sqr(const map<K, V>& m) {
    map<K, V> result;
    for (const auto& pair : m) {
        result[pair.first] = Sqr(pair.second);
    }
    return result;
}

int main() {
    // Приклад виклику функції
    vector<int> v = { 1, 2, 3 };
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}
