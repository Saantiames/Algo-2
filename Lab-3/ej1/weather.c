/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

Weather weather_from_file(FILE* file)
{
    Weather weather;
    /*int _average_temp;
    int _max_temp;
    int _min_temp;
    unsigned int _pressure;
    unsigned int _moisture;
    unsigned int _rainfall;
    */
   int data = fscanf(file, "%d %d %d %u %u %u\n", &weather._average_temp, &weather._max_temp, &weather._min_temp, 
                                                &weather._pressure, &weather._moisture, &weather._rainfall);
    if(data != 6){
      fprintf(stderr, "Formato invalido.\n");
      exit(EXIT_FAILURE);
    }
  

    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, "%d %d %d %u %u %u", weather._average_temp,
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
