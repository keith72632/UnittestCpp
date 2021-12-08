#ifndef UNITTEST_H
#define UNITTEST_H

#include <vector>
#include <iostream>

class Unittest {
    private:
        int _pass_flags;
        int _err_flags;
    protected:
        std::vector<void (*)()> functions;
    public:
        Unittest();
        template<typename T> bool assertTrue(T value){
            if(!value)
            {
                _err_flags++;
                return false;
            }
            _pass_flags++;
            return true;
        }
        template<typename T> bool assertEqual(T val1, T val2){
        if(val1 == val2)
            {
                _pass_flags++;
                return true;
            }
            _err_flags++;
            return false;
        }
        void calculateResults();
        ~Unittest();
};

#endif