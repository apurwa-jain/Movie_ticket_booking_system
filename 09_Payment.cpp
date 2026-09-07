class Payment {
public:
    // Pure virtual function making this an abstract class
    virtual bool pay(double amount) = 0;
    virtual ~Payment() {}
};
