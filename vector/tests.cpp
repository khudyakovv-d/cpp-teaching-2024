#include <iostream>
#include "vector.h"
#include "gtest/gtest.h"

TEST(vector_test, vector_creation) {
    Vector *v = new Vector();
    int size = v->size();
    ASSERT_EQ(size, 0);
}

TEST(vector_test, vector_copy_construct) {
    Vector v1 = Vector(10);
    Vector v2 = v1;
    ASSERT_EQ(v1.size(), v2.size());
}

TEST(vector_test, vector_copy_operator) {
    Vector v1 = Vector(10);
    Vector v2 = Vector();
    v2 = v1;
    ASSERT_EQ(v1.size(), v2.size());
}