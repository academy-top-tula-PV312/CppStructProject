#include <iostream>
#include <string>

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();

struct Person
{
    char* name{ new char };
    int age{ 0 };
    float label{ 0 };
    //bool married{ false };
};

void PersonPrint(Person person);
void PersonSwap(Person& p1, Person& p2);

void PersonSortName(Person persons[], int size);

void GroupExample();

int main()
{
    Person person;

    strcpy_s(person.name, strlen("Bob") + 1, "Bob");
    person.age = 25;
    person.label = 11.5;

    //PersonPrint(person);

    //std::cout << sizeof(Person) << "\n";

    Person joe;
    strcpy_s(joe.name, strlen("Joe") + 1, "Joe");
    joe.age = 31;
    joe.label = 10.3;

    //PersonPrint(joe);
    std::cout << "\n";

    Person temp = person;
    person = joe;
    joe = temp;

    //PersonPrint(person);
    //PersonPrint(joe);

    int* ptr = new int;
    *ptr = 123;

    Person* tom = new Person;

    (*tom).age = 25;
    tom->age = 25;

    delete tom;


}

void PersonPrint(Person person)
{
    std::cout << "Person name: " << person.name
        << ", age: " << person.age
        << ", label: " << person.label << "\n";
}

void PersonSwap(Person& p1, Person& p2)
{
    Person temp = p1;
    p1 = p2;
    p2 = temp;
}

void PersonSortName(Person persons[], int size)
{
    for (int i{}; i < size; i++)
        for (int j{ size - 1 }; j > i; j--)
            //if (strcmp(persons[j].name, persons[j - 1].name) < 0)
            if(persons[j].age < persons[j - 1].age)
                PersonSwap(persons[j], persons[j - 1]);
}

void GroupExample()
{
    const int groupSize{ 5 };
    Person group[groupSize];

    strcpy_s(group[0].name, 4, "Tom");
    strcpy_s(group[1].name, 4, "Jim");
    strcpy_s(group[2].name, 4, "Sam");
    strcpy_s(group[3].name, 4, "Leo");
    strcpy_s(group[4].name, 4, "Bob");

    srand(time(nullptr));

    for (int i{}; i < groupSize; i++)
    {
        group[i].age = 20 + rand() % 21;
        group[i].label = (10 + rand() % 15) / 2.0;
    }

    PersonSortName(group, groupSize);

    for (int i{}; i < groupSize; i++)
        PersonPrint(group[i]);
}
