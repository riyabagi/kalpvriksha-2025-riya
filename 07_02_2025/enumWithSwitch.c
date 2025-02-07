#include <stdio.h>

enum traffic
{
    red,
    yellow,
    green
};

void trafficLinghtSignal(enum traffic signal)
{
  switch (signal)
    {
    case red:
        printf("Stop");
        break;
    case yellow:
        printf("Get Ready");
        break;
    case green:
        printf("Go");
        break;
    
    default:
        break;
    }
}

int main()
{
    enum traffic signal = yellow;
    trafficLinghtSignal(signal);
    
    return 0;
}