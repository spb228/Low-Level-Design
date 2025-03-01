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
        cout << "creating vehicle" << endl;
    }

    ~Vehicle()
    {   
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
    const int sedan_size = 1; // 1 parking spot
    const int limo_size = 2;  // 2 parking spots
    const int semi_size = 3;  // 3 parking spots
};

class Floor
{
public:
    Floor(const int floor_num_in, const int num_of_spots_in, const int num_of_rows_in) :
        floor_num(floor_num_in),
        num_of_spots(num_of_spots_in),
        num_of_rows(num_of_rows_in)
    {
        cout << "creating floor: " << floor_num << endl; 
        create_spots(num_of_spots); 
    }

    ~Floor()
    {
    }

    void create_spots(const int num_of_spots)
    {
        spots_vec = vector<bool>(num_of_spots, false);
    }

    int get_empty_spot()
    {
        for (int i = 0; i < spots_vec.size(); i++)
        {
            if (spots_vec[i] == false)
            {
                return i; 
            }
        }
        return -1; // no empty spots
    }

    void add_car(const int spot_num)
    {
        if (spot_num >= spots_vec.size() || spot_num < 0)
        {
            cout << "invalid spot number";
            return;
        }
        spots_vec[spot_num] = true; 
        cout << "car added to floor: " << floor_num << " , " << "spot: " << spot_num << endl; 
    }

    void remove_car(const int spot_num)
    {
        if (spot_num >= spots_vec.size() || spot_num < 0)
        {
            cout << "invalid spot number";
            return;
        }
        spots_vec[spot_num] = false; 
        cout << "car removed from floor: " << floor_num << " , " << "spot: " << spot_num << endl; 
    }

    void print_floor_spots()
    {
        cout << endl << "Floor: " << floor_num << endl; 
        for (int i = 0; i < spots_vec.size(); i++)
        {
            cout << "Spot: " << i << " " << spots_vec[i] << endl; 
        }
        cout << endl;
    }
    
private:
    int floor_num;
    int num_of_spots; 
    int num_of_rows; 
    vector<bool> spots_vec; // false denotes spot empty, true denotes spot taken
};


int main()
{
    Vehicle sedan_1(vehicle_type_enum::SEDAN); 
    cout << "Vehicle type: " << sedan_1.get_vehicle_type() << endl; 
    cout << "Vehicle size: " << sedan_1.get_vehicle_size() << endl; 
    
    int floor_num_0 = 0; 
    int num_spots = 10; 
    int num_rows = 1; 
    Floor floor_0(floor_num_0, num_spots, num_rows); 
    floor_0.print_floor_spots(); 
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


Lot Floor Design:
- 10 adjacent parking spots in one row for now for each floor. 

 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |

*/
