/*
 * Created by Rakshit Allamraju
 * Date: Aug.16 2022
 *
 * Modified by Rakshit Allamraju
 * Date: Sept 21 2022
 */

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

#include "sim.h"
//#include "libAP_JSON.h"

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

#include <json.hpp>
#include "simstructs.h"

using namespace std;
using json = nlohmann::json;

int main(int argc, char* argv[])
{
    int result = 0;
    
    // read the config file. file should be in same level as the build folder
    std::ifstream file("../config.json");
    if ( file )
    {
        json simconfig;
        file >> simconfig;
        
        // read the configuration
        cout << "[Simulation]: Reading configuration file" << endl;

        // read the Ip address of physics backend 
        if ( simconfig.contains("IP Address") )
        {
            string ip_addr;
            ip_addr = simconfig["IP Address"];
            cout << "[Config]: IP address of physics backend set to " << ip_addr << endl;

        }
        else // no ip address field
        {
            cout << "[Config]: Config file doesnt contain field IP Address" << endl;
            exit(-1);
        }

        // read the vehicles defined for simulation
        if ( simconfig.contains("Vehicles") )
        {
            json vjson;
            vjson = simconfig["Vehicles"];

            // read quadcopter data
            if ( vjson.contains("Quadcopters") && vjson["Quadcopters"].size() != 0 )
            {
                cout << "[Config]: Quadcopters are defined in configuration" << endl;
                
                // find total number of quadcopters
                int total_quads = vjson["Quadcopters"].size();

                // Create an array to hold Quadcopter information
                Vehicles* Quads = new Vehicles[total_quads];

                int Counter(0);
                for (json::iterator it = vjson["Quadcopters"].begin(); it != vjson["Quadcopters"].end(); ++it) {
                    // std::cout << it.key() << " : " << it.value() << "\n";
                    // Key is unique name given to the vehicle
                    Quads[Counter].name = it.key();
                    Quads[Counter].id = it.value()["sysID"];
                    Quads[Counter].x_start = it.value()["X Start"];
                    Quads[Counter].y_start = it.value()["Y Start"];
                    Quads[Counter].z_start = it.value()["Z Start"];

                    Counter++;
                }

            } //end if contains quadcopters
            else 
            {
                cout << "[Config]: No Quadcopters are defined in configuration" << endl;
            }


            // read fixed wing data
            if ( vjson.contains("FixedWings") && vjson["FixedWings"].size() != 0 )
            {
                cout << "[Config]: Fixed Wings are defined in configuration" << endl;
                
                // find total number of fixed wings
                int total_fw = vjson["FixedWings"].size();

                // Create an array to hold fixedwing information
                Vehicles* FW = new Vehicles[total_fw];

                int Counter(0);
                for (json::iterator it = vjson["FixedWings"].begin(); it != vjson["FixedWings"].end(); ++it) {
                    // std::cout << it.key() << " : " << it.value() << "\n";
                    // Key is unique name given to the vehicle
                    FW[Counter].name = it.key();
                    FW[Counter].id = it.value()["sysID"];
                    FW[Counter].x_start = it.value()["X Start"];
                    FW[Counter].y_start = it.value()["Y Start"];
                    FW[Counter].z_start = it.value()["Z Start"];

                    Counter++;
                }

            } // end if contains fixedwing
            else
            {
                cout << "[Config]: No Fixed Wings are defined in configuration" << endl;
            }


            // read rover data
            if ( vjson.contains("Rovers") && vjson["Rovers"].size() != 0)
            {
                cout << "[Config]: Rovers are defined in configuration" << endl;
                
                // find total number of Rovers
                int total_rov = vjson["Rovers"].size();

                // Create an array to hold rover information
                Vehicles* Rover = new Vehicles[total_rov];

                int Counter(0);
                for (json::iterator it = vjson["Rovers"].begin(); it != vjson["Rovers"].end(); ++it) {
                    // std::cout << it.key() << " : " << it.value() << "\n";
                    // Key is unique name given to the vehicle
                    Rover[Counter].name = it.key();
                    Rover[Counter].id = it.value()["sysID"];
                    Rover[Counter].x_start = it.value()["X Start"];
                    Rover[Counter].y_start = it.value()["Y Start"];
                    Rover[Counter].z_start = it.value()["Z Start"];

                    Counter++;
                }

            } // end if contains rover
            else
            {
                cout << "[Config]: No Rovers are defined in configuration" << endl;
            }

        }
        else // Vehicles not defined ERROR
        {
            cout << "[Config]: Error...no Vehicles field found in config file. Please define." << endl;
            exit(-1);
        } //end if else simconfig contains vehicles

        cout << "[Config]: Reading vehicle configurations complete" << endl;         

    }
    else // file doesnt exist
    {
        cout << "[Simulation]: No file found. Please make sure 'config.json' exists on the same level as the build folder" << endl;
        exit(-1);
    }


    // TODO: Start CMD backend here

    
    return result;
}