#include <iostream>
#include <string>

struct Person {

    virtual std::string GetPerson() = 0;

    std::string name, surname, street;
};

struct Student : Person {
    
    std::string name, surname, street;
    int studentID;

    Student(std::string name, std::string surname, int studentID, std::string street) {

        this->name = name;
        this->surname = surname;
        this->studentID = studentID;
        this->street = street;

    }
    
    std::string GetPerson() override {
        return std::string("Name: ") + this->name + " " + this->surname + ", studentID: " + std::to_string(this->studentID) + ", Street: " + this->street;
    }
};

struct Teacher : Person {

    std::string name, surname, street, teachingArea;

    Teacher(std::string name, std::string surname, std::string teachingArea, std::string street) {

        this->name = name;
        this->surname = surname;
        this->teachingArea = teachingArea;
        this->street = street;

    }

    std::string GetPerson() override {
        return std::string("Name: ") + this->name + " " + this->surname + ", Teaching Area: " + this->teachingArea + ", Street: " + this->street;
    }
};


int main()
{
    
    Person* student = new Student("Dan", "Doom", 10, "University Street");
    std::cout << student->GetPerson() << std::endl;

    Person* teacher = new Teacher("Nad", "Mood", "Computer Science", "University Street");
    std::cout << teacher->GetPerson() << std::endl;

}

