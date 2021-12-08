#include <iostream>
#include <string>
#include <algorithm>

struct Frame {
    int len;
    int data;
    Frame(int l, int d)
    {
        this->data = d;
        this->len = l;
    }
    ~Frame(){
        std::cout << "Frame destroyed" << std::endl;
    }
};

void funkshun()
{
    std::cout << "hunnnngnggg" << std::endl;
}

void run_funkshun(void(*func)())
{
    func();
}

void funkshun2(std::string s)
{
    std::cout << s << std::endl;
}

void run_funkshun2(void(*func)(std::string))
{
    func("tiddies");
}

void funkshun3()
{
    std::cout << "funkshun3" << std::endl;
}

void run_funkshun3(std::function<void()>func)
{
    func();
}

void display_frame(struct Frame frame)
{
    std::cout << "Frame Length: " << frame.len << std::endl;
    std::cout << "Frame Data: " << frame.data << std::endl;
}

void run_display(std::function<void(struct Frame)>func, struct Frame frame)
{
    func(frame);
}

int main()
{
    //C-style function pointer type
    typedef void(*function)();
    function func = funkshun;
    func(); 

    //passing function to other functions
    run_funkshun(funkshun);
    run_funkshun2(funkshun2);
    run_funkshun([](){std::cout << "lambda" << std::endl;});

    Frame frame(5, 6666666);
    std::cout << frame.len << " " << frame.data << std::endl;

    //vector of void pointers with no arguments
    std::vector<void(*)()> functions;
    functions.push_back(&funkshun3);

    std::for_each(functions.begin(), functions.end(), [](void(*func)()){ func(); });

    for(auto func: functions)
    {
        func();
    }

    std::cout << "again" << std::endl;

    run_funkshun3(funkshun3);

    run_display(display_frame, frame);
}