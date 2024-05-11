#include <iostream>
#include <string>

using namespace std;

// Abstract base class for employees
class AbstractEmployee {
public:
    virtual void AskForPromotion() = 0; // Pure virtual function
};

// Base class: Employee
class Employee : public AbstractEmployee {
private:
    string Company;
    int Age;
protected:
    string Name;

public:
    void setName(string name) {
        Name = name;
    }

    string getName() {
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }

    string getCompany() {
        return Company;
    }

    void setAge(int age) {
        if (age >= 18)
            Age = age;
    }

    int getAge() {
        return Age;
    }

    void IntroduceYourself() {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    // Constructor
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    void AskForPromotion() {
        if (Age > 30)
            cout << Name << " got promoted!" << endl;
        else
            cout << Name << ", sorry NO promotion for you!" << endl;
    }

    virtual void Work() {
        cout << Name << " is checking email, task backlog, performing tasks...." << endl;
    }
};

// Derived class: Developer
class Developer : public Employee {
public:
    string FavProgrammingLang;

    // Constructor
    Developer(string name, string company, int age, string favprogramminglang)
        : Employee(name, company, age) {
        FavProgrammingLang = favprogramminglang;
    }

    void FixBug() {
        cout << Name << " fixed bug using " << FavProgrammingLang << endl;
    }

    void Work() {
        cout << Name << " is writing " << FavProgrammingLang << " code" << endl;
    }
};

// Derived class: Teacher
class Teacher : public Employee {
public:
    string Subject;

    // Constructor
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age) {
        Subject = subject;
    }

    void PrepareLesson() {
        cout << Name << " is preparing " << Subject << " lesson" << endl;
    }

    void Work() {
        cout << Name << " is teaching " << Subject << endl;
    }
};

int main() {
    Developer d = Developer("Lewis", "Data Camp", 25, "Python");
    Teacher t = Teacher("James", "Kemri", 40, "Science");

    // Pointers to Employee objects
    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work(); // Calls the Work() function of the Developer class
    e2->Work(); // Calls the Work() function of the Teacher class

    return 0;
}
