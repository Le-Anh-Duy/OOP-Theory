#include <iostream>
#include <stdexcept>
#include "fraction.hpp"
#include "handmade_sort.hpp"

////////////////////////// 3.2 + 3.3 CUSTOM SORT //////////////////////////

// EXAMPLE FOR A CUSTOME COMPARE FUNCTION
bool cmp(Fraction a, Fraction b) {
    return compare(a, b) == -1;
}

//////////////////////////    END  CUSTOM SORT   //////////////////////////


/*
    // Example function to test

    int main() {
        try {
            Fraction arr[] = {
                Fraction(1, 2),
                Fraction(2, 5),
                Fraction(9, 12),
                Fraction(0, 1222),
                Fraction(9, 3)
            };

            int n = 5;
            cout << (arr[0] < arr[1] )<< '\n';
            sort(arr, n, cmp);

            for (int i = 0; i < n; i ++)
                arr[i].output();

        }
        catch(const exception &e) {
            cout << "Exception: " << e.what() << '\n';
        }

        return 0;
    }

*/
    int main() {
        try {
            Fraction arr[] = {
                Fraction(1, 2),
                Fraction(2, 5),
                Fraction(9, 12),
                Fraction(0, 1222),
                Fraction(9, 3)
            };

            int n = 5;

            cout << (arr[0] < arr[1]) << '\n';

            sort(arr, n, cmp);

            for (int i = 0; i < n; i ++)
                arr[i].output();

        }
        catch(const exception &e) {
            cout << "Exception: " << e.what() << '\n';
        }

        return 0;
    }