#include "TextFile.h"

string TextFile::getFilename(){
    return FILENAME;
}

bool TextFile::checkIfFileEmpty(){

    bool fileExists = xml.Load(FILENAME);
        return fileExists;
}
