#include <vector>
#include <iostream>

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (auto el = v.begin(); el != v.end(); ++el) {
        if (el != v.begin())
            os << ", ";
        os << *el;
    }
    return os << "]";
}

void bubble(vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        bool swapped = false;
        for (int j = i + 1; j < array.size(); j++) {
            if (array[i] > array[j]) {
                array[i] ^= array[j];
                array[j] ^= array[i];
                array[i] ^= array[j];
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void insertion(vector<int>& array) {
    for (int i = 1; i < array.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (array[i] < array[j]) {
                array[i] ^= array[j];
                array[j] ^= array[i];
                array[i] ^= array[j];
                i -= 1;
            }
            else
                break;
        }
    }
}

int main() {
    vector<int> array = {32,1,5,23,6,64,2,1};
    cout << array << endl;
    insertion(array);
    cout << array << endl;
}
