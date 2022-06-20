#include "XmlFile.h"

string XmlFile::getFilename(){
    return FILENAME;
}

bool XmlFile::checkIfFileEmpty(){

    bool fileExists = xml.Load(FILENAME);
        return fileExists;
}
