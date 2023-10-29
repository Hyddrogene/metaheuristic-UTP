#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
// JSON
#include "nlohmann-json/json.hpp"
using json = nlohmann::json;

using namespace std;


/*
 * Arguments parsing
 */
std::vector< std::string > args;

void parseArgs(int argc, const char **argv) {
    if(args.empty()) { // We can parse args only once
        for(int i=0; i<argc; ++i) {
            args.push_back(argv[i]);
        }
    }
}//FinFunction

bool argExists(std::string arg) {
    return std::find(args.begin(), args.end(), arg) != args.end();
}//FinFunction

std::string getArg(std::string arg) {
    auto it = std::find(args.begin(), args.end(), arg);
    if(it != args.end() && ++it != args.end()) {
        return *it;
    }
    return std::string("");
}//FinFunction

int main(int argc, const char **argv)
{
    std::string jsonFilename;

    parseArgs(argc, argv);
    if(!argExists("-i")) {
        std::cerr << "ERROR: You have to give the input JSON file (-i <jsonFileName>)." << std::endl;
         jsonFilename = "/home/etud/minizincPython/example_extension_v2.json";
        //return 1;
    }
    else {
        jsonFilename = getArg("-i");
    }

    // First we read the JSON file
    std::ifstream jsonInputFile(jsonFilename);
    json jFile;

    if(!jsonInputFile.good() || !jsonInputFile.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier '" << jsonFilename << "'" << std::endl;
        return 1;
    }

    jsonInputFile >> jFile;
    /*
    if(1) {
        std::cout << "===[ FAILED ]===" << std::endl;
        solution.print();
        solution.print_outputs();
        std::cout << "===[ FAILED ]===" << std::endl;
    } else {
        std::cout << "===[ SUCCEEDED ]===" << std::endl;
        solution.print();
        solution.print_outputs();
        std::cout << "===[ SUCCEEDED ]===" << std::endl;

        solution.outputXML();
    }*/

    return 0;
}//FinMain
