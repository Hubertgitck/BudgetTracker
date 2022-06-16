#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>

#include "Markup.h"

using namespace std;

class TextFile{


protected:
    CMarkup xml;
    bool checkIfFileEmpty();
};


#endif
