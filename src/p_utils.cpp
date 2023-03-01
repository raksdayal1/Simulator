#include "p_util.h"
#include <math.h>


void thread_sleep(double seconds){

    #ifdef _WIN32
        Sleep(seconds*1E3);
    #else
        usleep(seconds*1E6);
    #endif
};

void Euler2Quaternion(double euler[3], double quat[4]){

    double roll, pitch, yaw;
    roll = euler[0];
    pitch = euler[1];
    yaw = euler[2];

    quat[1] = sin(roll/2) * cos(pitch/2) * cos(yaw/2) - cos(roll/2) * sin(pitch/2) * sin(yaw/2);
    quat[2] = cos(roll/2) * sin(pitch/2) * cos(yaw/2) + sin(roll/2) * cos(pitch/2) * sin(yaw/2);
    quat[3] = cos(roll/2) * cos(pitch/2) * sin(yaw/2) - sin(roll/2) * sin(pitch/2) * cos(yaw/2);
    quat[0] = cos(roll/2) * cos(pitch/2) * cos(yaw/2) + sin(roll/2) * sin(pitch/2) * sin(yaw/2);

}

