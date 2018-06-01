#include <iostream>
#include "Ship.hpp"
#include <gtest/gtest.h>

namespace
{

TEST(ShipTest, GetFunctionTests)
{
    Ship ship1("ship1", 4);
    EXPECT_EQ("ship1", ship1.getName());
    EXPECT_EQ(4, ship1.getLength());
    EXPECT_EQ(0, ship1.getDamage());
}

} //namespace

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
