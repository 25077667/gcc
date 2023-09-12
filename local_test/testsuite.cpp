#include <string>
#include <chrono>
#include <iostream>
#include <cmath>

int main()
{
    // Test the performance of std::string::rfind(), we loop over 1000000 times
    // And the source string is [1, 10, 100, 1000, 10000, 100000] long
    // And the target string is exactly 1 char long
    std::string target = "b";
    std::chrono::steady_clock::time_point start, end;
    std::chrono::duration<double> time_used;

    for (int i = 0; i < 6; i++)
    {
        std::string source = target;
        source.append(std::string(pow(10, i), 'a'));
        start = std::chrono::steady_clock::now();
        for (int j = 0; j < 1000000; j++)
        {
            source.rfind(target);
        }
        end = std::chrono::steady_clock::now();
        time_used = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
        std::cout << "source length: " << source.length() << ", time used: " << time_used.count() << std::endl;
    }

    return 0;
}