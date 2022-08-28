#include <iostream>
#include <ctime>

class Timer
{

    time_t *startTime{nullptr}, *endTime{nullptr};
    std::string out{};

public:
    Timer(const std::string &str = "Execution Time : ") : startTime{new time_t}, endTime{new time_t}, out{str}
    {
        time(this->startTime);
    };
    ~Timer();
};

Timer::~Timer()
{
    time(this->endTime);
    double diff{difftime(*this->endTime, *this->startTime)};
    std::cout << "\n"
              << this->out << diff << "s.\n";
    delete this->startTime;
    delete this->endTime;
};
int main()
{
    Timer execution_time{"main execution time : "};
    getchar();
    return 0;
};
