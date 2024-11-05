#include "Array.hpp"
#include <string>

using namespace std;


int main() {

    Array<double> B; // default constructor need to be call by not having brackets after the variable name
    Array<float> A(12);
    Array<int> I(4, 3);

    char ch[] = {'a', 'b', 'c', 'z', 'k'};
    int ch_size = 5;

    Array<char> chr(ch_size, ch);
    Array<char> newChr(chr);

    Array<Array<char>> _2DArray(10, chr);

    cout << "Array constructed with default constructor. \n";
    cout << B.getSize() << '\n';


    cout << "Array constructed with size and every element = 0 constructor. \n";
    for (int i = 0; i < A.getSize(); i++)
        cout << A.getElement(i) << " ";

    cout << '\n';

    cout << "Array constructed with size and every element equal an initial value constructor. \n";
    for (int i = 0; i < I.getSize(); i++)
        cout << I.getElement(i) << " ";

    cout << '\n';

    cout << "Array constructed with size and an initial c-style array of element. \n";
    for (int i = 0; i < chr.getSize(); i++)
        cout << chr.getElement(i) << " ";

    cout << '\n';

    cout << "Array constructed with another Aray. \n";
    for (int i = 0; i < newChr.getSize(); i++) {
        cout << newChr.getElement(i) << ' ';
    }

    cout << '\n';

    cout << "2D array demo\n";

    _2DArray.getElement(2).getElement(2) = 'x';

    for (int i = 0; i < _2DArray.getSize(); i ++) {
        for (int j = 0; j < _2DArray.getElement(i).getSize(); j ++)
            cout << _2DArray.getElement(i).getElement(j) << ' ';
        cout << '\n';
    }

    Array <Array<Array<char>>>_3Darr(2, _2DArray);

    for (int k = 0; k < _3Darr.getSize(); k++) {

        auto& _2Darr = _3Darr.getElement(k);
        cout << k << " Array " << '\n';

        for (int i = 0; i < _2Darr.getSize(); i ++) {
            for (int j = 0; j < _2Darr.getElement(i).getSize(); j ++)
                cout << _2Darr.getElement(i).getElement(j) << ' ';
            cout << '\n';
        }
    }

    cout << "End demo\n";

    return 0;
}