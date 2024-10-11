// overload_date.cpp
// compile with: /EHsc
#include <iostream>
// using namespace std;

// class Date
// {
//     int mo, da, yr;
// public:
//     Date(int m, int d, int y)
//     {
//         mo = m; da = d; yr = y;
//     }
//     friend ostream& operator<<(ostream& os, const Date& dt);
// };

// ostream& operator<<(ostream& os, const Date& dt)
// {
//     os << dt.mo << '/' << dt.da << '/' << dt.yr;
//     return os;
// }

// int main()
// {
//     Date dt(5, 6, 92);
//     cout << dt;
// }

#include <iostream>

class A {
    int val;
public:
    A(int v) : val(v) {}
    friend std::ostream& operator<<(std::ostream& os, const A& obj) {
        os << obj.val;
        return os;
    }
};
int main() {
    A obj(42);
    std::cout <<"Value = "<< obj << std::endl; // Output: Value: 42
    return 0;
}
