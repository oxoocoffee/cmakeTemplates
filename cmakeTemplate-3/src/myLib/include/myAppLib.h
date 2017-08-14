#ifndef MY_APP_LIB
#define MY_APP_LIB

class MyAppLib
{
    public:
                 MyAppLib(void);
        virtual ~MyAppLib(void);

        virtual void  print(void);
};

#define UNUSED_PARAM(x) (void)x;

#endif //MY_APP_LIB
