#include <iostream>
#include <string>
#include <vector>
#include <algorithm>             //дл€ sort
using namespace std;

class Student {               //класс дл€ задание 3

public:
    string name;
    string surname;
    int grade;

    Student(string name, string surname, int grade) :name(name), surname(surname), grade(grade) {};     //конструктор 
    
    int sortName(const Student& student) const {            //—ортировка по имени
        return name.compare(student.name);
    }

    int sortSurname(const Student& student) const {        //—ортировка по фамилии
        return surname.compare(student.surname);
    }
    int sortGrade(const Student& student) const {          //—ортировка по грейду
        if (grade < student.grade)
            return -1;
        if (grade > student.grade)
            return 1;
        return 0;
    }

    friend ostream& operator<< (ostream& stream, const Student& student) {      //вывод результата
        stream << " Grade: " << student.grade;
        stream << " Name: " << student.name;
        stream << " Surname: " << student.surname << endl;
        return stream;
    }
};

void Init(vector<Student>& students) {                                      //заполнение вектора задание 3
    students.emplace_back("Sergey ", "Petrov ", 2);
    students.emplace_back("Petr ", "Ivanov ", 4);
    students.emplace_back("Ivan ", "Sidorov ", 1);
    students.emplace_back("Oleg ", "Mamaev ", 3);
}

void Print(const vector<Student>& students) {                                //вывод вектора  задание 3
    for (const Student& student : students)
        cout << student;
}

void main()
{
    const int n = 10;
    vector<int> a(n);

    cout << "=======================Task 1====================== " << endl;

    for (vector<int>::size_type i = 0; i != a.size(); ++i)           //задание 1
    {
        a[i] = i * i;
        cout << a[i] << " ";
    }

    cout << " \n=======================Task 2====================== " << endl;

    vector< vector <int> > x(n);                                     //задание 2

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

    vector<Student> students;                                       //задание 3

    Init(students);    //вывод списка студентов
   // Print(students);

    sort(students.begin(), students.end(), [](const Student& left, const Student& right) {return left.sortName(right) < 0; });   //—ортировка по имени
    cout << "Sorted by name:" << endl;
    Print(students);

    sort(students.begin(), students.end(), [](const Student& left, const Student& right) {return left.sortSurname(right) < 0; });   //—ортировка по фамилии
    cout << "Sorted by surname:" << endl;
    Print(students);


    for (int i = 0; i < 4; i++) {
        auto iter = min_element(students.begin() + i, students.end(), [](const Student& left, const Student& right) {return left.sortGrade(right) < 0; });  //—ортировка по грейду
        if (iter != students.end()) {
            int index_min = iter - students.begin();                    //позици€ минимального элемента 
            students.insert(students.begin() + i, iter, iter + 1);      //копию минимального вставл€ем вперед после уже найденых минимальных
            students.erase(students.begin() + index_min + 1);           //удал€ем оригинал
        }
    }

    cout << "Sorted by grade:" << endl;               // ¬ывод сортировки по грейду
    Print(students);



    

}

