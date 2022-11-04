#include <iostream>
#include <iomanip>
#include <iostream>

int main()
{
    setlocale(0, "");
    int choice;
    do
    {
     /*хз че setconsole подчеркивает, так что setlocale сделал    SetConsoleOutputCP(1251); */  

        //int choice; не видит в while последнем
        std::cout << "1. Сумма заданного количества слагаемых\n";
        std::cout << "2. Сумма с заданной точностью\n";
        std::cout << "3. Завершить работу\n";
        bool isError = false;
        do
        {
            isError = false;
            std::cout << "->";
            std::cin >> choice;
            if (std::cin.fail() || choice < 1 || choice > 3)
            {
                isError = true;
                std::cout << "Ошибка ввода!\n";
                std::cin.clear(); //clear очищает флаги, а не поток
                std::cin.ignore(std::cin.rdbuf()->in_avail());
            }
        } while (isError);

        //std::cout << choice << '\n';
        if (choice != 3)
        {
            //-------------------- дальше идет задача по вводу х
            double x;
            std::cout << "Введите значение х: ";
            while (!(std::cin >> x) || abs(x) >= 1) //если после чтения поток заблокировался или модуль х >=1
            {
                std::cout << "Ошибка воода (|x| < 1!\n";
                std::cin.clear();
                std::cin.ignore(255, '\n'); //очищаем 255 символов в потоке
            }
            //std::cout << x << '\n';
            std::cout << std::setw(26) << std::left << "Точное значение" << "=" << std::fixed << std::setprecision(11) << asin(x) << '\n';
            if (choice == 1)
            {
                std::cout << "Задача 1\n";
                std::cout << "Введите количество слагаемых: ";
                int n;
                std::cin >> n;
                double s = 0, a = x; // , - оператор последовательного выполнения
                for (int i = 0; i < n; ++i)
                {
                    s += a;
                    a *= x * x * (2 * i + 1) * (2 * i + 1) / (2 * (i + 1) * 2 * (i + 3));


                }
            }
            else // choice = 2
            {
                //std::cout << "Задача 2\n";
                double E;
                std::cout << "Введите точность вычислений: ";
                std::cin >> E;
                int i = 0;
                double s = 0, a = x;
                while (abs(a) >= E)
                {
                    s += a;
                    a *= x * x * (2 * i + 1) * (2 * i + 1) / (2 * (i + 1) * 2 * (i + 3));
                    ++i;
                }
                std::cout << "Точность = " << E << '\n';/*  по логике здесь должно быть E, а там хз :/   */
                std::cout << "Кол-во слагаемых = " << i << '\n';
                std::cout << std::setw(26) << std::left << "Точное значение" << "=" << std::fixed << std::setprecision(11) << asin(x) << '\n';
            }
            char isExit; //переменная внутри блока
            std::cout << "\nЗаершить работу (Y/N - любой символ)\n";
            std::cin >> isExit;
            if (isExit == 'Y' || isExit == 'y')
                choice = 3;
            }

    } 
    while (choice != 3);
        //std::cin.ignore().get();
    return 0;
}
