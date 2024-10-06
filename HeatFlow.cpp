#include "HeatFlow.hpp"

HeatFlow::HeatFlow(float initial_temperature, int _number_of_sections, float _K, map<int, float> _sources_and_sinks)
{
    rod.resize(_number_of_sections);
    
    for(int i = 0; i < _number_of_sections; i++)
    {
        rod[i] = initial_temperature;
    }
    
    for(int i = 0; i < _number_of_sections; i++)
    {
        if (_sources_and_sinks[i] != 0) //This means I cannot set a source or sink to have a value of 0
        {
            rod[i] = _sources_and_sinks[i];
        }
    }

    K = _K;
    number_of_sections = _number_of_sections;
    sources_and_sinks = _sources_and_sinks;
}

void HeatFlow::pretty_print()
{
  
    string s_rod;
    
    for (int i = 0; i < number_of_sections; i++)
    {
        s_rod=to_string(rod[i]);
        cout << "+-";
        stringstream s;
              s << rod[i];
              s_rod = s.str();
        for (int i = 0; i < s_rod.length(); i++)
        {
            cout << "-";
        }
        cout << "-";
        
    }
    cout << "+\n";
    for (int i = 0; i < number_of_sections; i++)
    {
        cout << "| " << rod[i] << " ";
    }
    cout << "|\n";
    for (int i = 0; i < number_of_sections; i++)
    {
        s_rod = to_string(rod[i]);
        cout << "+-";
        stringstream s;
              s << rod[i];
              s_rod = s.str();
        for (int i = 0; i < s_rod.length(); i++)
        {
            cout << "-";
        }
        cout << "-";
        
    }
    cout << "+" << endl<<endl;
    
}

void HeatFlow::tick(int ticker)
{
    for (int i = 0; i < ticker; i++)
    {
        vector<float> initial_rod = rod;
        for (int i = 0; i < number_of_sections; i++)
        {
            if(i-1 >= 0 && i+1 < number_of_sections){
                rod[i] = initial_rod[i] + K*(initial_rod[i+1] - (2*initial_rod[i]) + initial_rod[i-1]);
            }
            
            else if (i-1 < 0){
                rod[i] = initial_rod[i] + K*(initial_rod[i+1] - initial_rod[i]);
            }
            
            else if (i+1 == number_of_sections){
                rod[i] = initial_rod[i] + K*(initial_rod[i-1] - initial_rod[i]);
            }
            
            if (sources_and_sinks[i] != 0){
                rod[i] = sources_and_sinks[i];
            }
            
        }
    }
}

float HeatFlow::get_rod(int pos)
{
    float _rod = rod[pos];
    return _rod;
};
