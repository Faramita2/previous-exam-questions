#ifndef PERFORMANCE_MONITOR_H
#define PERFORMANCE_MONITOR_H

#include <chrono>
#include <iostream>
#ifdef _WIN32
#include <psapi.h>
#include <windows.h>
#elif __APPLE__
#include <mach/mach.h>
#else
#include <fstream>
#include <string>
#include <unistd.h>
#endif

class PerformanceMonitor
{
  public:
    // 开始计时并记录初始内存使用情况
    void start()
    {
        startTime    = std::chrono::high_resolution_clock::now();
        memoryBefore = getMemoryUsage();
    }

    // 停止计时并打印运行时间和内存占用
    void stop()
    {
        auto   endTime     = std::chrono::high_resolution_clock::now();
        double elapsedTime = std::chrono::duration<double, std::milli>(endTime - startTime).count();
        size_t memoryAfter = getMemoryUsage();

        std::cout << "Elapsed time: " << elapsedTime << " ms" << std::endl;
        std::cout << "Memory usage: " << (memoryAfter - memoryBefore) << " KB" << std::endl;
    }

  private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    size_t                                                      memoryBefore;

// 获取当前进程的内存使用情况（单位：KB）
#ifdef __APPLE__
#include <mach/mach.h>
#endif

    size_t getMemoryUsage()
    {
#ifdef _WIN32
        PROCESS_MEMORY_COUNTERS pmc;
        if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
            std::cout << "Windows memory usage: " << pmc.WorkingSetSize / 1024 << " KB"
                      << std::endl;
            return pmc.WorkingSetSize / 1024;
        }
#elif __APPLE__
        struct task_basic_info t_info;
        mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;
        if (KERN_SUCCESS ==
            task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&t_info, &t_info_count)) {
            std::cout << "macOS memory usage: " << t_info.resident_size / 1024 << " KB"
                      << std::endl;
            return t_info.resident_size / 1024;
        }
#else
        std::ifstream statusFile("/proc/self/status");
        std::string   line;
        while (std::getline(statusFile, line)) {
            if (line.find("VmRSS:") != std::string::npos) {
                size_t pos = line.find_first_of("0123456789");
                std::cout << "Linux memory usage: " << std::stoul(line.substr(pos)) << " KB"
                          << std::endl;
                return std::stoul(line.substr(pos));
            }
        }
#endif
        std::cerr << "Failed to retrieve memory usage!" << std::endl;
        return 0;
    }
};

#endif // PERFORMANCE_MONITOR_H