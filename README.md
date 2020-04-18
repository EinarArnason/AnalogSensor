# AnalogSensor library

Interface for implementing code for analog sensors

## The What

This is a header only library interface that includes common non-platform specific functionality meant for analog sensors.

## The Why

The goal is to make cross platform implementation easier for analog sensor reading.

## The How

Because the library is header only, it only needs to be included.

```c++
#include "AnalogSensor.h"

class SomeSensor : public AnalogSensor {
    ...
}
```

### Using cmake

```cmake
add_subdirectory(${analogSensorDir})
target_link_libraries(${PROJECT_NAME} AnalogSensor)
```

## The Who

Einar Arnason  
<https://github.com/EinarArnason>  
<https://www.linkedin.com/in/einararnason/>
