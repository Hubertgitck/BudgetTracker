#include "TextFile.h"

bool TextFile::checkIfFileEmpty(){

    bool fileExists = xml.Load("users.xml");
        return fileExists;
}
