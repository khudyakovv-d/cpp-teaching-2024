#include <iostream>
#include "vector.h"
#include "gtest/gtest.h"

Vector foo(Vector vec) {
    std::cout << "Size: " << vec.size() << std::endl;
    return vec;
}

TEST(vector_test, vector_creation_on_stack) {
    Vector v = Vector();
    int size = v.size();
    ASSERT_EQ(size, 0);
}

TEST(vector_test, vector_creation_on_heap) {
    Vector *v = new Vector();
    int size = v->size();
    ASSERT_EQ(size, 0);
}

TEST(vector_test, vector_copy_construct) {
    Vector v1 = Vector(10);
    Vector v2 = v1;
    ASSERT_EQ(v1.size(), v2.size());
}

TEST(vector_test, vector_copy_construct_in_func_args) {
    Vector v = Vector(10);
    foo(v);
}

TEST(vector_test, vector_copy_operator) {
    Vector v1 = Vector(10);
    Vector v2 = Vector();
    v2 = v1;
    ASSERT_EQ(v1.size(), v2.size());
}

TEST(vector_test, vector_sum) {
    Vector v1 = Vector(10);
    v1[0] = 1;

    Vector v2 = Vector(10);
    v2[0] = 2;

    Vector v3 = Vector(10);
    v3[0] = 3;

    Vector vsum = v1 + v2 + v3;
    ASSERT_EQ(vsum[0], 6);
}