class Vector {

private:
    int * arr_;
    int size_;  

public:
    Vector();
    Vector(int size);
    Vector(const Vector &vec);
    ~Vector();
    int &operator[](int i);
    int const &operator[](int i) const;
    Vector &operator=(const Vector &vec);
    int size() const;
};