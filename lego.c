#define MOTOR_RIGHT OUT_A
#define MOTOR_LEFT OUT_B
#define COLOR_SENSOR S1
#define ULTRA_SENSOR S4

#define FORCE 100

#define DISTANCE 100

task sensors()
{
    SetSensorColorFull(COLOR_SENSOR);
    SetSensorUltrasonic(ULTRA_SENSOR);
    Wait(15);
}

task forward()
{
    OnRev(MOTOR_RIGHT, FORCE);
    OnRev(MOTOR_LEFT, FORCE);
}

task rotate()
{
    OnRev(MOTOR_RIGHT, FORCE);
    OnFwd(MOTOR_LEFT, FORCE);
}

task wheels()
{
    while(true)
    {
        if(SensorUS(ULTRA_SENSOR) < DISTANCE) // Trying to find an object
        {
            forward();
        }
        else
        {
            rotate();
        }
    }
}

task main()
{
    Wait(3000);
    Precedes(wheels, sensors);
}
