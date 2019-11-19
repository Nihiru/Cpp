#ifndef _IntCell_H_
#define _IntCell_H_
class IntCell{
    public:
        explicit IntCell(int);
        int read() const;
        void write(int x);
    private:
        int storedValue;
};
#endif
