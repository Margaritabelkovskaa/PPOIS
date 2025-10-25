#include <gtest/gtest.h>
#include "Cargo.h"

TEST(CargoTest, Getters) {
    Cargo cargo("Electronics", 100.0, 2.0, "General", true, false);
    
    EXPECT_EQ(cargo.getDescription(), "Electronics");
    EXPECT_EQ(cargo.getWeight(), 100.0);
    EXPECT_EQ(cargo.getType(), "General");
    EXPECT_TRUE(cargo.requiresSpecialHandling());
}

TEST(CargoTest, ShippingCost) {
    Cargo normal("Normal", 100.0, 2.0, "General", false, false);
    Cargo fragile("Fragile", 100.0, 2.0, "Fragile", true, false);
    Cargo refrigerated("Refrigerated", 100.0, 2.0, "Food", false, true);
    
    double normalCost = normal.calculateShippingCost(10.0);
    double fragileCost = fragile.calculateShippingCost(10.0);
    double refrigeratedCost = refrigerated.calculateShippingCost(10.0);
    
    EXPECT_EQ(normalCost, 1000.0);
    EXPECT_GT(fragileCost, normalCost);
    EXPECT_GT(refrigeratedCost, normalCost);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
