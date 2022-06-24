#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class XmlFile{

protected:
    CMarkup xml;
    const string FILENAME;

    string getFilename();
    bool checkIfFileEmpty();

public:
    XmlFile(string filename) : FILENAME(filename){}
};

#endif
