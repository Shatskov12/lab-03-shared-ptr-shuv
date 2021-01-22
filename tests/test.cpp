// Copyright 2020 Shatskov12 <Qweser2016@mail.ru>
#include <gtest/gtest.h>

#include "smart_pointer.hpp"
TEST(Example, EmptyTest) { EXPECT_TRUE(true); }


TEST(SharedPtr, constructorWithArgument) {
int a = 8;
SharedPtr<int> var(&a);
ASSERT_EQ(*var, a);
}

TEST(SharedPtr, constructorWithLValLink) {
int a = 8;
SharedPtr var(&a);
SharedPtr l(var);
ASSERT_EQ(var.use_count(), 2);
}

TEST(SharedPtr, constructorWithRValLink) {
int a = 9;
SharedPtr var(&a);
SharedPtr r(std::move(var));
ASSERT_EQ(var.use_count(), 2);
}

TEST(SharedPtr, isMoveConstr){
ASSERT_EQ(std::is_move_constructible<SharedPtr<int>>::value,true);
}

TEST(SharedPtr, isMoveAssign){
ASSERT_EQ(std::is_move_assignable<SharedPtr<int>>::value,true);
}

TEST(SharedPtr, operatorRavnoWithLValLink){
int a = 32;
SharedPtr var(&a);
SharedPtr var1 = var;
ASSERT_EQ(var.use_count(),2);
}

TEST(ShredPtr, operatorRavnoWithRValLink){
int a = 12;
SharedPtr var(&a);
SharedPtr var1 = std::move(var);
ASSERT_EQ(var.use_count(),2);
}




TEST(SharedPtr, funcSwap){
int a = 1;
int b = 2;
SharedPtr<int> A(&a);
SharedPtr<int> B(&b);
B.swap(A);
ASSERT_EQ(*B, 1);
}

