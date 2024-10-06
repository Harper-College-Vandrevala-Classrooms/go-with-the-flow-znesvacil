#pragma once
#ifndef HeatFlow_hpp
#define HeatFlow_hpp
#endif

#include <vector>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

class HeatFlow
{
private:
    vector<float> rod;
    float K;
    int number_of_sections;
    map<int, float> sources_and_sinks;
public:
    void tick(int ticker);
    void pretty_print();
    HeatFlow(float initial_temperature, int _number_of_sections, float _K, map<int, float> _sources_and_sinks);
    float get_rod(int pos);
};
