#include <gtest/gtest.h>
#include "TransportCompany.h"
#include "Client.h"
#include "Driver.h"
#include "Vehicle.h"
#include "Order.h"
#include "Cargo.h"
#include "DrivingLicense.h"

TEST(TransportCompanyTest, ConstructorAndGetters) {
    TransportCompany company("TestCompany");
    EXPECT_EQ(company.getCompanyName(), "TestCompany");
    EXPECT_EQ(company.getClientsCount(), 0);
    EXPECT_EQ(company.getDriversCount(), 0);
    EXPECT_EQ(company.getVehiclesCount(), 0);
}

TEST(TransportCompanyTest, AddSingleClient) {
    TransportCompany company("Test");
    Client* client = new Client("Test Client", "+79991234567");
    company.addClient(client);
    EXPECT_EQ(company.getClientsCount(), 1);
}

TEST(TransportCompanyTest, AddMultipleClients) {
    TransportCompany company("Test");
    company.addClient(new Client("Client1", "+79991111111"));
    company.addClient(new Client("Client2", "+79992222222"));
    company.addClient(new Client("Client3", "+79993333333"));
    EXPECT_EQ(company.getClientsCount(), 3);
}

TEST(TransportCompanyTest, AddSingleDriver) {
    TransportCompany company("Test");
    DrivingLicense* license = new DrivingLicense("DL123", "B,C", "2020-01-01", "2030-01-01");
    Driver* driver = new Driver("Driver1", "+79994444444", license, 500.0);
    company.addDriver(driver);
    EXPECT_EQ(company.getDriversCount(), 1);
}

TEST(TransportCompanyTest, AddMultipleDrivers) {
    TransportCompany company("Test");
    DrivingLicense* license1 = new DrivingLicense("DL111", "B", "2020-01-01", "2030-01-01");
    DrivingLicense* license2 = new DrivingLicense("DL222", "C", "2021-01-01", "2031-01-01");

    company.addDriver(new Driver("Driver1", "+79995555555", license1, 500.0));
    company.addDriver(new Driver("Driver2", "+79996666666", license2, 600.0));
    EXPECT_EQ(company.getDriversCount(), 2);
}

TEST(TransportCompanyTest, AddSingleVehicle) {
    TransportCompany company("Test");
    Vehicle* vehicle = new Vehicle("A123BC", "Gazelle", 1500.0);
    company.addVehicle(vehicle);
    EXPECT_EQ(company.getVehiclesCount(), 1);
}

TEST(TransportCompanyTest, AddMultipleVehicles) {
    TransportCompany company("Test");
    company.addVehicle(new Vehicle("A111AA", "Gazelle", 1500.0));
    company.addVehicle(new Vehicle("B222BB", "Kamaz", 10000.0));
    company.addVehicle(new Vehicle("C333CC", "Ford", 2000.0));
    EXPECT_EQ(company.getVehiclesCount(), 3);
}

TEST(TransportCompanyTest, CreateOrder) {
    TransportCompany company("Test");
    Client* client = new Client("Client", "+79991234567");
    Cargo* cargo = new Cargo("Electronics", 100.0, 2.0, "General", false, false);
    Order* order = new Order(1, client, cargo, "Moscow", "St. Petersburg", 5000.0);

    company.createOrder(order);
    SUCCEED();
}

TEST(TransportCompanyTest, CalculateDailyRevenueNoOrders) {
    TransportCompany company("Test");
    double revenue = company.calculateDailyRevenue();
    EXPECT_EQ(revenue, 0.0);
}

TEST(TransportCompanyTest, CalculateDailyRevenueWithDeliveredOrders) {
    TransportCompany company("Test");
    Client* client = new Client("Client", "+79991234567");
    Cargo* cargo = new Cargo("Goods", 50.0, 1.0, "General", false, false);
    Order* order = new Order(1, client, cargo, "Moscow", "St. Petersburg", 3000.0);

    order->updateStatus("Delivered");
    company.createOrder(order);

    double revenue = company.calculateDailyRevenue();
    EXPECT_EQ(revenue, 3000.0);
}

TEST(TransportCompanyTest, CalculateDailyRevenueWithPendingOrders) {
    TransportCompany company("Test");
    Client* client = new Client("Client", "+79991234567");
    Cargo* cargo = new Cargo("Goods", 50.0, 1.0, "General", false, false);
    Order* order = new Order(1, client, cargo, "Moscow", "St. Petersburg", 3000.0);

    company.createOrder(order);

    double revenue = company.calculateDailyRevenue();
    EXPECT_EQ(revenue, 0.0);
}

TEST(TransportCompanyTest, ProcessAllPayments) {
    TransportCompany company("Test");
    company.processAllPayments();
    SUCCEED();
}

TEST(TransportCompanyTest, MixedOperations) {
    TransportCompany company("Test");

    Client* client = new Client("Client", "+79991234567");
    DrivingLicense* license = new DrivingLicense("DL123", "B", "2020-01-01", "2030-01-01");
    Driver* driver = new Driver("Driver", "+79998888888", license, 500.0);
    Vehicle* vehicle = new Vehicle("A123BC", "Gazelle", 1500.0);
    Cargo* cargo = new Cargo("Goods", 100.0, 2.0, "General", false, false);
    Order* order = new Order(1, client, cargo, "Moscow", "St. Petersburg", 5000.0);

    company.addClient(client);
    company.addDriver(driver);
    company.addVehicle(vehicle);
    company.createOrder(order);

    EXPECT_EQ(company.getClientsCount(), 1);
    EXPECT_EQ(company.getDriversCount(), 1);
    EXPECT_EQ(company.getVehiclesCount(), 1);
}

TEST(TransportCompanyTest, BoundaryCasesWithNullptr) {
    TransportCompany company("Test");
    company.addClient(nullptr);
    company.addDriver(nullptr);
    company.addVehicle(nullptr);
    company.createOrder(nullptr);
    SUCCEED();
}

TEST(TransportCompanyTest, DifferentCompanyNames) {
    TransportCompany company1("Company1");
    TransportCompany company2("Another Company");
    TransportCompany company3("");

    EXPECT_EQ(company1.getCompanyName(), "Company1");
    EXPECT_EQ(company2.getCompanyName(), "Another Company");
    EXPECT_EQ(company3.getCompanyName(), "");
}

TEST(TransportCompanyTest, MultipleOperationsSequence) {
    TransportCompany company("Test");

    for (int i = 0; i < 5; i++) {
        company.addClient(new Client("Client" + std::to_string(i), "+7999" + std::to_string(1000000 + i)));
    }

    for (int i = 0; i < 3; i++) {
        DrivingLicense* license = new DrivingLicense("DL" + std::to_string(i), "B", "2020-01-01", "2030-01-01");
        company.addDriver(new Driver("Driver" + std::to_string(i), "+7999" + std::to_string(2000000 + i), license, 500.0 + i * 100));
    }

    for (int i = 0; i < 4; i++) {
        company.addVehicle(new Vehicle("A" + std::to_string(100 + i) + "BC", "Model" + std::to_string(i), 1000.0 + i * 500));
    }

    EXPECT_EQ(company.getClientsCount(), 5);
    EXPECT_EQ(company.getDriversCount(), 3);
    EXPECT_EQ(company.getVehiclesCount(), 4);
}

TEST(TransportCompanyTest, StabilityAfterManyOperations) {
    TransportCompany company("Test");

    for (int i = 0; i < 100; i++) {
        company.addClient(new Client("Client" + std::to_string(i), "+7999" + std::to_string(1000000 + i)));
    }

    EXPECT_EQ(company.getClientsCount(), 100);
    EXPECT_EQ(company.getDriversCount(), 0);
    EXPECT_EQ(company.getVehiclesCount(), 0);
}

TEST(TransportCompanyTest, InstanceIsolation) {
    TransportCompany company1("First");
    TransportCompany company2("Second");

    company1.addClient(new Client("Client1", "+79991111111"));
    DrivingLicense* license = new DrivingLicense("DL111", "B", "2020-01-01", "2030-01-01");
    company1.addDriver(new Driver("Driver1", "+79992222222", license, 500.0));

    company2.addVehicle(new Vehicle("A111AA", "Gazelle", 1500.0));
    company2.addVehicle(new Vehicle("B222BB", "Kamaz", 10000.0));

    EXPECT_EQ(company1.getClientsCount(), 1);
    EXPECT_EQ(company1.getDriversCount(), 1);
    EXPECT_EQ(company1.getVehiclesCount(), 0);

    EXPECT_EQ(company2.getClientsCount(), 0);
    EXPECT_EQ(company2.getDriversCount(), 0);
    EXPECT_EQ(company2.getVehiclesCount(), 2);
}

TEST(TransportCompanyTest, RepeatedGetterCalls) {
    TransportCompany company("Test");
    company.addClient(new Client("Client", "+79991234567"));
    DrivingLicense* license = new DrivingLicense("DL123", "B", "2020-01-01", "2030-01-01");
    company.addDriver(new Driver("Driver", "+79998888888", license, 500.0));

    EXPECT_EQ(company.getClientsCount(), 1);
    EXPECT_EQ(company.getClientsCount(), 1);
    EXPECT_EQ(company.getClientsCount(), 1);

    EXPECT_EQ(company.getDriversCount(), 1);
    EXPECT_EQ(company.getDriversCount(), 1);
}

TEST(TransportCompanyTest, OperationOrder) {
    TransportCompany company("Test");
    EXPECT_EQ(company.getClientsCount(), 0);
    company.addClient(new Client("Client1", "+79991111111"));
    EXPECT_EQ(company.getClientsCount(), 1);
    company.addClient(new Client("Client2", "+79992222222"));
    EXPECT_EQ(company.getClientsCount(), 2);
}

TEST(TransportCompanyTest, BasicUsageScenario) {
    TransportCompany company("DeliveryCo");

    company.addClient(new Client("Client1", "+79991111111"));
    company.addClient(new Client("Client2", "+79992222222"));

    DrivingLicense* license = new DrivingLicense("DL123", "B,C", "2020-01-01", "2030-01-01");
    company.addDriver(new Driver("Driver1", "+79993333333", license, 500.0));

    company.addVehicle(new Vehicle("A111AA", "Gazelle", 1500.0));
    company.addVehicle(new Vehicle("B222BB", "Kamaz", 10000.0));
    company.addVehicle(new Vehicle("C333CC", "Ford", 2000.0));

    Cargo* cargo1 = new Cargo("Electronics", 50.0, 1.0, "General", true, false);
    Cargo* cargo2 = new Cargo("Food", 200.0, 5.0, "Perishable", false, true);

    Order* order1 = new Order(1, new Client("OrderClient1", "+79994444444"), cargo1, "Moscow", "St. Petersburg", 3000.0);
    Order* order2 = new Order(2, new Client("OrderClient2", "+79995555555"), cargo2, "St. Petersburg", "Novosibirsk", 15000.0);

    company.createOrder(order1);
    company.createOrder(order2);

    company.processAllPayments();

    EXPECT_EQ(company.getClientsCount(), 2);
    EXPECT_EQ(company.getDriversCount(), 1);
    EXPECT_EQ(company.getVehiclesCount(), 3);
}

TEST(TransportCompanyTest, EmptyCompany) {
    TransportCompany company("EmptyCo");
    EXPECT_EQ(company.getClientsCount(), 0);
    EXPECT_EQ(company.getDriversCount(), 0);
    EXPECT_EQ(company.getVehiclesCount(), 0);
    company.processAllPayments();
    double revenue = company.calculateDailyRevenue();
    EXPECT_EQ(revenue, 0.0);
}

TEST(TransportCompanyTest, ClientsOnly) {
    TransportCompany company("ClientOnly");
    for (int i = 0; i < 10; i++) {
        company.addClient(new Client("Client" + std::to_string(i), "+7999" + std::to_string(1000000 + i)));
    }
    EXPECT_EQ(company.getClientsCount(), 10);
    EXPECT_EQ(company.getDriversCount(), 0);
    EXPECT_EQ(company.getVehiclesCount(), 0);
}

TEST(TransportCompanyTest, DriversOnly) {
    TransportCompany company("DriverOnly");
    for (int i = 0; i < 7; i++) {
        DrivingLicense* license = new DrivingLicense("DL" + std::to_string(i), "B", "2020-01-01", "2030-01-01");
        company.addDriver(new Driver("Driver" + std::to_string(i), "+7999" + std::to_string(2000000 + i), license, 500.0 + i * 50));
    }
    EXPECT_EQ(company.getClientsCount(), 0);
    EXPECT_EQ(company.getDriversCount(), 7);
    EXPECT_EQ(company.getVehiclesCount(), 0);
}

TEST(TransportCompanyTest, VehiclesOnly) {
    TransportCompany company("VehicleOnly");
    for (int i = 0; i < 15; i++) {
        company.addVehicle(new Vehicle("A" + std::to_string(100 + i) + "BC", "Model" + std::to_string(i), 1000.0 + i * 200));
    }
    EXPECT_EQ(company.getClientsCount(), 0);
    EXPECT_EQ(company.getDriversCount(), 0);
    EXPECT_EQ(company.getVehiclesCount(), 15);
}

TEST(TransportCompanyTest, ClientsAndDrivers) {
    TransportCompany company("Test");
    company.addClient(new Client("Client1", "+79991111111"));
    company.addClient(new Client("Client2", "+79992222222"));
    company.addClient(new Client("Client3", "+79993333333"));

    DrivingLicense* license1 = new DrivingLicense("DL111", "B", "2020-01-01", "2030-01-01");
    DrivingLicense* license2 = new DrivingLicense("DL222", "C", "2021-01-01", "2031-01-01");
    company.addDriver(new Driver("Driver1", "+79994444444", license1, 500.0));
    company.addDriver(new Driver("Driver2", "+79995555555", license2, 600.0));

    EXPECT_EQ(company.getClientsCount(), 3);
    EXPECT_EQ(company.getDriversCount(), 2);
    EXPECT_EQ(company.getVehiclesCount(), 0);
}

TEST(TransportCompanyTest, DriversAndVehicles) {
    TransportCompany company("Test");
    DrivingLicense* license = new DrivingLicense("DL123", "B,C", "2020-01-01", "2030-01-01");
    company.addDriver(new Driver("Driver1", "+79996666666", license, 500.0));

    company.addVehicle(new Vehicle("A111AA", "Gazelle", 1500.0));
    company.addVehicle(new Vehicle("B222BB", "Kamaz", 10000.0));
    company.addVehicle(new Vehicle("C333CC", "Ford", 2000.0));
    company.addVehicle(new Vehicle("D444DD", "MAN", 15000.0));

    EXPECT_EQ(company.getClientsCount(), 0);
    EXPECT_EQ(company.getDriversCount(), 1);
    EXPECT_EQ(company.getVehiclesCount(), 4);
}

TEST(TransportCompanyTest, AllEntityTypes) {
    TransportCompany company("Test");
    company.addClient(new Client("Client", "+79991234567"));
    DrivingLicense* license = new DrivingLicense("DL123", "B", "2020-01-01", "2030-01-01");
    company.addDriver(new Driver("Driver", "+79998888888", license, 500.0));
    company.addVehicle(new Vehicle("A123BC", "Gazelle", 1500.0));
    Cargo* cargo = new Cargo("Goods", 100.0, 2.0, "General", false, false);
    Order* order = new Order(1, new Client("OrderClient", "+79999999999"), cargo, "Moscow", "St. Petersburg", 5000.0);
    company.createOrder(order);

    EXPECT_EQ(company.getClientsCount(), 1);
    EXPECT_EQ(company.getDriversCount(), 1);
    EXPECT_EQ(company.getVehiclesCount(), 1);
}

TEST(TransportCompanyTest, PerformanceWithManyEntities) {
    TransportCompany company("Test");
    const int COUNT = 50;

    for (int i = 0; i < COUNT; i++) {
        company.addClient(new Client("Client" + std::to_string(i), "+7999" + std::to_string(1000000 + i)));
        DrivingLicense* license = new DrivingLicense("DL" + std::to_string(i), "B", "2020-01-01", "2030-01-01");
        company.addDriver(new Driver("Driver" + std::to_string(i), "+7999" + std::to_string(2000000 + i), license, 500.0));
        company.addVehicle(new Vehicle("A" + std::to_string(100 + i) + "BC", "Model" + std::to_string(i), 1000.0 + i * 100));
    }

    EXPECT_EQ(company.getClientsCount(), COUNT);
    EXPECT_EQ(company.getDriversCount(), COUNT);
    EXPECT_EQ(company.getVehiclesCount(), COUNT);
}

TEST(TransportCompanyTest, LargeNumberOfOperations) {
    TransportCompany company("StressTest");
    for (int i = 0; i < 1000; i++) {
        company.addClient(new Client("Client" + std::to_string(i), "+7999" + std::to_string(1000000 + i)));
    }
    EXPECT_EQ(company.getClientsCount(), 1000);
}

TEST(TransportCompanyTest, FindAndAssignOperations) {
    TransportCompany company("Test");

    Client* client1 = new Client("Client1", "+79991111111");
    Client* client2 = new Client("Client2", "+79992222222");
    company.addClient(client1);
    company.addClient(client2);

    DrivingLicense* license1 = new DrivingLicense("DL111", "B", "2020-01-01", "2030-01-01");
    DrivingLicense* license2 = new DrivingLicense("DL222", "C", "2021-01-01", "2031-01-01");
    Driver* driver1 = new Driver("Driver1", "+79993333333", license1, 500.0);
    Driver* driver2 = new Driver("Driver2", "+79994444444", license2, 600.0);
    company.addDriver(driver1);
    company.addDriver(driver2);

    Vehicle* vehicle1 = new Vehicle("A111AA", "Gazelle", 1500.0);
    Vehicle* vehicle2 = new Vehicle("B222BB", "Kamaz", 10000.0);
    company.addVehicle(vehicle1);
    company.addVehicle(vehicle2);

    Cargo* cargo1 = new Cargo("Electronics", 50.0, 1.0, "General", true, false);
    Cargo* cargo2 = new Cargo("Food", 200.0, 5.0, "Perishable", false, true);

    Order* order1 = new Order(1, client1, cargo1, "Moscow", "St. Petersburg", 3000.0);
    Order* order2 = new Order(2, client2, cargo2, "St. Petersburg", "Novosibirsk", 15000.0);

    company.createOrder(order1);
    company.createOrder(order2);

    SUCCEED();
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
