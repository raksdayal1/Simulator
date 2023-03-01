#include <string>

typedef enum {QUAD_TYPE, FW_TYPE, ROVER_TYPE} TYPE;

struct Vehicles
{
    std::string name;
    int id;
    float x_start;
    float y_start;
    float z_start;
    int port_no;

    TYPE type;

};
