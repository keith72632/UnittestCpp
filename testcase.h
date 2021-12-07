#ifndef TESTCASE_H
#define TESTCASE_H

#include "unittest.h"

class TestCase : public Unittest {
    public:
        void test_one(){
            this->assertTrue(1);
        }
        void test_two(){
            this->assertEqual(1, 1);
        }
        void test_all(){
            this->test_one();
            this->test_two();
        }
};

#endif