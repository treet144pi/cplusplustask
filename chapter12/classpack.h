extern const int sizelift;
class Complex
{
    private:
        int real;
        int imagine;
    public:
        Complex ();
        Complex (int,int);
        void display();
        friend Complex operator+ (Complex&,Complex&);
};
extern int tick(int,int,int);

