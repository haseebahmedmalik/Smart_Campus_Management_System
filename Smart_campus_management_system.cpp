#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person{
protected:
    int id;
    string name;

public:
    Person(int i, string n){
        id = i;
        name = n;
    }
    
    virtual void display() = 0;
    string getName(){
        return name;
    }
};

class Student : public Person{
    int semester;

public:
    static int totalStudents;
    Student(int i, string n, int s) : Person(i, n){
        semester = s;
        totalStudents++;
    }
    void display(){
        cout << "Student ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Semester: " << semester << endl;
    }
};

int Student::totalStudents = 0;

class Teacher : public Person{
    string designation;
public:
    static int totalTeachers;
    Teacher(int i, string n, string d) : Person(i, n){
        designation = d;
        totalTeachers++;
    }
    void display(){
        cout << "Teacher ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
    }
};

int Teacher::totalTeachers = 0;

class Course{
    string code;
    string title;
    int creditHours;

public:
    static int totalCourses;
    Course(string c, string t, int ch){
        code = c;
        title = t;
        creditHours = ch;
        totalCourses++;
    }
    void display(){
        cout << "Course Code: " << code << endl;
        cout << "Title: " << title << endl;
        cout << "Credit Hours: " << creditHours << endl;
    }
    string getTitle(){
        return title;
    }
    int operator+(Course c){
        return creditHours + c.creditHours;
    }
};

int Course::totalCourses = 0;

template <class T>
class Record{
    vector<T*> data;

public:
    void add(T* obj){
        data.push_back(obj);
    }
};

class Department{
    string name;

    vector<Student*> students;
    vector<Teacher*> teachers;
    vector<Course*> courses;

public:
    Department(string n){
        name = n;
    }

    void addStudent(Student* s){
        students.push_back(s);
    }

    void addTeacher(Teacher* t){
        teachers.push_back(t);
    }

    void addCourse(Course* c){
        courses.push_back(c);
    }

    void display(){
        cout << "Department: " << name << endl;
        cout << "Students"<< endl;

        for (auto s : students){
            s->display();
            cout << endl;
        }

        cout << "Teachers"<< endl;

        for (auto t : teachers){
            t->display();
            cout << endl;
        }

        cout << "Courses"<< endl;

        for (auto c : courses) {
            c->display();
            cout << endl;
        }
    }
};

class Section{
    string sectionName;

    vector<Student*> students;
    vector<Course*> courses;
    vector<Teacher*> teachers;

public:
    Section(string n){
        sectionName = n;
    }

    void addStudent(Student* s){
        students.push_back(s);
    }

    void assignCourse(Course* c){
        courses.push_back(c);
    }

    void assignTeacher(Teacher* t) {
        teachers.push_back(t);
    }

    void display() {
        cout << "Section: " << sectionName << endl;
        cout << "Students"<< endl;

        for (auto s : students){
            s->display();
            cout << endl;
        }

        cout << "Teachers"<< endl;

        for (auto t : teachers){
            t->display();
            cout << endl;
        }

        cout << "Courses"<< endl;

        for (auto c : courses){
            c->display();
            cout << endl;
        }
    }
};

class Enrollment{
    Student* student;
    Course* course;

    int marks;
    string grade;

public:
    Enrollment(Student* s, Course* c) {
        student = s;
        course = c;
        marks = 0;
        grade = "N/A";
    }

    void updateMarks(int m){
        marks = m;

        if (marks >= 85){
            grade = "A";
        }

        else if (marks >= 70){
            grade = "B";
        }

        else if (marks >= 50){
            grade = "C";
        }

        else{
            grade = "F";
        }
    }

    void display(){
        cout << "Student: " << student->getName() << endl;
        cout << "Course: " << course->getTitle() << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main(){
    vector<Student*> students;
    vector<Teacher*> teachers;
    vector<Course*> courses;
    vector<Department*> departments;
    vector<Section*> sections;
    vector<Enrollment*> enrollments;

    int choice;

    do{
        cout << " Smart Campus Management System "<< endl;

        cout << "1. Add Student"<< endl;
        cout << "2. Display Students"<< endl;
        cout << "3. Add Teacher"<< endl;
        cout << "4. Display Teachers"<< endl;
        cout << "5. Add Course"<< endl;
        cout << "6. Display Courses"<< endl;
        cout << "7. Add Department"<< endl;
        cout << "8. Add Student to Department"<< endl;
        cout << "9. Add Teacher to Department"<< endl;
        cout << "10. Add Course to Department"<< endl;
        cout << "11. Display Department Details"<< endl;
        cout << "12. Create Section"<< endl;
        cout << "13. Add Student to Section"<< endl;
        cout << "14. Assign Course to Section"<< endl;
        cout << "15. Assign Teacher to Section"<< endl;
        cout << "16. Display Section Details"<< endl;
        cout << "17. Enroll Student in Course"<< endl;
        cout << "18. Add Marks"<< endl;
        cout << "19. Display Results"<< endl;
        cout << "20. Exit"<< endl;
        cout<<endl;
         cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, semester;
            string name;

            cout << "Enter ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Semester: ";
            cin >> semester;

            students.push_back(new Student(id, name, semester));
        }

        else if (choice == 2){
            for (auto s : students){
                s->display();
                cout << endl;
            }
        }

        else if (choice == 3){
            int id;
            string name, designation;

            cout << "Enter ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Designation: ";
            getline(cin, designation);

            teachers.push_back(new Teacher(id, name, designation));
        }

        else if (choice == 4){
            for (auto t : teachers){
                t->display();
                cout << endl;
            }
        }

        else if (choice == 5){
            string code, title;
            int ch;

            cin.ignore();

            cout << "Enter Course Code: ";
            getline(cin, code);

            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Credit Hours: ";
            cin >> ch;

            courses.push_back(new Course(code, title, ch));
        }

        else if (choice == 6){
            for (auto c : courses)
            {
                c->display();
                cout << endl;
            }
        }

        else if (choice == 7){
            string name;

            cin.ignore();

            cout << "Enter Department Name: ";
            getline(cin, name);

            departments.push_back(new Department(name));
        }

        else if (choice == 8){
            int s, d;

            cout << "Student Index: ";
            cin >> s;

            cout << "Department Index: ";
            cin >> d;

            departments[d]->addStudent(students[s]);
        }

        else if (choice == 9){
            int t, d;

            cout << "Teacher Index: ";
            cin >> t;

            cout << "Department Index: ";
            cin >> d;

            departments[d]->addTeacher(teachers[t]);
        }

        else if (choice == 10){
            int c, d;

            cout << "Course Index: ";
            cin >> c;

            cout << "Department Index: ";
            cin >> d;

            departments[d]->addCourse(courses[c]);
        }

        else if (choice == 11){
            int d;

            cout << "Department Index: ";
            cin >> d;

            departments[d]->display();
        }

        else if (choice == 12){
            string name;

            cin.ignore();

            cout << "Enter Section Name: ";
            getline(cin, name);

            sections.push_back(new Section(name));
        }

        else if (choice == 13){
            int s, sec;

            cout << "Student Index: ";
            cin >> s;

            cout << "Section Index: ";
            cin >> sec;

            sections[sec]->addStudent(students[s]);
        }

        else if (choice == 14){
            int c, sec;

            cout << "Course Index: ";
            cin >> c;

            cout << "Section Index: ";
            cin >> sec;

            sections[sec]->assignCourse(courses[c]);
        }

        else if (choice == 15){
            int t, sec;

            cout << "Teacher Index: ";
            cin >> t;

            cout << "Section Index: ";
            cin >> sec;

            sections[sec]->assignTeacher(teachers[t]);
        }

        else if (choice == 16){
            int sec;

            cout << "Section Index: ";
            cin >> sec;

            sections[sec]->display();
        }

        else if (choice == 17){
            int s, c;

            cout << "Student Index: ";
            cin >> s;

            cout << "Course Index: ";
            cin >> c;

            enrollments.push_back(new Enrollment(students[s], courses[c]));
        }

        else if (choice == 18){
            int e, marks;

            cout << "Enrollment Index: ";
            cin >> e;

            cout << "Enter Marks: ";
            cin >> marks;

            enrollments[e]->updateMarks(marks);
        }

        else if (choice == 19){
            for (auto e : enrollments)
            {
                e->display();
                cout << endl;
            }
        }

    } while (choice != 20);

    return 0;
}