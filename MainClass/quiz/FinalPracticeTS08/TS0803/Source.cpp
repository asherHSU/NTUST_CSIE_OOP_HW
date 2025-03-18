#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>

class MemorySimulator {
public:
    MemorySimulator(size_t size) : memory(size, 0) {}

    void setMemory(size_t position, const std::string& type, const std::string& value) {
        if (type == "char") {
            if (position > memory.size()) {
                std::cout << "Violation Access.\n";
                return;
            }

            if (value.length() >= 3 && strcmp(value.c_str(), "128") > 0) {
                memory[position] = strtol("128", nullptr, 10);
            }

            memory[position] = strtol(value.c_str(),nullptr,10);
        }
        else if (type == "short") {
            if (position + sizeof(short) >= memory.size()) {
                std::cout << "Violation Access.\n";
                return;
            }

            if (value.length() >= 5 && strcmp(value.c_str(), "32767") > 0) {
                short val = static_cast<short>(std::stoi("32767"));
                std::memcpy(&memory[position], &val, sizeof(short));
                return;
            }

            short val = static_cast<short>(std::stoi(value));
            std::memcpy(&memory[position], &val, sizeof(short));
        }
        else if (type == "int") {
            if (position + sizeof(int) > memory.size()) {
                std::cout << "Violation Access.\n";
                return;
            }

            int val = std::atoi(value.c_str());
            std::memcpy(&memory[position], &val, sizeof(int));
        }
        else if (type == "String") {
            size_t len = value.size();
            if (position + len > memory.size()) {
                std::cout << "Violation Access.\n";
                std::memcpy(&memory[position], value.c_str(), memory.size() - len - 1);
                return;
            }
            std::memcpy(&memory[position], value.c_str(), len);
        }
    }

    void getMemory(size_t position, const std::string& type) {
        if (type == "char") {
            if (position >= memory.size()) {
                std::cout << "Violation Access.\n";
                return;
            }
            uint8_t val;
            std::memcpy(&val, &memory[position], sizeof(uint8_t));
            std::cout << (int)val << "\n";
        }
        else if (type == "short") {
            if (position + sizeof(short) > memory.size()) {
                std::cout << "Violation Access.\n";
                return;
            }
            short val;
            std::memcpy(&val, &memory[position], sizeof(short));
            std::cout << val << "\n";
        }
        else if (type == "int") {
            if (position + sizeof(int) > memory.size()) {
                std::cout << "Violation Access.\n";
                return;
            }
            int val;
            std::memcpy(&val, &memory[position], sizeof(int));
            std::cout << val << "\n";
        }
        else if (type == "String") {
            if (position >= memory.size()) {
                std::cout << "Violation Access.\n";
                return;
            }
            for (size_t i = position; i < memory.size(); ++i) {
                if (memory[i] == '\0') break;
                std::cout << memory[i];
            }
            std::cout << "\n";
        }
    }

private:
    std::vector<uint8_t> memory;
};

int main() {
    size_t memorySize;
    std::cin >> memorySize;
    MemorySimulator simulator(memorySize);

    size_t numCommands;
    std::cin >> numCommands;
    std::string command;
    std::getline(std::cin, command); // to consume the newline after the number of commands

    std::vector<std::string> commands;
    for (size_t i = 0; i < numCommands; ++i) {
        std::getline(std::cin, command);
        commands.push_back(command);
        //std::cout << command << " ";
    }

    for (const auto& cmd : commands) {
        std::istringstream iss(cmd);
        std::string operation;
        iss >> operation;
        if (operation == "Set") {
            size_t position;
            std::string type, value;
            iss >> position >> type;
            std::getline(iss, value);
            value = value.substr(1); // remove the leading space
            simulator.setMemory(position, type, value);
        }
        else if (operation == "Get") {
            size_t position;
            std::string type;
            iss >> position >> type;
            simulator.getMemory(position, type);
        }
    }

    //simulator.printMemoryHexDump(); // Print memory dump at the end

    return 0;
}
