#ifndef SIM_H
#define SIM_H
using namespace
template<class T>
class sim
{
    T x;
    T y;
    public:
        sim(T sim1=0,T sim2=0)
        {
           T x=sim1;
           T y=sim2;
        }
        virtual ~sim();
};

#endif // SIM_H
