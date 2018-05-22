// tests.cpp
#include "BinaryTree.h" 
#include <gtest/gtest.h>


class BinaryTreeTest : public ::testing::Test
{
    protected:
        // This is where we reference the method calls we will be using on
        // each object in our test cases
        virtual void SetUp()
        {
            tree0_.addData(10);

            tree1_.addData(10);
            tree1_.addData(5);
            tree1_.addData(12);
        }

    // virtual void TearDown() {}  <-- TearDown stuff would go here

    // This is where we instantiate out test objects
    BinaryTree<int> tree0_;
    BinaryTree<int> tree1_;
};

TEST_F(BinaryTreeTest, AddsNodesCorrectly)
{ 
    ASSERT_TRUE(tree0_.root != NULL); // Is there a value in root?
    ASSERT_TRUE(tree0_.root->left == NULL); // Left node is NULL
    ASSERT_TRUE(tree0_.root->right == NULL); // Right node is NULL
    ASSERT_EQ(10, tree0_.root->data); // Value of root node is equal to 10

    ASSERT_TRUE(tree1_.root != NULL);
    ASSERT_TRUE(tree1_.root->left != NULL);
    ASSERT_TRUE(tree1_.root->right != NULL);
    ASSERT_EQ(10, tree1_.root->data);
    ASSERT_EQ(5, tree1_.root->left->data);
    ASSERT_EQ(12, tree1_.root->right->data);
    ASSERT_TRUE(tree1_.root->left->left == NULL);
    ASSERT_TRUE(tree1_.root->left->right == NULL);
    ASSERT_TRUE(tree1_.root->right->left == NULL);
    ASSERT_TRUE(tree1_.root->right->right == NULL);
}

 
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




/*
TEST(SquareRootTest, PositiveNos)
{ 
    ASSERT_EQ(6, squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
    ASSERT_EQ(25.4, squareRoot(645.16));
    ASSERT_EQ(0, squareRoot(0.0));
}
 
TEST(SquareRootTest, NegativeNos)
{
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}
 
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/