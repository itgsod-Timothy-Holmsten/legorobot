#define MOTOR_RIGHT OUT_A
#define MOTOR_LEFT OUT_B
#define COLOR_SENSOR S1
#define ULTRA_SENSOR S4

#define FORCE 100

#define DISTANCE 100

void forward()
{
    OnRev(MOTOR_RIGHT, FORCE);
    OnRev(MOTOR_LEFT, FORCE);
}

void backward()
{
    OnFwd(MOTOR_LEFT, FORCE);
    OnFwd(MOTOR_RIGHT, FORCE);
}

void rotate()
{
    OnRev(MOTOR_RIGHT, FORCE);
    OnFwd(MOTOR_LEFT, FORCE);
}

task robot()
{
    while(true)
    {
        if(Sensor(COLOR_SENSOR) < 3)
        {
            backward();
            Wait(300);
            rotate();
            Wait(300);
        }
        else
        {
            if(SensorUS(ULTRA_SENSOR) < DISTANCE) // Trying to find an object
            {
                forward();
                Wait(100);
            }
            else
            {
                rotate();
            }
            Wait(15);
        }
    }
}

task main()
{
    SetSensorColorFull(COLOR_SENSOR);
    SetSensorUltrasonic(ULTRA_SENSOR);

    Wait(3000);
    robot();
}
