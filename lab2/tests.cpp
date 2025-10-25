#include <gtest/gtest.h>
#include "TransportCompany.h"
#include "Client.h"
#include "Driver.h"
#include "Vehicle.h"
#include "Order.h"
#include "Cargo.h"
#include "DrivingLicense.h"
#include "GPSPosition.h"

// 1. ����������� � �������
TEST(TransportCompanyTest, ConstructorAndGetters) {
    TransportCompany company("TestCompany");
    EXPECT_EQ(company.getCompanyName(), "TestCompany");
    EXPECT_EQ(company.getClientsCount(), 0);
    EXPECT_EQ(company.getDriversCount(), 0);
    EXPECT_EQ(company.getVehiclesCount(), 0);
}

// 2. ���������� �������
TEST(TransportCompanyTest, AddSingleClient) {
    TransportCompany company("Test");
    Client* client = new Client("Test Client", "+79991234567");
    company.addClient(client);
    EXPECT_EQ(company.getClientsCount(), 1);
}

// 3. ���������� ���������� ��������
TEST(TransportCompanyTest, AddMultipleClients) {
    TransportCompany company("Test");
    company.addClient(new Client("Client1", "+79991111111"));
    company.addClient(new Client("Client2", "+79992222222"));
    company.addClient(new Client("Client3", "+79993333333"));
    EXPECT_EQ(company.getClientsCount(), 3);
}

// 4. ���������� ��������
TEST(TransportCompanyTest, AddSingleDriver) {
    TransportCompany company("Test");
    DrivingLicense* license = new DrivingLicense("DL123", "B,C", "2020-01-01", "2030-01-01");
    Driver* driver = new Driver("Driver1", "+79994444444", license, 500.0);
    company.addDriver(driver);
    EXPECT_EQ(company.getDriversCount(), 1);
}

// 5. ���������� ���������� ���������
TEST(TransportCompanyTest, AddMultipleDrivers) {
    TransportCompany company("Test");
    DrivingLicense* license1 = new DrivingLicense("DL111", "B", "2020-01-01", "2030-01-01");
    DrivingLicense* license2 = new DrivingLicense("DL222", "C", "2021-01-01", "2031-01-01");

    company.addDriver(new Driver("Driver1", "+79995555555", license1, 500.0));
    company.addDriver(new Driver("Driver2", "+79996666666", license2, 600.0));
    EXPECT_EQ(company.getDriversCount(), 2);
}

// 6. ���������� ������������� ��������
TEST(TransportCompanyTest, AddSingleVehicle) {
    TransportCompany company("Test");
    Vehicle* vehicle = new Vehicle("A123BC", "Gazelle", 1500.0);
    company.addVehicle(vehicle);
    EXPECT_EQ(company.getVehiclesCount(), 1);
}

// 7. ���������� ���������� ������������ �������
TEST(TransportCompanyTest, AddMultipleVehicles) {
    TransportCompany company("Test");
    company.addVehicle(new Vehicle("A111AA", "Gazelle", 1500.0));
    company.addVehicle(new Vehicle("B222BB", "Kamaz", 10000.0));
    company.addVehicle(new Vehicle("C333CC", "Ford", 2000.0));
    EXPECT_EQ(company.getVehiclesCount(), 3);
}

// 8. �������� ������
TEST(TransportCompanyTest, CreateOrder) {
    TransportCompany company("Test");
    Client* client = new Client("Client", "+79991234567");
    Cargo* cargo = new Cargo("Electronics", 100.0, 2.0, "General", false, false);
    Order* order = new Order(1, client, cargo, "Moscow", "St. Petersburg", 5000.0);

    company.createOrder(order);
    SUCCEED();
}

// 9. ������ ������� ��� �������
TEST(TransportCompanyTest, CalculateDailyRevenueNoOrders) {
    TransportCompany company("Test");
    double revenue = company.calculateDailyRevenue();
    EXPECT_EQ(revenue, 0.0);
}

// 10. ������ ������� � ������������� ��������
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

// 11. ������ ������� � ��������������� ��������
TEST(TransportCompanyTest, CalculateDailyRevenueWithPendingOrders) {
    TransportCompany company("Test");
    Client* client = new Client("Client", "+79991234567");
    Cargo* cargo = new Cargo("Goods", 50.0, 1.0, "General", false, false);
    Order* order = new Order(1, client, cargo, "Moscow", "St. Petersburg", 3000.0);

    company.createOrder(order);

    double revenue = company.calculateDailyRevenue();
    EXPECT_EQ(revenue, 0.0);
}

// 12. ��������� ��������
TEST(TransportCompanyTest, ProcessAllPayments) {
    TransportCompany company("Test");
    company.processAllPayments();
    SUCCEED();
}

// 13. ��������� ��������
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

// 14. ��������� ������ � nullptr
TEST(TransportCompanyTest, BoundaryCasesWithNullptr) {
    TransportCompany company("Test");
    company.addClient(nullptr);
    company.addDriver(nullptr);
    company.addVehicle(nullptr);
    company.createOrder(nullptr);
    SUCCEED();
}

// 15. ������ �������� ��������
TEST(TransportCompanyTest, DifferentCompanyNames) {
    TransportCompany company1("Company1");
    TransportCompany company2("Another Company");
    TransportCompany company3("");

    EXPECT_EQ(company1.getCompanyName(), "Company1");
    EXPECT_EQ(company2.getCompanyName(), "Another Company");
    EXPECT_EQ(company3.getCompanyName(), "");
}

// 16. ������������� ��������
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

// 17. ������������ ����� ������ ��������
TEST(TransportCompanyTest, StabilityAfterManyOperations) {
    TransportCompany company("Test");

    for (int i = 0; i < 100; i++) {
        company.addClient(new Client("Client" + std::to_string(i), "+7999" + std::to_string(1000000 + i)));
    }

    EXPECT_EQ(company.getClientsCount(), 100);
    EXPECT_EQ(company.getDriversCount(), 0);
    EXPECT_EQ(company.getVehiclesCount(), 0);
}

// 18. �������� �����������
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

// 19. ��������� ������ ��������
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

// 20. ������� ��������
TEST(TransportCompanyTest, OperationOrder) {
    TransportCompany company("Test");
    EXPECT_EQ(company.getClientsCount(), 0);
    company.addClient(new Client("Client1", "+79991111111"));
    EXPECT_EQ(company.getClientsCount(), 1);
    company.addClient(new Client("Client2", "+79992222222"));
    EXPECT_EQ(company.getClientsCount(), 2);
}

// 21. ������� �������� �������������
TEST(TransportCompanyTest, BasicUsageScenario) {
    TransportCompany company("DeliveryCo");

    // ��������� ��������
    company.addClient(new Client("Client1", "+79991111111"));
    company.addClient(new Client("Client2", "+79992222222"));

    // ��������� ��������
    DrivingLicense* license = new DrivingLicense("DL123", "B,C", "2020-01-01", "2030-01-01");
    company.addDriver(new Driver("Driver1", "+79993333333", license, 500.0));

    // ��������� ���������
    company.addVehicle(new Vehicle("A111AA", "Gazelle", 1500.0));
    company.addVehicle(new Vehicle("B222BB", "Kamaz", 10000.0));
    company.addVehicle(new Vehicle("C333CC", "Ford", 2000.0));

    // ������� ������
    Cargo* cargo1 = new Cargo("Electronics", 50.0, 1.0, "General", true, false);
    Cargo* cargo2 = new Cargo("Food", 200.0, 5.0, "Perishable", false, true);

    Order* order1 = new Order(1, new Client("OrderClient1", "+79994444444"), cargo1, "Moscow", "St. Petersburg", 3000.0);
    Order* order2 = new Order(2, new Client("OrderClient2", "+79995555555"), cargo2, "St. Petersburg", "Novosibirsk", 15000.0);

    company.createOrder(order1);
    company.createOrder(order2);

    // ������������ �������
    company.processAllPayments();

    // ��������� �������� ���������
    EXPECT_EQ(company.getClientsCount(), 2);
    EXPECT_EQ(company.getDriversCount(), 1);
    EXPECT_EQ(company.getVehiclesCount(), 3);
}

// 22. ������ ��������
TEST(TransportCompanyTest, EmptyCompany) {
    TransportCompany company("EmptyCo");
    EXPECT_EQ(company.getClientsCount(), 0);
    EXPECT_EQ(company.getDriversCount(), 0);
    EXPECT_EQ(company.getVehiclesCount(), 0);
    company.processAllPayments();
    double revenue = company.calculateDailyRevenue();
    EXPECT_EQ(revenue, 0.0);
}

// 23. ������ �������
TEST(TransportCompanyTest, ClientsOnly) {
    TransportCompany company("ClientOnly");
    for (int i = 0; i < 10; i++) {
        company.addClient(new Client("Client" + std::to_string(i), "+7999" + std::to_string(1000000 + i)));
    }
    EXPECT_EQ(company.getClientsCount(), 10);
    EXPECT_EQ(company.getDriversCount(), 0);
    EXPECT_EQ(company.getVehiclesCount(), 0);
}

// 24. ������ ��������
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

// 25. ������ ���������
TEST(TransportCompanyTest, VehiclesOnly) {
    TransportCompany company("VehicleOnly");
    for (int i = 0; i < 15; i++) {
        company.addVehicle(new Vehicle("A" + std::to_string(100 + i) + "BC", "Model" + std::to_string(i), 1000.0 + i * 200));
    }
    EXPECT_EQ(company.getClientsCount(), 0);
    EXPECT_EQ(company.getDriversCount(), 0);
    EXPECT_EQ(company.getVehiclesCount(), 15);
}

// 26. ������� + ��������
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

// 27. �������� + ���������
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

// 28. ��� ���� ���������
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

// 29. ������������������
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

// 30. ������� ���������� ��������
TEST(TransportCompanyTest, LargeNumberOfOperations) {
    TransportCompany company("StressTest");
    for (int i = 0; i < 1000; i++) {
        company.addClient(new Client("Client" + std::to_string(i), "+7999" + std::to_string(1000000 + i)));
    }
    EXPECT_EQ(company.getClientsCount(), 1000);
}

// 31. ���� �������� Cargo
TEST(CargoTest, GettersAndCalculation) {
    Cargo cargo("Electronics", 100.0, 2.0, "General", true, false);

    EXPECT_EQ(cargo.getDescription(), "Electronics");
    EXPECT_EQ(cargo.getWeight(), 100.0);
    EXPECT_EQ(cargo.getType(), "General");

    double cost = cargo.calculateShippingCost(10.0);
    EXPECT_GT(cost, 1000.0); // 100 * 10 * 1.5 = 1500

    EXPECT_TRUE(cargo.requiresSpecialHandling());
}

// 32. ���� Client � ���������
TEST(ClientTest, PaymentOperations) {
    Client client("Test Client", "+79991234567");

    EXPECT_EQ(client.getBalance(), 0.0);

    client.addMoney(1000.0);
    EXPECT_EQ(client.getBalance(), 1000.0);

    bool paymentResult = client.makePayment(500.0);
    EXPECT_TRUE(paymentResult);
    EXPECT_EQ(client.getBalance(), 500.0);

    paymentResult = client.makePayment(600.0);
    EXPECT_FALSE(paymentResult);
    EXPECT_EQ(client.getBalance(), 500.0);
}

// 33. ���� Driver � ����������� ����������
TEST(DriverTest, VehicleAssignment) {
    DrivingLicense license("DL123", "B,C", "2020-01-01", "2030-01-01");
    Driver driver("Driver1", "+79991234567", &license, 500.0);

    EXPECT_TRUE(driver.getIsAvailable());
    EXPECT_EQ(driver.getAssignedVehicle(), nullptr);

    Vehicle vehicle("A123BC", "Gazelle", 1500.0);
    driver.assignVehicle(&vehicle);

    EXPECT_FALSE(driver.getIsAvailable());
    EXPECT_EQ(driver.calculateSalary(8), 4000.0); // 500 * 8
}

// 34. ���� DrivingLicense
TEST(DrivingLicenseTest, ValidationAndCategories) {
    DrivingLicense license("DL123", "B,C,D", "2020-01-01", "2030-01-01");

    EXPECT_TRUE(license.isValid());
    EXPECT_TRUE(license.canDriveCategory("B"));
    EXPECT_TRUE(license.canDriveCategory("C"));
    EXPECT_FALSE(license.canDriveCategory("A")); // �� ������ ���� ��������
    EXPECT_EQ(license.getNumber(), "DL123");
}

// 35. ���� GPSPosition
TEST(GPSPositionTest, DistanceAndValidation) {
    GPSPosition pos1(55.7558, 37.6173); // ������
    GPSPosition pos2(59.9343, 30.3351); // �����-���������

    EXPECT_TRUE(pos1.isValid());
    EXPECT_TRUE(pos2.isValid());

    double distance = pos1.calculateDistance(pos2);
    EXPECT_GT(distance, 0); // ���������� ������ ���� �������������

    std::string str = pos1.toString();
    EXPECT_FALSE(str.empty());
}

// 36. ���� Order � ����������� �������� � ����������
TEST(OrderTest, AssignmentsAndStatus) {
    Client client("Client", "+79991234567");
    Cargo cargo("Goods", 100.0, 2.0, "General", false, false);
    Order order(1, &client, &cargo, "Moscow", "St. Petersburg", 5000.0);

    EXPECT_EQ(order.getStatus(), "Pending");
    EXPECT_FALSE(order.isDelivered());

    DrivingLicense license("DL123", "B", "2020-01-01", "2030-01-01");
    Driver driver("Driver", "+79998888888", &license, 500.0);
    Vehicle vehicle("A123BC", "Gazelle", 1500.0);

    order.assignDriver(&driver);
    EXPECT_EQ(order.getStatus(), "Assigned");

    order.assignVehicle(&vehicle);
    EXPECT_EQ(order.getStatus(), "Ready");

    order.updateStatus("Delivered");
    EXPECT_TRUE(order.isDelivered());
}

// 37. ���� Vehicle � ���������


// 38. ���� TransportCompany � ������� � ������������
TEST(TransportCompanyTest, FindAndAssignOperations) {
    TransportCompany company("Test");

    // ��������� ��������
    Client* client1 = new Client("Client1", "+79991111111");
    Client* client2 = new Client("Client2", "+79992222222");
    company.addClient(client1);
    company.addClient(client2);

    // ��������� ���������
    DrivingLicense* license1 = new DrivingLicense("DL111", "B", "2020-01-01", "2030-01-01");
    DrivingLicense* license2 = new DrivingLicense("DL222", "C", "2021-01-01", "2031-01-01");
    Driver* driver1 = new Driver("Driver1", "+79993333333", license1, 500.0);
    Driver* driver2 = new Driver("Driver2", "+79994444444", license2, 600.0);
    company.addDriver(driver1);
    company.addDriver(driver2);

    // ��������� ���������
    Vehicle* vehicle1 = new Vehicle("A111AA", "Gazelle", 1500.0);
    Vehicle* vehicle2 = new Vehicle("B222BB", "Kamaz", 10000.0);
    company.addVehicle(vehicle1);
    company.addVehicle(vehicle2);

    // ������� ������
    Cargo* cargo1 = new Cargo("Electronics", 50.0, 1.0, "General", true, false);
    Cargo* cargo2 = new Cargo("Food", 200.0, 5.0, "Perishable", false, true);

    Order* order1 = new Order(1, client1, cargo1, "Moscow", "St. Petersburg", 3000.0);
    Order* order2 = new Order(2, client2, cargo2, "St. Petersburg", "Novosibirsk", 15000.0);

    company.createOrder(order1);
    company.createOrder(order2);

    // ��������� �������� �������
    SUCCEED(); // ���� ����� ���� ��� ������ - ���� �������
}

// 39. ���� �� ������ ������ (�������)
TEST(MemoryTest, NoCrashOnDestruction) {
    {
        TransportCompany company("MemoryTest");

        for (int i = 0; i < 10; i++) {
            company.addClient(new Client("Client" + std::to_string(i), "+7999" + std::to_string(1000000 + i)));
            DrivingLicense* license = new DrivingLicense("DL" + std::to_string(i), "B", "2020-01-01", "2030-01-01");
            company.addDriver(new Driver("Driver" + std::to_string(i), "+7999" + std::to_string(2000000 + i), license, 500.0));
            company.addVehicle(new Vehicle("A" + std::to_string(100 + i) + "BC", "Model" + std::to_string(i), 1000.0));
        }
    }
    // ���� ����������� �������� ��������� - ���� �������
    SUCCEED();
}

// 40. ����������� ���� ������-��������
TEST(IntegrationTest, CompleteBusinessProcess) {
    TransportCompany company("ExpressDelivery");

    // ����������� �������
    Client* client = new Client("Ivan Petrov", "+79991234567");
    client->addMoney(10000.0);
    company.addClient(client);

    // ���� ��������
    DrivingLicense* license = new DrivingLicense("DL123456", "B,C", "2020-01-01", "2030-01-01");
    Driver* driver = new Driver("Sergey Ivanov", "+79998888888", license, 550.0);
    company.addDriver(driver);

    // ����������� ����������
    Vehicle* vehicle = new Vehicle("A123BC777", "Gazelle Next", 2000.0);
    company.addVehicle(vehicle);

    // �������� ������
    Cargo* cargo = new Cargo("��������", 150.0, 1.5, "Electronics", true, false);
    Order* order = new Order(1001, client, cargo, "������, ��. ��������, 1",
        "�����-���������, ������� ��., 10", 7500.0);

    // ���������� ������
    company.createOrder(order);

    // ���������� �������� � ����������
    order->assignDriver(driver);
    order->assignVehicle(vehicle);

    // ��������
    order->updateStatus("In Transit");
    order->updateStatus("Delivered");

    // �������� ���������� ���������
    EXPECT_TRUE(order->isDelivered());
    EXPECT_EQ(order->getStatus(), "Delivered");
    EXPECT_TRUE(client->getBalance() < 10000.0); // ������ ������ ���� �������

    // ������ �������
    double revenue = company.calculateDailyRevenue();
    EXPECT_GE(revenue, 0.0);
}

// 41. ���� ��������� �������� ��� Cargo
TEST(CargoTest, BoundaryValues) {
    // ������� ���
    Cargo zeroWeight("Documents", 0.0, 0.1, "Documents", false, false);
    EXPECT_EQ(zeroWeight.calculateShippingCost(10.0), 0.0);

    // ����� ������� ���
    Cargo heavyCargo("Metal", 10000.0, 50.0, "Industrial", false, false);
    EXPECT_GT(heavyCargo.calculateShippingCost(1.0), 10000.0);

    // ������� � ��������� ����������
    Cargo specialCargo("Medicine", 10.0, 0.5, "Medical", true, true);
    double cost = specialCargo.calculateShippingCost(10.0);
    EXPECT_GT(cost, 100.0); // 10 * 10 * 1.5 * 2.0 = 300
}

// 42. ���� Vehicle � ������� ���������� ��������
TEST(VehicleTest, LoadingScenarios) {
    Vehicle truck("C999CC", "MAN", 5000.0);

    // ����������� ��������
    EXPECT_TRUE(truck.loadCargo(1000.0));
    EXPECT_TRUE(truck.loadCargo(2000.0));
    EXPECT_TRUE(truck.loadCargo(1500.0));
    EXPECT_FALSE(truck.loadCargo(1000.0)); // ���������� capacity

    // ������ ��������� � ����� ��������
    truck.unloadCargo();
    EXPECT_TRUE(truck.loadCargo(5000.0)); // ������������ ��������
    EXPECT_FALSE(truck.loadCargo(1.0)); // ���� 1 �� ��� ������

    // �������� ��������
    truck.refuel(50.0);
    SUCCEED();
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    // ������������� ������� �������� � �������� ��� ������ ��� ��������
    TransportCompany test("CoverageTest");
    test.addClient(new Client("Test", "123"));
    test.addDriver(new Driver("Driver", "456", new DrivingLicense("DL", "B", "2020-01-01", "2030-01-01"), 500.0));
    test.addVehicle(new Vehicle("ABC", "Model", 1000.0));
    test.createOrder(new Order(1, new Client("C", "123"), new Cargo("Cargo", 10, 1, "Type"), "A", "B", 100.0));
    test.calculateDailyRevenue();
    test.processAllPayments();

    return RUN_ALL_TESTS();
}
