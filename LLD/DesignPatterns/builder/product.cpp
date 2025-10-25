#include <iostream>
using namespace std;

class House {
private:
    std::string walls;
    std::string roof;
    std::string floor;

public:
    void setWalls(const std::string& w) { walls = w; }
    void setRoof(const std::string& r) { roof = r; }
    void setFloor(const std::string& f) { floor = f; }

    void showHouse() const {
        std::cout << "House with " << walls << ", " << roof << ", and " << floor << "." << std::endl;
    }
};
