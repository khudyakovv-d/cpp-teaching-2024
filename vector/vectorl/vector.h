class Vector {

private:
    int * arr_;
    int size_;  

public:
    Vector();
    explicit Vector(int size);
    Vector(const Vector &vec);
    Vector(Vector &&vec) noexcept;
    ~Vector();
    int &operator[](int i);
    int const &operator[](int i) const;
    Vector &operator=(const Vector &vec);
    Vector &operator=(Vector &&vec);
    int size() const;
};

Vector operator+(const Vector &vec1, const Vector &vec2);