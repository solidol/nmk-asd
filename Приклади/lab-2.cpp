#include <iostream>
using std::cin;
using std::cout;
using std::endl;
 
int main() 
{
    double a, h, p, s;
    cout << "Введите угол трапеции: ";
    cin >> a;
    cout << "Введите высоту трапеции: ";
    cin >> h;
    p = 2 * a + 2 * (h / sin(a)) * (1 + cos(a));
    s = (0,5 * (2 * a + ( (2 * h * cos(a)) / sin(a))) * h;
    cout << "Периметр равен: " << p;
    cout << "Площадь равна: " << s;
    system("PAUSE");
    return 0;
}