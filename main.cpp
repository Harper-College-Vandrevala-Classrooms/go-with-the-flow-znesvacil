#include "HeatFlow.hpp"
#include <cassert>

using namespace std;

map<int, float> sourcesandsinks_h {{ 0, 100}, {2, 200}};
map<int, float> sourcesandsinks_n {{ 1, -50}, {5, 200}, {8, 10}};
map<int, float> from_the_middle {{ 4, 200}};
map<int, float> from_the_ends {{ 0, 200}, {8, 200}};


HeatFlow h(20, 5, 0.4, sourcesandsinks_h);
HeatFlow n(50, 10, 0.5, sourcesandsinks_n);
HeatFlow middle_test(10, 9, 0.1, from_the_middle);
HeatFlow ends_test(10, 9, 0.1, from_the_ends);


int main() {
    cout << "With rod h:" << endl;
    assert(h.get_rod(0) == 100);
    assert(h.get_rod(1) == 20);
    assert(h.get_rod(2) == 200);
    assert(h.get_rod(3) == 20);
    assert(h.get_rod(4) == 20);
    h.pretty_print();
    
    h.tick(1);
    assert(h.get_rod(0) == 100);
    assert(h.get_rod(1) == 124);
    assert(h.get_rod(2) == 200);
    assert(h.get_rod(3) == 92);
    assert(h.get_rod(4) == 20);
    h.pretty_print();
    
    h.tick(1);
    //Comparisons with floating point numbers don't work, verify instead by checking the printed values
    h.pretty_print(); //These match what I calculated on paper
    
    cout << "With rod N:" << endl;
    assert(n.get_rod(0) == 50);
    assert(n.get_rod(1) == -50);
    assert(n.get_rod(2) == 50);
    assert(n.get_rod(3) == 50);
    assert(n.get_rod(4) == 50);
    assert(n.get_rod(5) == 200);
    assert(n.get_rod(6) == 50);
    assert(n.get_rod(7) == 50);
    assert(n.get_rod(8) == 10);
    assert(n.get_rod(9) == 50);
    n.pretty_print();
    
    n.tick(1);
    assert(n.get_rod(0) == 0);
    assert(n.get_rod(1) == -50);
    assert(n.get_rod(2) == 0);
    assert(n.get_rod(3) == 50);
    assert(n.get_rod(4) == 125);
    assert(n.get_rod(5) == 200);
    assert(n.get_rod(6) == 125);
    assert(n.get_rod(7) == 30);
    assert(n.get_rod(8) == 10);
    assert(n.get_rod(9) == 30);
    n.pretty_print();

    n.tick(1); //Yet again, can't compare floats
    n.pretty_print(); //It matches my calculations
    
    cout << "Testing putting a source in the middle:" << endl;
    cout << "At the start:" << endl;
    
    middle_test.pretty_print();
    cout << "After 10 ticks:" << endl;
    middle_test.tick(10);
    middle_test.pretty_print();
    cout << "After 100 ticks:" << endl;
    middle_test.tick(100);
    middle_test.pretty_print();
    
    cout << "Testing putting a source at the ends:" << endl;
    cout << "At the start:" << endl;
    
    ends_test.pretty_print();
    cout << "After 10 ticks:" << endl;
    ends_test.tick(10);
    ends_test.pretty_print();
    cout << "After 100 ticks:" << endl;
    ends_test.tick(100);
    ends_test.pretty_print();
  
    cout << "Success!" <<endl;
    return 0;
}

