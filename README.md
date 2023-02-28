This document provides the general outline of the Simulator
The simualtor is build with the ardupilot source code and these commands needs to be run to install the necessary tools required by the ardupilot source code

BUILDING ARDUPILOT FOR SITL 
The ardupilot source code is already provided in the codebase but the executable needs to be built from scratch. In this document the root directory is defined as $ROOT

1. cd into $ROOT/ardupilot and run the following commands

    sudo apt-get update
    Tools/environment_install/install-prereqs-ubuntu.sh -y

2. Once the required packages installation is complete compile the ardupilot code for SITL with the following commands

    ./waf configure --board sitl
    ./waf copter plane rover

3. The last command will compile the ardupilot software for plane, copter and rover type vehicles
4. The binaries for copter, plane and rover should appear in $ROOT/ardupilot/build/sitl/bin

SETTING THE CONFIG.JSON FILE
The vehicles that are required to operate in the simulation are defined in the config.json file. This file is required to be situated at the same level as the build folder
The config.json file are required to contain the following fields
1. IP Address
2.            Vehicles
                |
                |
    -------------------------------
    |               |             |
    |               |             |
    Quadcopters  FixedWings     Rovers
      / \              / \          / \
     /   \            /   \        /   \
    quad1 quad2 ..   fw1  fw2 ..  rov1  rov2 ..

3.             Home
                |
                |
    --------------------------
    |            |           |
    |            |           |
    Latitude  Longitude   Altitude