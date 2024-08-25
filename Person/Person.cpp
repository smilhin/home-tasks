#include <iostream>
#include <string>
#include <vector>

struct Person 
{
    Person(const std::string& name, const std::string& surname, const std::string& street)
        : m_Name(name), m_Surname(surname), m_Street(street)
    {
    
    }
    virtual std::string GetPerson() = 0;
protected:
    std::string m_Name, m_Surname, m_Street;
};

struct Student : Person
{

    int studentID = 0;

    Student(const std::string& name, const std::string& surname, const int& studentID, const std::string& street)  
        : Person(name, surname, street), studentID(studentID) 
    {
    
    }
    
    std::string GetPerson() {
        return std::string("Name: ") + this->m_Name + " " + this->m_Surname + ", studentID: " + std::to_string(this->studentID) + ", Street: " + this->m_Street;
    }
};

struct Teacher : Person 
{

    std::string teachingArea;

    Teacher(const std::string& name, const std::string& surname, const std::string& teachingArea, const std::string& street) 
        : Person(name, surname, street), teachingArea(teachingArea)
    {

    }

    std::string GetPerson() override {
        return std::string("Name: ") + this->m_Name + " " + this->m_Surname + ", Teaching Area: " + this->teachingArea + ", Street: " + this->m_Street;
    }
};


int main()
{
   
    Student student("Dan", "Doom", 10, "University Street");

    Teacher teacher("Nad", "Mood", "Computer Science", "University Street");
    
    std::cout << student.GetPerson() << std::endl << teacher.GetPerson();

}

