#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class TextFile{

protected:
    string getFilename();
    const string FILENAME;
    CMarkup xml;
    bool checkIfFileEmpty();
public:
    TextFile(string filename) : FILENAME(filename){}
};

#endif
