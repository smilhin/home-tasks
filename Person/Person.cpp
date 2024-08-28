#include <iostream>
#include <string>
#include <vector>
#include <memory>


struct Person 
{
    Person(const std::string& name, const std::string& surname, const std::string& street)
        : m_Name(name), m_Surname(surname), m_Street(street)
    {
    
    }


    virtual std::string GetPerson() const = 0;
protected:
    std::string m_Name, m_Surname, m_Street;
};

struct Student : Person
{

    int studentID = 0;

    Student(const std::string& name, const std::string& surname, const int& studentID, const std::string& street)  
        : Person(name, surname, street), studentID(studentID) 
    {
        std::cout << "Created Student" << '\n';
    }

    ~Student() {
        std::cout << "Deleted Student!" << '\n';
    }
    
    std::string GetPerson() const {
        return std::string("Name: ") + this->m_Name + " " + this->m_Surname + ", studentID: " + std::to_string(this->studentID) + ", Street: " + this->m_Street;
    }
};

struct Teacher : Person 
{

    std::string teachingArea;

    Teacher(const std::string& name, const std::string& surname, const std::string& teachingArea, const std::string& street) 
        : Person(name, surname, street), teachingArea(teachingArea)
    {
        std::cout << "Created Teacher" << '\n';
    }

    ~Teacher() {
        std::cout << "Deleted Teacher!" << '\n';
    }


    std::string GetPerson() const override {
        return std::string("Name: ") + this->m_Name + " " + this->m_Surname + ", Teaching Area: " + this->teachingArea + ", Street: " + this->m_Street;
    }
};

struct Database 
{
    std::vector<Person*> people;
    Database() {
        std::cout << "Created Database!" << '\n';
    }

    ~Database() {
        std::cout << "Destroyed Database!" << '\n';
    }

    void PushToDatabase(Person* person) {

        people.emplace_back(person);

    }

    std::string GetDatabase() {

        std::string result;

        for (Person* p : people) {
            result += p->GetPerson() + '\n';
        }
        return result;
    }
};


int main()
{
   
    std::unique_ptr<Student> student1 = std::make_unique<Student>("Dan", "Mood", 20, "College Street");

    std::unique_ptr<Student> student2 = std::make_unique<Student>("Dan", "Mood", 20, "College Street");

    std::unique_ptr<Teacher> teacher = std::make_unique<Teacher>("Dan", "Mood", "Computer Science", "College Street");

 

    std::unique_ptr<Database> db = std::make_unique<Database>();

    db->PushToDatabase(student1.get());
    db->PushToDatabase(teacher.get());
    db->PushToDatabase(student2.get());

    std::cout << db->GetDatabase();

    std::cin.get();
}

