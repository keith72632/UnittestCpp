#include "unittest.h"

Unittest::Unittest(void){
    _pass_flags = 0;
    _err_flags = 0;
}

void Unittest::calculateResults(void)
{
    if(!_err_flags)
    {
        std::cout << _pass_flags << " tests passed" << std::endl;
        return;
    }
    else{
        std::cout << _err_flags << " errors" << std::endl;
        return;
    }
}

Unittest::~Unittest(){
    this->calculateResults();
}