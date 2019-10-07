#include <iostream>
using namespace std;
class Professor
{
    char name[20],
        department[20];
    unsigned int 
        degree,
        experience;

public:
    //class constructor signature
    Professor(char p_name[20], char p_department[20], int p_degree, int p_experience);
    Professor();
    //class destructor signature
    ~Professor();
    //display function
    void showOff()
    {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Degree: " << degree << endl;
        cout << "Experience: " << experience << endl;
    }
};
//constructor
Professor::Professor(char p_name[20], char p_department[20], int p_degree, int p_experience)
{
    strcpy(name, p_name);
    strcpy(department, p_department);
    degree = p_degree;
    experience = p_experience;
    cout << "\nConstructor said: record created" << endl;
}
//constructor
Professor::Professor()
{
    strcpy(name, "John Doe");
    strcpy(department, "Unknown");
    degree = 0;
    experience = 0;
    cout << "\nConstructor said: record created" << endl;
}
//destructor
Professor::~Professor()
{
    cout << "\nDestructor said: memory for " << name << " was freed up" << endl;
}

int main()
{
    Professor professor1("Jeff", "CS", 2, 7);
    professor1.showOff();
    Professor professor2;
    professor2.showOff();
    return 0;
}