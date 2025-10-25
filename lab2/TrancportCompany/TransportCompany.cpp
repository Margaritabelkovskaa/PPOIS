#include "TransportCompany.h"
#include "Client.h"
#include "Driver.h"
#include "Vehicle.h"
#include "Order.h"

TransportCompany::TransportCompany(const std::string& name)
    : companyName(name), companyBalance(0) {
}

TransportCompany::~TransportCompany() {
    for (auto client : clients) delete client;
    for (auto driver : drivers) delete driver;
    for (auto vehicle : vehicles) delete vehicle;
    for (auto order : orders) delete order;
}

void TransportCompany::addClient(Client* client) {
    clients.push_back(client);
}

void TransportCompany::addDriver(Driver* driver) {
    drivers.push_back(driver);
}

void TransportCompany::addVehicle(Vehicle* vehicle) {
    vehicles.push_back(vehicle);
}

void TransportCompany::createOrder(Order* order) {
    orders.push_back(order);
}

double TransportCompany::calculateDailyRevenue() const {
    double total = 0;
    for (auto order : orders) {
        if (order->isDelivered()) {
            total += order->getCost();
        }
    }
    return total;
}

void TransportCompany::processAllPayments() {
    // Логика обработки всех платежей
}//#include "TransportCompany.h"
//#include <iostream>
//#include <memory>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//#include <chrono>
//#include <iomanip>
//#include <sstream>
//
//using namespace std;
//
//// ==================== ENTITY IMPLEMENTATIONS ====================
//
//// GeoCoordinates
//GeoCoordinates::GeoCoordinates(double lat, double lon, double alt)
//    : latitude(lat), longitude(lon), altitude(alt) {
//}
//
//// Address
//Address::Address(const string& id, const string& cntry, const string& cty,
//    const string& str, const string& bld, const string& zip,
//    shared_ptr<GeoCoordinates> coords)
//    : address_id(id), country(cntry), city(cty), street(str), building(bld),
//    zip_code(zip), coordinates(coords) {
//}
//
//// User
//User::User(const string& id, const string& nm, const string& em,
//    const string& ph, const string& reg_date, const string& st,
//    shared_ptr<Address> addr)
//    : user_id(id), name(nm), email(em), phone(ph), registration_date(reg_date),
//    status(st), address(addr) {
//}
//
//// Customer
//Customer::Customer(const string& id, const string& company, const string& tax,
//    double credit_lim, int pay_terms, shared_ptr<User> usr)
//    : customer_id(id), company_name(company), tax_id(tax), credit_limit(credit_lim),
//    payment_terms(pay_terms), user(usr) {
//}
//
//// Employee
//Employee::Employee(const string& id, const string& dept, const string& pos,
//    double sal, const string& hire_d, shared_ptr<User> usr)
//    : employee_id(id), department(dept), position(pos), salary(sal),
//    hire_date(hire_d), user(usr) {
//}
//
//// Dimensions
//Dimensions::Dimensions(double len, double wid, double hgt)
//    : length(len), width(wid), height(hgt) {
//}
//
//// Package
//Package::Package(const string& id, double wgt, shared_ptr<Dimensions> dims,
//    double decl_val, const string& pkg_type, const string& contents,
//    shared_ptr<Shipment> ship)
//    : package_id(id), weight(wgt), dimensions(dims), declared_value(decl_val),
//    package_type(pkg_type), contents_description(contents), shipment(ship) {
//}
//
//// Shipment
//Shipment::Shipment(const string& id, const string& tracking, const string& created,
//    const string& deadline, const string& st, shared_ptr<Customer> cust)
//    : shipment_id(id), tracking_number(tracking), created_date(created),
//    delivery_deadline(deadline), status(st), customer(cust) {
//}
//
//// RouteCheckpoint
//RouteCheckpoint::RouteCheckpoint(const string& id, int seq_num, shared_ptr<Address> addr,
//    const string& est_arrival, const string& act_arrival,
//    shared_ptr<Route> rt)
//    : checkpoint_id(id), sequence_number(seq_num), address(addr),
//    estimated_arrival(est_arrival), actual_arrival(act_arrival), route(rt) {
//}
//
//// Route
//Route::Route(const string& id, shared_ptr<Address> start, shared_ptr<Address> end,
//    double distance, double duration)
//    : route_id(id), start_point(start), end_point(end), total_distance(distance),
//    estimated_duration(duration) {
//}
//
//// Vehicle
//Vehicle::Vehicle(const string& id, const string& license, const string& type,
//    double cap, shared_ptr<Address> location, const string& st)
//    : vehicle_id(id), license_plate(license), vehicle_type(type), capacity(cap),
//    current_location(location), status(st) {
//}
//
//// Driver
//Driver::Driver(const string& id, const string& license, const string& expiry,
//    shared_ptr<Employee> emp)
//    : Employee(*emp), driver_id(id), license_number(license), license_expiry(expiry), employee(emp) {
//}
//
//// Delivery
//Delivery::Delivery(const string& id, const string& start, const string& end,
//    const string& st, shared_ptr<Driver> drv, shared_ptr<Vehicle> vhc,
//    shared_ptr<Route> rt)
//    : delivery_id(id), start_time(start), end_time(end), status(st), driver(drv),
//    vehicle(vhc), route(rt) {
//}
//
//// BankAccount
//BankAccount::BankAccount(const string& id, const string& acc_num, const string& bank,
//    double bal, const string& curr, shared_ptr<Customer> own)
//    : account_id(id), account_number(acc_num), bank_name(bank), balance(bal),
//    currency(curr), owner(own) {
//}
//
//// Transaction
//Transaction::Transaction(const string& id, double amt, const string& curr,
//    const string& trans_date, const string& desc,
//    shared_ptr<BankAccount> src, shared_ptr<BankAccount> dest)
//    : transaction_id(id), amount(amt), currency(curr), transaction_date(trans_date),
//    description(desc), source_account(src), destination_account(dest) {
//}
//
//// Invoice
//Invoice::Invoice(const string& id, const string& inv_num, const string& issue,
//    const string& due, double total, const string& st,
//    shared_ptr<Customer> cust, shared_ptr<Shipment> ship)
//    : invoice_id(id), invoice_number(inv_num), issue_date(issue), due_date(due),
//    total_amount(total), status(st), customer(cust), shipment(ship) {
//}
//
//// Permission
//Permission::Permission(const string& id, const string& name, const string& desc)
//    : permission_id(id), permission_name(name), description(desc) {
//}
//
//// UserRole
//UserRole::UserRole(const string& id, const string& name)
//    : role_id(id), role_name(name) {
//}
//
//// Shelf
//Shelf::Shelf(const string& id, int lvl, double max_wgt, shared_ptr<StorageZone> zone)
//    : shelf_id(id), level(lvl), max_weight(max_wgt), storage_zone(zone) {
//}
//
//// StorageZone
//StorageZone::StorageZone(const string& id, const string& type, const string& temp,
//    double cap, shared_ptr<Warehouse> wh)
//    : zone_id(id), zone_type(type), temperature_range(temp), capacity(cap), warehouse(wh) {
//}
//
//// Warehouse
//Warehouse::Warehouse(const string& id, const string& nm, shared_ptr<Address> addr,
//    double total_cap, double current_occ)
//    : warehouse_id(id), name(nm), address(addr), total_capacity(total_cap),
//    current_occupancy(current_occ) {
//}
//
//// InventoryItem
//InventoryItem::InventoryItem(const string& id, const string& sk, const string& nm,
//    int qty, double price, const string& expiry, shared_ptr<Shelf> sh)
//    : item_id(id), sku(sk), name(nm), quantity(qty), unit_price(price),
//    expiry_date(expiry), shelf(sh) {
//}
//
//// StockMovement
//StockMovement::StockMovement(const string& id, const string& type, int qty,
//    const string& mov_date, shared_ptr<InventoryItem> itm,
//    shared_ptr<Shelf> src, shared_ptr<Shelf> dest)
//    : movement_id(id), movement_type(type), quantity(qty), movement_date(mov_date),
//    item(itm), source_location(src), destination_location(dest) {
//}
//
//// Contract
//Contract::Contract(const string& id, const string& start, const string& end,
//    const string& trm, const string& st, shared_ptr<Customer> cust)
//    : contract_id(id), start_date(start), end_date(end), terms(trm), status(st), customer(cust) {
//}
//
//// Tariff
//Tariff::Tariff(const string& id, const string& service, double rate_kg,
//    double rate_km, double min_charge, shared_ptr<Contract> cntr)
//    : tariff_id(id), service_type(service), rate_per_kg(rate_kg), rate_per_km(rate_km),
//    minimum_charge(min_charge), contract(cntr) {
//}
//
//// Report
//Report::Report(const string& id, const string& type, const string& gen_date,
//    const string& dt, shared_ptr<Employee> gen_by)
//    : report_id(id), report_type(type), generated_date(gen_date), data(dt), generated_by(gen_by) {
//}
//
//// MaintenanceRecord
//MaintenanceRecord::MaintenanceRecord(const string& id, const string& date,
//    const string& type, double cst, const string& desc,
//    shared_ptr<Vehicle> vhc)
//    : record_id(id), maintenance_date(date), maintenance_type(type), cost(cst),
//    description(desc), vehicle(vhc) {
//}
//
//// ==================== SERVICE IMPLEMENTATIONS ====================
//
//// FinancialService
//shared_ptr<Transaction> FinancialService::transferMoneyBetweenAccounts(
//    shared_ptr<BankAccount> sourceAccount,
//    shared_ptr<BankAccount> destinationAccount,
//    double amount) {
//
//    if (sourceAccount->balance < amount) {
//        throw InsufficientFundsException();
//    }
//
//    sourceAccount->balance -= amount;
//    destinationAccount->balance += amount;
//
//    // Safe current time retrieval
//    time_t now = time(nullptr);
//    tm now_tm;
//
//#ifdef _WIN32
//    localtime_s(&now_tm, &now);
//#else
//    localtime_r(&now, &now_tm);
//#endif
//
//    char buffer[20];
//    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &now_tm);
//
//    // Generate more unique transaction ID
//    string transactionId = "trans_" + to_string(rand()) + "_" +
//        to_string(time(nullptr));
//
//    auto transaction = make_shared<Transaction>(
//        transactionId,
//        amount,
//        sourceAccount->currency,
//        string(buffer),
//        "Transfer to " + destinationAccount->account_number,
//        sourceAccount,
//        destinationAccount
//    );
//
//    cout << "Transfer completed: " << amount << " " << sourceAccount->currency
//        << " from " << sourceAccount->account_number
//        << " to " << destinationAccount->account_number << endl;
//
//    return transaction;
//}
//
//bool FinancialService::processInvoicePayment(shared_ptr<Invoice> invoice,
//    const string& paymentMethod) {
//
//    if (invoice->status == "PAID") {
//        cout << "Invoice already paid" << endl;
//        return false;
//    }
//
//    invoice->status = "PAID";
//
//    // Add payment date
//    time_t now = time(nullptr);
//    tm now_tm;
//
//#ifdef _WIN32
//    localtime_s(&now_tm, &now);
//#else
//    localtime_r(&now, &now_tm);
//#endif
//
//    char buffer[20];
//    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &now_tm);
//
//    cout << "Invoice " << invoice->invoice_number << " successfully paid via "
//        << paymentMethod << " (" << buffer << ")" << endl;
//    return true;
//}
//
//double FinancialService::calculateShipmentCost(shared_ptr<Shipment> shipment,
//    shared_ptr<Tariff> tariff) {
//
//    if (!shipment) {
//        throw invalid_argument("Shipment is null");
//    }
//
//    if (!tariff) {
//        throw invalid_argument("Tariff is null");
//    }
//
//    double totalWeight = 0.0;
//    for (const auto& package : shipment->packages) {
//        if (package) {
//            totalWeight += package->weight;
//        }
//    }
//
//    double totalDistance = 0.0;
//    if (shipment->route) {
//        totalDistance = shipment->route->total_distance;
//    }
//
//    double cost = (totalWeight * tariff->rate_per_kg +
//        totalDistance * tariff->rate_per_km);
//
//    double finalCost = max(cost, tariff->minimum_charge);
//
//    cout << "Delivery cost calculation: " << finalCost << " RUB" << endl;
//    cout << "   Weight: " << totalWeight << " kg, Distance: " << totalDistance
//        << " km" << endl;
//
//    return finalCost;
//}
//
//// SecurityService
//shared_ptr<User> SecurityService::authenticateUser(const string& username,
//    const string& password) {
//
//    if (username.empty() || password.empty()) {
//        throw AuthenticationException();
//    }
//
//    if (username != "admin" && password != "password123") {
//        throw AuthenticationException();
//    }
//
//    auto address = make_shared<Address>("addr1", "Russia", "Moscow",
//        "Tverskaya", "1", "125009", nullptr);
//
//    auto user = make_shared<User>("user1", "Administrator", "admin@company.com",
//        "+79991234567", "2024-01-01", "ACTIVE", address);
//
//    cout << "User " << username << " successfully authenticated" << endl;
//
//    return user;
//}
//
//bool SecurityService::checkPasswordStrength(const string& password) {
//    if (password.length() < 8) return false;
//
//    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
//
//    for (char c : password) {
//        if (isupper(c)) hasUpper = true;
//        if (islower(c)) hasLower = true;
//        if (isdigit(c)) hasDigit = true;
//        if (string("!@#$%^&*").find(c) != string::npos) hasSpecial = true;
//    }
//
//    bool isStrong = hasUpper && hasLower && hasDigit && hasSpecial;
//
//    cout << "Password strength check: " << (isStrong ? "STRONG" : "WEAK") << endl;
//
//    return isStrong;
//}
//
//bool SecurityService::authorizeAction(shared_ptr<User> user,
//    const string& action,
//    const string& resource) {
//
//    if (user->name.find("Admin") != string::npos) {
//        cout << "Authorization granted for " << action << ":" << resource << endl;
//        return true;
//    }
//
//    throw AuthorizationException();
//}
//
//// LogisticsService
//shared_ptr<Shipment> LogisticsService::createShipment(
//    shared_ptr<Customer> customer,
//    const vector<shared_ptr<Package>>& packages,
//    shared_ptr<Address> deliveryAddress) {
//
//    auto shipment = make_shared<Shipment>(
//        "ship_" + to_string(rand()),
//        generateTrackingNumber(),
//        "2024-01-15 10:00:00",
//        "2024-01-20 18:00:00",
//        "CREATED",
//        customer
//    );
//
//    for (auto& package : packages) {
//        package->shipment = shipment;
//        shipment->packages.push_back(package);
//    }
//
//    cout << "New shipment created. Tracking number: "
//        << shipment->tracking_number << endl;
//
//    return shipment;
//}
//
//shared_ptr<Route> LogisticsService::optimizeRoute(shared_ptr<Route> route) {
//
//    if (route->checkpoints.empty()) {
//        throw RouteOptimizationException();
//    }
//
//    sort(route->checkpoints.begin(), route->checkpoints.end(),
//        [](const auto& a, const auto& b) {
//            return a->sequence_number < b->sequence_number;
//        });
//
//    cout << "Route optimized. Checkpoints: "
//        << route->checkpoints.size() << endl;
//
//    return route;
//}
//
//bool LogisticsService::assignVehicleToDelivery(shared_ptr<Delivery> delivery,
//    const vector<shared_ptr<Vehicle>>& availableVehicles) {
//
//    double totalWeight = 150.0; // Simplified implementation
//
//    vector<shared_ptr<Vehicle>> suitableVehicles;
//    for (const auto& vehicle : availableVehicles) {
//        if (vehicle->status == "AVAILABLE" && vehicle->capacity >= totalWeight) {
//            suitableVehicles.push_back(vehicle);
//        }
//    }
//
//    if (suitableVehicles.empty()) {
//        throw VehicleNotAvailableException();
//    }
//
//    delivery->vehicle = suitableVehicles[0];
//    suitableVehicles[0]->status = "ASSIGNED";
//
//    cout << "Vehicle " << suitableVehicles[0]->license_plate
//        << " assigned to delivery" << endl;
//
//    return true;
//}
//
//string LogisticsService::generateTrackingNumber() {
//    stringstream ss;
//    ss << "TRK" << setw(10) << setfill('0') << rand();
//    return ss.str();
//}
//
//// WarehouseService
//vector<shared_ptr<InventoryItem>> WarehouseService::receiveGoods(
//    shared_ptr<Shipment> shipment,
//    shared_ptr<Warehouse> warehouse,
//    shared_ptr<StorageZone> targetZone) {
//
//    double shipmentVolume = 100.0; // Simplified implementation
//
//    if (warehouse->current_occupancy + shipmentVolume > warehouse->total_capacity) {
//        throw CapacityExceededException();
//    }
//
//    vector<shared_ptr<InventoryItem>> inventoryItems;
//
//    for (const auto& package : shipment->packages) {
//        auto item = make_shared<InventoryItem>(
//            "item_" + to_string(rand()),
//            "SKU_" + to_string(rand()),
//            package->contents_description,
//            1,
//            package->declared_value,
//            "2024-12-31",
//            nullptr
//        );
//
//        inventoryItems.push_back(item);
//    }
//
//    warehouse->current_occupancy += shipmentVolume;
//
//    cout << "Goods received at warehouse. Occupancy level: "
//        << warehouse->current_occupancy << "/" << warehouse->total_capacity << endl;
//
//    return inventoryItems;
//}
//
//shared_ptr<InventoryItem> WarehouseService::findInventoryItem(
//    const string& sku,
//    shared_ptr<Warehouse> warehouse) {
//
//    // Simplified search
//    auto item = make_shared<InventoryItem>("item1", sku, "Demo product", 100, 1500.0, "2024-12-31", nullptr);
//
//    cout << "Item found: " << item->name << " (SKU: " << sku << ")" << endl;
//    return item;
//}
//
//shared_ptr<StockMovement> WarehouseService::moveStock(
//    shared_ptr<InventoryItem> item,
//    int quantity,
//    shared_ptr<Shelf> fromShelf,
//    shared_ptr<Shelf> toShelf) {
//
//    if (item->quantity < quantity) {
//        throw WarehouseException("Insufficient stock for movement");
//    }
//
//    auto movement = make_shared<StockMovement>(
//        "mov_" + to_string(rand()),
//        "TRANSFER",
//        quantity,
//        "2024-01-15 14:30:00",
//        item,
//        fromShelf,
//        toShelf
//    );
//
//    item->quantity -= quantity;
//
//    cout << "Stock movement: " << quantity << " units of "
//        << item->name << endl;
//
//    return movement;
//}
//
//// AnalyticsService
//shared_ptr<Report> AnalyticsService::generateFinancialReport(
//    const string& startDate,
//    const string& endDate,
//    shared_ptr<Employee> employee) {
//
//    stringstream reportData;
//    reportData << "Period: " << startDate << " - " << endDate << "\n"
//        << "Total revenue: 1,500,000 RUB\n"
//        << "Total expenses: 950,000 RUB\n"
//        << "Profit: 550,000 RUB";
//
//    auto report = make_shared<Report>(
//        "rep_" + to_string(rand()),
//        "FINANCIAL",
//        "2024-01-15 16:00:00",
//        reportData.str(),
//        employee
//    );
//
//    cout << "Financial report generated for period "
//        << startDate << " - " << endDate << endl;
//
//    return report;
//}
//
//string AnalyticsService::calculateDeliveryPerformance(
//    shared_ptr<Driver> driver,
//    const string& startDate,
//    const string& endDate) {
//
//    stringstream result;
//    result << "Driver: " << driver->employee->user->name << "\n"
//        << "Total deliveries: 25\n"
//        << "Completed: 23\n"
//        << "Completion rate: 92%";
//
//    cout << "Driver performance analytics generated" << endl;
//
//    return result.str();
//}
//
//// VehicleService
//shared_ptr<MaintenanceRecord> VehicleService::scheduleMaintenance(
//    shared_ptr<Vehicle> vehicle,
//    const string& maintenanceType,
//    const string& scheduledDate) {
//
//    auto record = make_shared<MaintenanceRecord>(
//        "maint_" + to_string(rand()),
//        scheduledDate,
//        maintenanceType,
//        0.0,
//        "Scheduled maintenance",
//        vehicle
//    );
//
//    vehicle->maintenance_records.push_back(record);
//    vehicle->status = "MAINTENANCE_SCHEDULED";
//
//    cout << "Maintenance scheduled for vehicle "
//        << vehicle->license_plate << " on " << scheduledDate << endl;
//
//    return record;
//}
//
//// ==================== MAIN SYSTEM IMPLEMENTATION ====================
//
//TransportCompany::TransportCompany() {
//    srand(time(nullptr));
//}
//
//void TransportCompany::initializeSampleData() {
//    cout << "Initializing demo data..." << endl;
//
//    auto coordinates = make_shared<GeoCoordinates>(55.7558, 37.6173, 150.0);
//    auto address = make_shared<Address>("addr1", "Russia", "Moscow",
//        "Tverskaya", "1", "125009", coordinates);
//
//    auto user = make_shared<User>("user1", "Ivan Ivanov", "ivan@example.com",
//        "+79991234567", "2023-01-15", "ACTIVE", address);
//
//    auto adminUser = make_shared<User>("user2", "System Administrator",
//        "admin@company.com", "+79997654321",
//        "2023-01-10", "ACTIVE", address);
//
//    auto customer = make_shared<Customer>("cust1", "Romashka LLC", "1234567890",
//        100000.0, 30, user);
//    customers.push_back(customer);
//
//    auto employee = make_shared<Employee>("emp1", "Logistics", "Manager",
//        50000.0, "2023-02-01", adminUser);
//    employees.push_back(employee);
//
//    auto vehicle = make_shared<Vehicle>("veh1", "A123BC777", "Truck",
//        2000.0, address, "AVAILABLE");
//    vehicles.push_back(vehicle);
//
//    auto warehouse = make_shared<Warehouse>("wh1", "Main Warehouse",
//        address, 5000.0, 1500.0);
//    warehouses.push_back(warehouse);
//
//    cout << "Demo data initialized" << endl;
//}
//
//void TransportCompany::demonstrateFinancialOperations() {
//    cout << "\nFINANCIAL OPERATIONS DEMONSTRATION" << endl;
//    cout << "=================================" << endl;
//
//    if (customers.empty()) return;
//
//    auto customer = customers[0];
//
//    auto account1 = make_shared<BankAccount>("acc1", "40702810123456789000",
//        "Sberbank", 50000.0, "RUB", customer);
//
//    auto account2 = make_shared<BankAccount>("acc2", "40702810987654321000",
//        "VTB", 30000.0, "RUB", customer);
//
//    try {
//        auto transaction = financialService.transferMoneyBetweenAccounts(account1, account2, 10000.0);
//
//        auto invoice = make_shared<Invoice>("inv1", "INV-2024-001", "2024-01-15",
//            "2024-02-15", 25000.0, "PENDING",
//            customer, nullptr);
//
//        financialService.processInvoicePayment(invoice, "BANK_TRANSFER");
//
//    }
//    catch (const FinancialException& e) {
//        cout << "Financial error: " << e.what() << endl;
//    }
//}
//
//void TransportCompany::demonstrateLogisticsOperations() {
//    cout << "\nLOGISTICS OPERATIONS DEMONSTRATION" << endl;
//    cout << "================================" << endl;
//
//    if (customers.empty()) return;
//
//    auto customer = customers[0];
//    auto address = customer->user->address;
//
//    try {
//        auto dimensions = make_shared<Dimensions>(30, 20, 15);
//        auto package1 = make_shared<Package>("pkg1", 5.0, dimensions,
//            1000.0, "BOX", "Electronics", nullptr);
//
//        auto package2 = make_shared<Package>("pkg2", 3.5, dimensions,
//            500.0, "ENVELOPE", "Documents", nullptr);
//
//        vector<shared_ptr<Package>> packages = { package1, package2 };
//
//        auto shipment = logisticsService.createShipment(customer, packages, address);
//        shipments.push_back(shipment);
//
//        auto route = make_shared<Route>("route1", address, address, 150.0, 3.5);
//
//        auto checkpoint1 = make_shared<RouteCheckpoint>("cp1", 1, address,
//            "2024-01-16 10:00:00", "", route);
//        auto checkpoint2 = make_shared<RouteCheckpoint>("cp2", 2, address,
//            "2024-01-16 12:00:00", "", route);
//
//        route->checkpoints.push_back(checkpoint1);
//        route->checkpoints.push_back(checkpoint2);
//
//        logisticsService.optimizeRoute(route);
//
//        if (!vehicles.empty()) {
//            auto driverUser = make_shared<User>("user3", "Petr Driverov",
//                "driver@company.com", "+79995556677",
//                "2023-03-01", "ACTIVE", address);
//
//            auto driverEmployee = make_shared<Employee>("emp2", "Logistics",
//                "Driver", 40000.0,
//                "2023-03-01", driverUser);
//
//            auto driver = make_shared<Driver>("drv1", "1234567890",
//                "2025-12-31", driverEmployee);
//
//            auto delivery = make_shared<Delivery>("del1", "2024-01-16 08:00:00",
//                "", "ASSIGNED", driver,
//                vehicles[0], route);
//
//            logisticsService.assignVehicleToDelivery(delivery, vehicles);
//        }
//
//    }
//    catch (const LogisticsOperationException& e) {
//        cout << "Logistics operation error: " << e.what() << endl;
//    }
//}
//
//void TransportCompany::demonstrateWarehouseOperations() {
//    cout << "\nWAREHOUSE OPERATIONS DEMONSTRATION" << endl;
//    cout << "================================" << endl;
//
//    if (shipments.empty() || warehouses.empty()) return;
//
//    auto shipment = shipments[0];
//    auto warehouse = warehouses[0];
//
//    try {
//        auto receivedItems = warehouseService.receiveGoods(shipment, warehouse, nullptr);
//
//        if (!receivedItems.empty()) {
//            warehouseService.findInventoryItem(receivedItems[0]->sku, warehouse);
//        }
//
//        auto storageZone = make_shared<StorageZone>("zone1", "GENERAL", "15-25C",
//            1000.0, warehouse);
//
//        auto shelf1 = make_shared<Shelf>("sh1", 1, 500.0, storageZone);
//        auto shelf2 = make_shared<Shelf>("sh2", 2, 500.0, storageZone);
//
//        auto inventoryItem = make_shared<InventoryItem>("item_demo", "SKU_DEMO_001",
//            "Demo product", 100, 1500.0,
//            "2024-12-31", shelf1);
//
//        auto movement = warehouseService.moveStock(inventoryItem, 50, shelf1, shelf2);
//
//    }
//    catch (const WarehouseException& e) {
//        cout << "Warehouse operation error: " << e.what() << endl;
//    }
//}
//
//void TransportCompany::demonstrateSecurityOperations() {
//    cout << "\nSECURITY OPERATIONS DEMONSTRATION" << endl;
//    cout << "================================" << endl;
//
//    try {
//        auto user = securityService.authenticateUser("admin", "password123");
//
//        securityService.checkPasswordStrength("StrongPass123!");
//        securityService.checkPasswordStrength("weak");
//
//        securityService.authorizeAction(user, "READ", "FINANCIAL_REPORTS");
//
//    }
//    catch (const SecurityException& e) {
//        cout << "Security error: " << e.what() << endl;
//    }
//}
//
//void TransportCompany::runDemo() {
//    cout << "TRANSPORT COMPANY SYSTEM 'FASTLOGIX'" << endl;
//    cout << "===================================" << endl;
//
//    initializeSampleData();
//    demonstrateSecurityOperations();
//    demonstrateFinancialOperations();
//    demonstrateLogisticsOperations();
//    demonstrateWarehouseOperations();
//
//    cout << "\nADDITIONAL OPERATIONS" << endl;
//    cout << "====================" << endl;
//
//    if (!employees.empty()) {
//        auto report = analyticsService.generateFinancialReport("2024-01-01", "2024-01-15", employees[0]);
//    }
//
//    if (!vehicles.empty()) {
//        auto maintenance = vehicleService.scheduleMaintenance(vehicles[0], "REGULAR", "2024-02-01");
//    }
//
//    cout << "\nDEMONSTRATION COMPLETED!" << endl;
//}