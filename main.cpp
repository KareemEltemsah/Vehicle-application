#include <iostream>
using namespace std;
class Person
{
private:
    string name;
public:
    Person()
    {
        name.erase();
    }
    Person(string the_name)
    {
        name=the_name;
    }
    Person(const Person& the_object)
    {
        name=the_object.name;
    }
    string get_name() const
    {
        return name;
    }
    Person& operator = (const Person& rt_side)
    {
        name=rt_side.name;
    }
    friend istream& operator >>(istream& in_stream,Person& person_object);
    friend ostream& operator <<(ostream& out_stream,const Person& person_object);
};
class Vehicle
{
protected:
    string manufacturer;
    int cylinders;
    Person owner;
public:
    Vehicle()
    {

    }
    Vehicle(string m, int c, Person o)
    {
        manufacturer=m;
        cylinders=c;
        owner=o;
    }
    Vehicle(const Vehicle& the_object)
    {
        manufacturer=the_object.manufacturer;
        cylinders=the_object.cylinders;
        owner=the_object.owner;
    }
    virtual void input()
    {
        cout << "\nEnter the name of the vehicle owner : ";
        cin >> owner;
        cout << "Manufacturer : ";
        cin >> manufacturer;
        cout << "How many cylinders it has : ";
        cin >> cylinders;
        cout << endl;
    }
    virtual void output()
    {
        cout << "This vehicle owner called " << owner << endl;
        cout << "From manufacturer " << manufacturer << endl;
        cout << "It has " << cylinders << " cylinders" << endl << endl;
    }
    string get_manufacturer()
    {
        return manufacturer;
    }
    int get_cylinders()
    {
        return cylinders;
    }
    Person get_owner()
    {
        return owner;
    }
};
class Truck : public Vehicle
{
private:
    double load_capacity;
    int towing_capacity;
public:
    Truck()
    {

    }
    Truck(string m, int c, Person o) : Vehicle(m,c,o)
    {

    }
    void input()
    {
        cout << "\nEnter the name of the truck owner : ";
        cin >> owner;
        cout << "Manufacturer : ";
        cin >> manufacturer;
        cout << "How many cylinders it has : ";
        cin >> cylinders;
        cout << "The load capacity : ";
        cin >> load_capacity;
        cout << "Towing capacity : ";
        cin >> towing_capacity;
        cout << endl;
    }
    void output()
    {
        cout << "This truck owner called " << owner << endl;
        cout << "From manufacturer " << manufacturer << endl;
        cout << "It has " << cylinders << " cylinders" << endl;
        cout << "It has " << load_capacity << " load_capacity and " << towing_capacity << " towing capacity" << endl << endl;
    }
    double get_load_capacity()
    {
        return load_capacity;
    }
    int get_towing_capacity()
    {
        return towing_capacity;
    }
};
istream& operator >>(istream& in_stream,Person& person_object)
{
    std::cin >> person_object.name;
}
ostream& operator <<(ostream& out_stream,const Person& person_object)
{
    std::cout << person_object.name;
}
int main()
{
    Vehicle **v;
    cout << "Enter number of vehicles : ";
    int n;
    cin >> n;
    v=new Vehicle*[n];
    char choice;
    for (int i=0 ; i<n ; i++)
    {
        cout << "Enter v for normal vehicle or t for truck : ";
        cin >> choice;
        if (choice=='v')
            v[i]=new Vehicle;
        else if (choice=='t')
            v[i]=new Truck;
        else
        {
            cout << "Error" << endl; //type isn't defined
            i--;
            continue;
        }
        v[i]->input();
    }
    for (int i=0 ; i<n ; i++)
    {
        cout << i+1;
        if (i==0)
            cout << "st vehicle" << endl;
        else if (i==1)
            cout << "nd vehicle" << endl;
        else if (i==2)
            cout << "rd vehicle" << endl;
        else
            cout << "th vehicle" << endl;
        v[i]->output();
    }
    return 0;
}
