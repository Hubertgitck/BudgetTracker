#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class XmlFile{

protected:
    CMarkup xml;
    string getFilename();
    const string FILENAME;
    bool checkIfFileEmpty();

public:
    XmlFile(string filename) : FILENAME(filename){}
};

#endif
