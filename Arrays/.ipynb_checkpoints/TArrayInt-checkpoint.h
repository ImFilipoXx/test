#ifndef TARRAYINT_H
#define TARRAYINT_H

#define Max_Length 30

class TArrayInt {
private:
    int Flength;
    int FArray[Max_Length];

public:
    TArrayInt(int length);
    TArrayInt();
    ~TArrayInt();

    void SetArray(int Array[]);
    TArrayInt GetArray() const;
    void SetElement(int index, int value);
    int GetElement(int index) const;
    int GetLength() const;
    void SetLength(int length);
    int Sum() const;
    float Average() const;
    int CountZeros() const;
    bool IsEmpty() const;
    bool IsFull() const;
    bool InsertLast(int value);
};

#endif
