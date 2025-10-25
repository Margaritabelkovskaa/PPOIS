#include <gtest/gtest.h>
#include "Vehicle.h"

TEST(VehicleTest, Loading) {
    Vehicle truck("C999CC", "MAN", 5000.0);
    
    EXPECT_TRUE(truck.loadCargo(1000.0));
    EXPECT_TRUE(truck.loadCargo(2000.0));
    EXPECT_TRUE(truck.loadCargo(1500.0));
    EXPECT_FALSE(truck.loadCargo(1000.0));
    
    truck.unloadCargo();
    EXPECT_TRUE(truck.loadCargo(5000.0));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
