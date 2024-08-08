#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// Base class for all roles in the bank
class Employee {
    protected:
        std::string name;
        std::string position;

    public:
        Employee(const std::string &name, const std::string &position) 
            : name(name), position(position) {}

        virtual void display() {
            std::cout << position << ": " << name << std::endl;
        }
};

// Derived classes for each role
class CMD : public Employee {
    public:
        CMD(const std::string &name) : Employee(name, "CMD") {}
};

class ExecutiveDirector : public Employee {
    public:
        ExecutiveDirector(const std::string &name) : Employee(name, "Executive Director") {}
};

class GeneralManager : public Employee {
    public:
        GeneralManager(const std::string &name) : Employee(name, "General Manager") {}
};

class DeputyGeneralManager : public Employee {
    public:
        DeputyGeneralManager(const std::string &name) : Employee(name, "Deputy General Manager") {}
};

class SeniorOfficer : public Employee {
    public:
        SeniorOfficer(const std::string &name) : Employee(name, "Senior Officer") {}
};

class Officer : public Employee {
    public:
        Officer(const std::string &name) : Employee(name, "Officer") {}
};

class AssistantOfficer : public Employee {
    public:
        AssistantOfficer(const std::string &name) : Employee(name, "Assistant Officer") {}
};

class ProbationaryOfficer : public Employee {
    public:
        ProbationaryOfficer(const std::string &name) : Employee(name, "Probationary Officer") {}
};

// Bank hierarchy class using composition
class BankHierarchy {
    private:
        std::unordered_map<std::string, std::vector<Employee*>> branchData;

    public:
        BankHierarchy() {
            // Initialize data for branches
            branchData["Central"] = {
                new CMD("Mr. John Doe"),
                new ExecutiveDirector("Mr. Alan Smith"),
                new GeneralManager("Mr. James Brown"),
                new DeputyGeneralManager("Ms. Laura Davis"),
                new SeniorOfficer("Mr. Robert Wilson"),
                new Officer("Ms. Emma Johnson"),
                new AssistantOfficer("Mr. William Jones"),
                new ProbationaryOfficer("Ms. Olivia Taylor")
            };

            branchData["North"] = {
                new CMD("Ms. Jane Doe"),
                new ExecutiveDirector("Mr. Michael Scott"),
                new GeneralManager("Mr. David Clark"),
                new DeputyGeneralManager("Ms. Susan Lee"),
                new SeniorOfficer("Mr. Joseph Walker"),
                new Officer("Ms. Emily Hall"),
                new AssistantOfficer("Mr. Chris Young"),
                new ProbationaryOfficer("Ms. Sophia Martinez")
            };

            branchData["South"] = {
                new CMD("Mr. Richard Roe"),
                new ExecutiveDirector("Ms. Jessica White"),
                new GeneralManager("Mr. Paul Harris"),
                new DeputyGeneralManager("Ms. Patricia Lewis"),
                new SeniorOfficer("Mr. George King"),
                new Officer("Ms. Lily Wright"),
                new AssistantOfficer("Mr. Henry Green"),
                new ProbationaryOfficer("Ms. Grace Adams")
            };
        }

        void displayHierarchy(const std::string &branchName) {
            if (branchData.find(branchName) != branchData.end()) {
                std::cout << "Branch: " << branchName << std::endl;
                for (auto &employee : branchData[branchName]) {
                    employee->display();
                }
            } else {
                std::cout << "Branch not found. Please check the branch name and try again." << std::endl;
            }
        }

        ~BankHierarchy() {
            // Clean up dynamically allocated memory
            for (auto &pair : branchData) {
                for (auto &employee : pair.second) {
                    delete employee;
                }
            }
        }
};

int main() {
    BankHierarchy bank;
    std::string branchName;

    std::cout << "Enter the branch name: ";
    std::getline(std::cin, branchName);

    bank.displayHierarchy(branchName);

    return 0;
}
