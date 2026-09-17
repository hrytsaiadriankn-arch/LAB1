class Pay
{
private:
    double first;
    int second;

public:
    double GetFirst() const { return first; }
    int GetSecond() const { return second; }

    bool SetFirst(double value);
    bool SetSecond(int value);

    bool Init(double salary, int workedDays);

    void Read();
    void Display() const;

    double Summa(int workingDaysInMonth) const;
};