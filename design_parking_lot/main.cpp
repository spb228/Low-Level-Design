#include <iostream>
#include <vector>
#include <string> 

using namespace std;

enum vehicle_type_enum
{
    SEDAN, // 0 
    LIMO, // 1
    SEMI // 2
};

class Vehicle
{
public:
    Vehicle(const vehicle_type_enum v_type_in) :
        v_type(v_type_in)
    {
        cout << "creating vehicle";
    }

    vehicle_type_enum get_vehicle_type()
    {
        return v_type; 
    }

    int get_vehicle_size()
    {
        if (v_type == vehicle_type_enum::SEDAN)
        {
            return sedan_size; 
        }
        else if (v_type == vehicle_type_enum::LIMO)
        {
            return limo_size; 
        }
        else if (v_type == vehicle_type_enum::SEMI)
        {
            return semi_size; 
        }

        return -1; // error: v_type is not valid
    }

private:
    vehicle_type_enum v_type; 
    int v_size;
    const int sedan_size = 1; 
    const int limo_size = 2; 
    const int semi_size = 3; 
};



int main()
{
    cout << "test_1" << endl;
    

    
}

/* 
Requirements
- variable floors - floor class
- variable spots (but they are all in one row)
- 3 types of vehicles - vehicle class
    1) car - 1 spot
    2) limo - 2 consec spots
    3) truck - 3 consec spots
- Vehicle gets assigned lowest floor smallest value spot
- Vechicle gets charged at the exit for variable time they stayed



*/
