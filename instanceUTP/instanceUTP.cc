#include "instanceUTP.hh"


instanceUTP::instanceUTP(std::string filenameJson):filenameJson(filenameJson){
    std::ifstream jsonInputFile(filenameJson);
    if(!jsonInputFile.good() || !jsonInputFile.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier '" << filenameJson << "'" << std::endl;
    }
    jsonInputFile >> jFile;
}//FinMethod

void instanceUTP::generate(){

}//FinMethod
