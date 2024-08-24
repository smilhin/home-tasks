#include <iostream>
#include <string>

struct Person {

    virtual std::string GetPerson() = 0;

    std::string name, surname, street;
};

struct Student : Person 
{
    
    int studentID;

    Student(const std::string& name, const std::string& surname, const int& studentID, const std::string& street)  {

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

    std::string teachingArea;

    Teacher(const std::string& name, const std::string& surname, const std::string& teachingArea, const std::string& street) {

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
    Student student("Dan", "Doom", 10, "University Street");
    std::cout << student.GetPerson() << std::endl;

    Teacher teacher("Nad", "Mood", "Computer Science", "University Street");
    std::cout << teacher.GetPerson() << std::endl;

}

