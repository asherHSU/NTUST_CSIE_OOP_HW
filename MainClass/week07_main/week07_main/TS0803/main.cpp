#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

class MemorySimulator {
public:
    MemorySimulator(size_t size) : memory(size, 0) {}

    void setMemory(size_t position, const std::string& type, const std::string& value) {
        if (type == "char") {
            if (position >= memory.size()) {
                std::cout << "Violation Access\n";
                return;
            }
            memory[position] = value[0];
        }
        else if (type == "short") {
            if (position + sizeof(short) > memory.size()) {
                std::cout << "Violation Access\n";
                return;
            }
            short val = static_cast<short>(std::stoi(value));
            std::memcpy(&memory[position], &val, sizeof(short));
        }
        else if (type == "int") {
            if (position + sizeof(int) > memory.size()) {
                std::cout << "Violation Access\n";
                return;
            }
            int val = std::stoi(value);
            std::memcpy(&memory[position], &val, sizeof(int));
        }
        else if (type == "String") {
            size_t len = value.size();
            if (position + len > memory.size()) {
                std::cout << "Violation Access\n";
                return;
            }
            std::memcpy(&memory[position], value.c_str(), len);
        }
    }

    void getMemory(size_t position, const std::string& type) {
        if (type == "char") {
            if (position >= memory.size()) {
                std::cout << "Violation Access\n";
                return;
            }
            std::cout << memory[position] << "\n";
        }
        else if (type == "short") {
            if (position + sizeof(short) > memory.size()) {
                std::cout << "Violation Access\n";
                return;
            }
            short val;
            std::memcpy(&val, &memory[position], sizeof(short));
            std::cout << val << "\n";
        }
        else if (type == "int") {
            if (position + sizeof(int) > memory.size()) {
                std::cout << "Violation Access\n";
                return;
            }
            int val;
            std::memcpy(&val, &memory[position], sizeof(int));
            std::cout << val << "\n";
        }
        else if (type == "String") {
            if (position >= memory.size()) {
                std::cout << "Violation Access\n";
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
    for (size_t i = 0; i < numCommands; ++i) {
        std::getline(std::cin, command);
        std::istringstream iss(command);
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

    return 0;
}
