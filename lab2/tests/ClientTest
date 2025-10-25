#include <gtest/gtest.h>
#include "Client.h"

TEST(ClientTest, PaymentOperations) {
    Client client("Test Client", "+79991234567");
    client.addMoney(1000.0);
    EXPECT_EQ(client.getBalance(), 1000.0);
    
    EXPECT_TRUE(client.makePayment(500.0));
    EXPECT_FALSE(client.makePayment(600.0));
    EXPECT_EQ(client.getBalance(), 500.0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
