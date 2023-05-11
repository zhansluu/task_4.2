#include <iostream>
#include "compound_quadrature_formulas.h"

using namespace std;

int main()
{
    setlocale(0, "Russian");
    cout << "������� 4.2. ����������� ���������� ��������� �� ��������� ������������ ��������." << endl << endl;

    double a, b, step, w = 0, q = 0;
    size_t n;
    cout << "������� ������ ������ ��������������: � = ";
    cin >> a;
    cout << "������� ������� ������ ��������������: b = ";
    cin >> b;
    cout << "������� ����� ����������� ������� [a,b]: n = ";
    cin >> n;
    while (n <= 0)
    {
        cout << endl << "������� ������������ �������� n! ��������� �������.";
        cin >> n;
    }
    step = (b-a)/n;
    cout << "��� ������� h = " << step << endl;

    cout << "�������� �������, � ������� ������ ��������:" << endl
         << "0-3 - ��������� ��������������� �������;" << endl
         << "4 - ������� f(x)=6*x^2+cos(x)*exp(4x)" << endl
         << "5 - ������� f(x)=1.27*x^5+2.04*x" << endl
         << "6 - ����� ������" << endl;
    size_t num;
    cin >> num;
    while (num != 0 && num != 1 && num != 2 && num != 3 && num != 4 && num!= 5 && num != 6)
    {
        cout << "������� �������� ��������! ��������� �������.";
        cin >> num;
    }

    double J, leftJ, rightJ, middleJ, trapJ, simpsJ;
    while (num != 6){
        switch (num){
        case 0:
            w = (n-1)*polinom0degree();
            q = n*polinom0degree();
            J = integralOfPolinom0degree(b) - integralOfPolinom0degree(a);
            leftJ = leftRectangles(0, w, step);
            rightJ = rightRectangles(0, w, step, n);
            middleJ = middleRectangles(0, q, step);
            trapJ = trapeze(0, w, step, n);
            simpsJ = simpson(0, w, q, step, n);
            break;
        case 1:
            w = 0; q = 0;
            for (size_t i = 1; i < n; i++)
            {
                w += polinom1degree(a+i*step);
                q += polinom1degree((2*a+2*i*step+step)/2);
            }
            q += polinom1degree((2*a+step)/2);
            J = integralOfPolinom1degree(b) - integralOfPolinom1degree(a);
            leftJ = leftRectangles(1, w, step);
            rightJ = rightRectangles(1, w, step, n);
            middleJ = middleRectangles(1, q, step);
            trapJ = trapeze(1, w, step, n);
            simpsJ = simpson(1, w, q, step, n);
            break;
        case 2:
            w = 0; q = 0;
            for (size_t i = 1; i < n; i++)
            {
                w += polinom2degree(a+i*step);
                q += polinom2degree((2*a+2*i*step+step)/2);
            }
            q += polinom2degree((2*a+step)/2);
            J = integralOfPolinom2degree(b) - integralOfPolinom2degree(a);
            leftJ = leftRectangles(2, w, step);
            rightJ = rightRectangles(2, w, step, n);
            middleJ = middleRectangles(2, q, step);
            trapJ = trapeze(2, w, step, n);
            simpsJ = simpson(2, w, q, step, n);
            break;
        case 3:
            w = 0; q = 0;
            for (size_t i = 1; i < n; i++)
            {
                w += polinom3degree(a+i*step);
                q += polinom3degree((2*a+2*i*step+step)/2);
            }
            q += polinom3degree((2*a+step)/2);
            J = integralOfPolinom3degree(b) - integralOfPolinom3degree(a);
            leftJ = leftRectangles(3, w, step);
            rightJ = rightRectangles(3, w, step, n);
            middleJ = middleRectangles(3, q, step);
            trapJ = trapeze(3, w, step, n);
            simpsJ = simpson(3, w, q, step, n);
            break;
        case 4:
            w = 0; q = 0;
            for (size_t i = 1; i < n; i++)
            {
                w += func(a+i*step);
                q += func((2*a+2*i*step+step)/2);
            }
            q += func((2*a+step)/2);
            J = integralOfFunc(b) - integralOfFunc(a);
            leftJ = leftRectangles(4, w, step);
            rightJ = rightRectangles(4, w, step, n);
            middleJ = middleRectangles(4, q, step);
            trapJ = trapeze(4, w, step, n);
            simpsJ = simpson(4, w, q, step, n);
            break;
        case 5:
            w = 0; q = 0;
            for (size_t i = 1; i < n; i++)
            {
                w += f(a+i*step);
                q += f((2*a+2*i*step+step)/2);
            }
            q += f((2*a+step)/2);
            J = F(b) - F(a);
            leftJ = leftRectangles(5, w, step);
            rightJ = rightRectangles(5, w, step, n);
            middleJ = middleRectangles(5, q, step);
            trapJ = trapeze(5, w, step, n);
            simpsJ = simpson(5, w, q, step, n);
            break;
        case 6:
            return 0;
        }
        cout << "������ �������� ���������: J = " << J << endl;
        cout << "�� ����� ���������������: J(h) = " << leftJ << endl
             << "������������� �����������: " << 0.5*(b-a)*fabs(b)*step << endl
             << "���������� ����������� �����������: |J - J(h)| = " << fabs(J-leftJ) << endl
             << "������������� ����������� �����������: " << fabs(J-leftJ)/fabs(J) << endl
             << "------------------------------------------" << endl
             << "�� ������ ���������������: J(h) = " << rightJ << endl
             << "������������� �����������: " << 0.5*(b-a)*fabs(b)*step << endl
             << "���������� ����������� �����������: |J - J(h)| = " << fabs(J-rightJ) << endl
             << "������������� ����������� �����������: " <<  fabs(J-rightJ)/fabs(J) << endl
             << "------------------------------------------" << endl
             << "�� ������� ���������������: J(h) = " << middleJ << endl
             << "������������� �����������: " << (b-a)*fabs(b)*pow(step,2)/24 << endl
             << "���������� ����������� �����������: |J - J(h)| = " << fabs(J-middleJ) << endl
             << "������������� ����������� �����������: " << fabs(J-middleJ)/fabs(J) << endl
             << "------------------------------------------" << endl
             << "�� ��������: J(h) = " << trapJ << endl
             << "������������� �����������: " << (b-a)*fabs(b)*pow(step,2)/12 << endl
             << "���������� ����������� �����������: |J - J(h)| = " << fabs(J-trapJ) << endl
             << "������������� ����������� �����������: " << fabs(J-trapJ)/fabs(J) << endl
             << "------------------------------------------" << endl
             << "�� ��������: J(h) = " << simpsJ << endl
             << "������������� �����������: " << (b-a)*fabs(b)*pow(step,4)/2880 << endl
             << "���������� ����������� �����������: |J - J(h)| = " << fabs(J-simpsJ) << endl
             << "������������� ����������� �����������: " << fabs(J-simpsJ)/fabs(J) << endl
             << "------------------------------------------" << endl << endl << endl;
        cin >> num;
        while (num != 0 && num != 1 && num != 2 && num != 3 && num != 4 && num!= 5 && num != 6)
        {
            cout << "������� �������� ��������! ��������� �������.";
            cin >> num;
        }

    }
    return 0;
}
