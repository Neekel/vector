#include <iostream>
#include <string>
#include <vector>
#include <algorithm>             //��� sort
using namespace std;

class Student {               //����� ��� ������� 3

public:
    string name;
    string surname;
    int grade;

    Student(string name, string surname, int grade) :name(name), surname(surname), grade(grade) {};     //����������� 
    
    int sortName(const Student& student) const {            //���������� �� �����
        return name.compare(student.name);
    }

    int sortSurname(const Student& student) const {        //���������� �� �������
        return surname.compare(student.surname);
    }
    int sortGrade(const Student& student) const {          //���������� �� ������
        if (grade < student.grade)
            return -1;
        if (grade > student.grade)
            return 1;
        return 0;
    }

    friend ostream& operator<< (ostream& stream, const Student& student) {      //����� ����������
        stream << " Grade: " << student.grade;
        stream << " Name: " << student.name;
        stream << " Surname: " << student.surname << endl;
        return stream;
    }
};

void Init(vector<Student>& students) {                                      //���������� ������� ������� 3
    students.emplace_back("Sergey ", "Petrov ", 2);
    students.emplace_back("Petr ", "Ivanov ", 4);
    students.emplace_back("Ivan ", "Sidorov ", 1);
    students.emplace_back("Oleg ", "Mamaev ", 3);
}

void Print(const vector<Student>& students) {                                //����� �������  ������� 3
    for (const Student& student : students)
        cout << student;
}

void main()
{
    const int n = 10;
    vector<int> a(n);

    cout << "=======================Task 1====================== " << endl;

    for (vector<int>::size_type i = 0; i != a.size(); ++i)           //������� 1
    {
        a[i] = i * i;
        cout << a[i] << " ";
    }

    cout << " \n=======================Task 2====================== " << endl;

    vector< vector <int> > x(n);                                     //������� 2

    for (int i = 0; i < n; i++) x[i].resize(n);

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            x[i][j] = i * j;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << " " << x[i][j];
        cout << endl;
    }

    cout << " =======================Task 3====================== " << endl;

    vector<Student> students;                                       //������� 3

    Init(students);    //����� ������ ���������
   // Print(students);

    sort(students.begin(), students.end(), [](const Student& left, const Student& right) {return left.sortName(right) < 0; });   //���������� �� �����
    cout << "Sorted by name:" << endl;
    Print(students);

    sort(students.begin(), students.end(), [](const Student& left, const Student& right) {return left.sortSurname(right) < 0; });   //���������� �� �������
    cout << "Sorted by surname:" << endl;
    Print(students);


    for (int i = 0; i < 4; i++) {
        auto iter = min_element(students.begin() + i, students.end(), [](const Student& left, const Student& right) {return left.sortGrade(right) < 0; });  //���������� �� ������
        if (iter != students.end()) {
            int index_min = iter - students.begin();                    //������� ������������ �������� 
            students.insert(students.begin() + i, iter, iter + 1);      //����� ������������ ��������� ������ ����� ��� �������� �����������
            students.erase(students.begin() + index_min + 1);           //������� ��������
        }
    }

    cout << "Sorted by grade:" << endl;               // ����� ���������� �� ������
    Print(students);



    

}

