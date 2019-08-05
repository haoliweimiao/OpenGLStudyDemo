/*
 * @Description: null
 * @Author: haoliwei
 * @Date: 2019-06-24 21:18:49
 * @LastEditTime: 2019-07-20 14:45:03
 * @LastEditors: Please set LastEditors
 */

#include "ThreadSleepUtils.hpp"

/**
 * @param time:sleep time,ms
 */
void sleep(long time)
{
    using namespace std::chrono_literals;
    // auto start = std::chrono::high_resolution_clock::now();

    typedef std::chrono::duration<long> CustomDuration;

    //CustomDuration test1 = std::chrono::milliseconds(1);//Forbidden
    //CustomDuration test1 = std::chrono::duration_cast<CustomDuration>(std::chrono::milliseconds(1)); //Permitted, will be truncated
    //CustomDuration test2 = std::chrono::duration_cast<CustomDuration>(1ms); //Permitted, may be easier to read
    CustomDuration waitTime = std::chrono::duration_cast<CustomDuration>(std::chrono::milliseconds(time));
    std::this_thread::sleep_for(waitTime);
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::milli> elapsed = end - start;
    // std::cout << "Waited " << elapsed.count() << " ms\n";
}