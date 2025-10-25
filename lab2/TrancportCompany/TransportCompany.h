#ifndef TRANSPORTCOMPANY_H
#define TRANSPORTCOMPANY_H

#include <vector>
#include <string>

class Client;
class Driver;
class Vehicle;
class Order;

class TransportCompany {
private:
    std::string companyName;
    std::vector<Client*> clients;
    std::vector<Driver*> drivers;
    std::vector<Vehicle*> vehicles;
    std::vector<Order*> orders;
    double companyBalance;

public:
    TransportCompany(const std::string& name);
    ~TransportCompany();

    void addClient(Client* client);
    void addDriver(Driver* driver);
    void addVehicle(Vehicle* vehicle);
    void createOrder(Order* order);
    double calculateDailyRevenue() const;
    void processAllPayments();

    std::string getCompanyName() const { return companyName; }
    int getClientsCount() const { return clients.size(); }
    int getDriversCount() const { return drivers.size(); }
    int getVehiclesCount() const { return vehicles.size(); }
};

#endif//#ifndef TRANSPORT_COMPANY_H
//#define TRANSPORT_COMPANY_H
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <memory>
//#include <exception>
//#include <ctime>
//#include <cstdlib>
//#include <sstream>
//#include <iomanip>
//
//// ==================== ÁÀÇÎÂÛÅ ÈÑÊËŞ×ÅÍÈß ====================
//class LogisticsException : public std::exception {
//private:
//    std::string message;
//public:
//    LogisticsException(const std::string& msg) : message(msg) {}
//    const char* what() const noexcept override { return message.c_str(); }
//};
//
//class FinancialException : public LogisticsException {
//public:
//    FinancialException(const std::string& msg) : LogisticsException(msg) {}
//};
//
//class InsufficientFundsException : public FinancialException {
//public:
//    InsufficientFundsException() : FinancialException("Íåäîñòàòî÷íî ñğåäñòâ íà ñ÷åòå") {}
//};
//
//class PaymentProcessingException : public FinancialException {
//public:
//    PaymentProcessingException(const std::string& msg) : FinancialException(msg) {}
//};
//
//class LogisticsOperationException : public LogisticsException {
//public:
//    LogisticsOperationException(const std::string& msg) : LogisticsException(msg) {}
//};
//
//class RouteOptimizationException : public LogisticsOperationException {
//public:
//    RouteOptimizationException() : LogisticsOperationException("Îøèáêà îïòèìèçàöèè ìàğøğóòà") {}
//};
//
//class VehicleNotAvailableException : public LogisticsOperationException {
//public:
//    VehicleNotAvailableException() : LogisticsOperationException("Òğàíñïîğòíîå ñğåäñòâî íåäîñòóïíî") {}
//};
//
//class WarehouseException : public LogisticsException {
//public:
//    WarehouseException(const std::string& msg) : LogisticsException(msg) {}
//};
//
//class InventoryNotFoundException : public WarehouseException {
//public:
//    InventoryNotFoundException() : WarehouseException("Òîâàğ íå íàéäåí íà ñêëàäå") {}
//};
//
//class CapacityExceededException : public WarehouseException {
//public:
//    CapacityExceededException() : WarehouseException("Ïğåâûøåíà âìåñòèìîñòü ñêëàäà") {}
//};
//
//class SecurityException : public LogisticsException {
//public:
//    SecurityException(const std::string& msg) : LogisticsException(msg) {}
//};
//
//class AuthenticationException : public SecurityException {
//public:
//    AuthenticationException() : SecurityException("Îøèáêà àóòåíòèôèêàöèè") {}
//};
//
//class AuthorizationException : public SecurityException {
//public:
//    AuthorizationException() : SecurityException("Îøèáêà àâòîğèçàöèè") {}
//};
//
//// ==================== ÏĞÅÄÂÀĞÈÒÅËÜÍÛÅ ÎÁÚßÂËÅÍÈß ====================
//class Address;
//class GeoCoordinates;
//class User;
//class Customer;
//class Employee;
//class BankAccount;
//class Transaction;
//class Shipment;
//class Package;
//class Dimensions;
//class Route;
//class RouteCheckpoint;
//class Vehicle;
//class Driver;
//class Delivery;
//class Warehouse;
//class StorageZone;
//class Shelf;
//class InventoryItem;
//class StockMovement;
//class UserRole;
//class Permission;
//class Invoice;
//class Contract;
//class Tariff;
//class Report;
//class MaintenanceRecord;
//
//// ==================== ÁÀÇÎÂÛÅ ÑÓÙÍÎÑÒÈ ====================
//class GeoCoordinates {
//public:
//    double latitude;
//    double longitude;
//    double altitude;
//
//    GeoCoordinates(double lat, double lon, double alt);
//};
//
//class Address {
//public:
//    std::string address_id;
//    std::string country;
//    std::string city;
//    std::string street;
//    std::string building;
//    std::string zip_code;
//    std::shared_ptr<GeoCoordinates> coordinates;
//
//    Address(const std::string& id, const std::string& cntry, const std::string& cty,
//        const std::string& str, const std::string& bld, const std::string& zip,
//        std::shared_ptr<GeoCoordinates> coords);
//};
//
//class User {
//public:
//    std::string user_id;
//    std::string name;
//    std::string email;
//    std::string phone;
//    std::string registration_date;
//    std::string status;
//    std::shared_ptr<Address> address;
//    std::vector<std::shared_ptr<UserRole>> roles;
//
//    User(const std::string& id, const std::string& nm, const std::string& em,
//        const std::string& ph, const std::string& reg_date, const std::string& st,
//        std::shared_ptr<Address> addr);
//};
//
//class Customer {
//public:
//    std::string customer_id;
//    std::string company_name;
//    std::string tax_id;
//    double credit_limit;
//    int payment_terms;
//    std::shared_ptr<User> user;
//    std::vector<std::shared_ptr<Contract>> contracts;
//
//    Customer(const std::string& id, const std::string& company, const std::string& tax,
//        double credit_lim, int pay_terms, std::shared_ptr<User> usr);
//};
//
//class Employee {
//public:
//    std::string employee_id;
//    std::string department;
//    std::string position;
//    double salary;
//    std::string hire_date;
//    std::shared_ptr<User> user;
//    std::vector<std::shared_ptr<Vehicle>> assigned_vehicles;
//
//    Employee(const std::string& id, const std::string& dept, const std::string& pos,
//        double sal, const std::string& hire_d, std::shared_ptr<User> usr);
//};
//
//// ==================== ËÎÃÈÑÒÈ×ÅÑÊÈÅ ÑÓÙÍÎÑÒÈ ====================
//class Dimensions {
//public:
//    double length;
//    double width;
//    double height;
//
//    Dimensions(double len, double wid, double hgt);
//};
//
//class Package {
//public:
//    std::string package_id;
//    double weight;
//    std::shared_ptr<Dimensions> dimensions;
//    double declared_value;
//    std::string package_type;
//    std::string contents_description;
//    std::shared_ptr<Shipment> shipment;
//
//    Package(const std::string& id, double wgt, std::shared_ptr<Dimensions> dims,
//        double decl_val, const std::string& pkg_type, const std::string& contents,
//        std::shared_ptr<Shipment> ship);
//};
//
//class Shipment {
//public:
//    std::string shipment_id;
//    std::string tracking_number;
//    std::string created_date;
//    std::string delivery_deadline;
//    std::string status;
//    std::shared_ptr<Customer> customer;
//    std::vector<std::shared_ptr<Package>> packages;
//    std::shared_ptr<Route> route;
//
//    Shipment(const std::string& id, const std::string& tracking, const std::string& created,
//        const std::string& deadline, const std::string& st, std::shared_ptr<Customer> cust);
//};
//
//class RouteCheckpoint {
//public:
//    std::string checkpoint_id;
//    int sequence_number;
//    std::shared_ptr<Address> address;
//    std::string estimated_arrival;
//    std::string actual_arrival;
//    std::shared_ptr<Route> route;
//
//    RouteCheckpoint(const std::string& id, int seq_num, std::shared_ptr<Address> addr,
//        const std::string& est_arrival, const std::string& act_arrival,
//        std::shared_ptr<Route> rt);
//};
//
//class Route {
//public:
//    std::string route_id;
//    std::shared_ptr<Address> start_point;
//    std::shared_ptr<Address> end_point;
//    double total_distance;
//    double estimated_duration;
//    std::vector<std::shared_ptr<RouteCheckpoint>> checkpoints;
//
//    Route(const std::string& id, std::shared_ptr<Address> start, std::shared_ptr<Address> end,
//        double distance, double duration);
//};
//
//class Vehicle {
//public:
//    std::string vehicle_id;
//    std::string license_plate;
//    std::string vehicle_type;
//    double capacity;
//    std::shared_ptr<Address> current_location;
//    std::string status;
//    std::vector<std::shared_ptr<MaintenanceRecord>> maintenance_records;
//
//    Vehicle(const std::string& id, const std::string& license, const std::string& type,
//        double cap, std::shared_ptr<Address> location, const std::string& st);
//};
//
//class Driver : public Employee {
//public:
//    std::string driver_id;
//    std::string license_number;
//    std::string license_expiry;
//    std::shared_ptr<Employee> employee;
//    std::vector<std::shared_ptr<Delivery>> assigned_deliveries;
//
//    Driver(const std::string& id, const std::string& license, const std::string& expiry,
//        std::shared_ptr<Employee> emp);
//};
//
//class Delivery {
//public:
//    std::string delivery_id;
//    std::string start_time;
//    std::string end_time;
//    std::string status;
//    std::shared_ptr<Driver> driver;
//    std::shared_ptr<Vehicle> vehicle;
//    std::shared_ptr<Route> route;
//
//    Delivery(const std::string& id, const std::string& start, const std::string& end,
//        const std::string& st, std::shared_ptr<Driver> drv, std::shared_ptr<Vehicle> vhc,
//        std::shared_ptr<Route> rt);
//};
//
//// ==================== ÔÈÍÀÍÑÎÂÛÅ ÑÓÙÍÎÑÒÈ ====================
//class BankAccount {
//public:
//    std::string account_id;
//    std::string account_number;
//    std::string bank_name;
//    double balance;
//    std::string currency;
//    std::shared_ptr<Customer> owner;
//
//    BankAccount(const std::string& id, const std::string& acc_num, const std::string& bank,
//        double bal, const std::string& curr, std::shared_ptr<Customer> own);
//};
//
//class Transaction {
//public:
//    std::string transaction_id;
//    double amount;
//    std::string currency;
//    std::string transaction_date;
//    std::string description;
//    std::shared_ptr<BankAccount> source_account;
//    std::shared_ptr<BankAccount> destination_account;
//
//    Transaction(const std::string& id, double amt, const std::string& curr,
//        const std::string& trans_date, const std::string& desc,
//        std::shared_ptr<BankAccount> src, std::shared_ptr<BankAccount> dest);
//};
//
//class Invoice {
//public:
//    std::string invoice_id;
//    std::string invoice_number;
//    std::string issue_date;
//    std::string due_date;
//    double total_amount;
//    std::string status;
//    std::shared_ptr<Customer> customer;
//    std::shared_ptr<Shipment> shipment;
//
//    Invoice(const std::string& id, const std::string& inv_num, const std::string& issue,
//        const std::string& due, double total, const std::string& st,
//        std::shared_ptr<Customer> cust, std::shared_ptr<Shipment> ship);
//};
//
//// ==================== ÑÊËÀÄÑÊÈÅ ÑÓÙÍÎÑÒÈ ====================
//class Permission {
//public:
//    std::string permission_id;
//    std::string permission_name;
//    std::string description;
//
//    Permission(const std::string& id, const std::string& name, const std::string& desc);
//};
//
//class UserRole {
//public:
//    std::string role_id;
//    std::string role_name;
//    std::vector<std::shared_ptr<Permission>> permissions;
//
//    UserRole(const std::string& id, const std::string& name);
//};
//
//class Shelf {
//public:
//    std::string shelf_id;
//    int level;
//    double max_weight;
//    std::shared_ptr<StorageZone> storage_zone;
//    std::vector<std::shared_ptr<InventoryItem>> inventory_items;
//
//    Shelf(const std::string& id, int lvl, double max_wgt, std::shared_ptr<StorageZone> zone);
//};
//
//class StorageZone {
//public:
//    std::string zone_id;
//    std::string zone_type;
//    std::string temperature_range;
//    double capacity;
//    std::shared_ptr<Warehouse> warehouse;
//    std::vector<std::shared_ptr<Shelf>> shelves;
//
//    StorageZone(const std::string& id, const std::string& type, const std::string& temp,
//        double cap, std::shared_ptr<Warehouse> wh);
//};
//
//class Warehouse {
//public:
//    std::string warehouse_id;
//    std::string name;
//    std::shared_ptr<Address> address;
//    double total_capacity;
//    double current_occupancy;
//    std::vector<std::shared_ptr<StorageZone>> zones;
//
//    Warehouse(const std::string& id, const std::string& nm, std::shared_ptr<Address> addr,
//        double total_cap, double current_occ);
//};
//
//class InventoryItem {
//public:
//    std::string item_id;
//    std::string sku;
//    std::string name;
//    int quantity;
//    double unit_price;
//    std::string expiry_date;
//    std::shared_ptr<Shelf> shelf;
//
//    InventoryItem(const std::string& id, const std::string& sk, const std::string& nm,
//        int qty, double price, const std::string& expiry, std::shared_ptr<Shelf> sh);
//};
//
//class StockMovement {
//public:
//    std::string movement_id;
//    std::string movement_type;
//    int quantity;
//    std::string movement_date;
//    std::shared_ptr<InventoryItem> item;
//    std::shared_ptr<Shelf> source_location;
//    std::shared_ptr<Shelf> destination_location;
//
//    StockMovement(const std::string& id, const std::string& type, int qty,
//        const std::string& mov_date, std::shared_ptr<InventoryItem> itm,
//        std::shared_ptr<Shelf> src, std::shared_ptr<Shelf> dest);
//};
//
//// ==================== ÄÎÏÎËÍÈÒÅËÜÍÛÅ ÑÓÙÍÎÑÒÈ ====================
//class Contract {
//public:
//    std::string contract_id;
//    std::string start_date;
//    std::string end_date;
//    std::string terms;
//    std::string status;
//    std::shared_ptr<Customer> customer;
//    std::vector<std::shared_ptr<Tariff>> tariffs;
//
//    Contract(const std::string& id, const std::string& start, const std::string& end,
//        const std::string& trm, const std::string& st, std::shared_ptr<Customer> cust);
//};
//
//class Tariff {
//public:
//    std::string tariff_id;
//    std::string service_type;
//    double rate_per_kg;
//    double rate_per_km;
//    double minimum_charge;
//    std::shared_ptr<Contract> contract;
//
//    Tariff(const std::string& id, const std::string& service, double rate_kg,
//        double rate_km, double min_charge, std::shared_ptr<Contract> cntr);
//};
//
//class Report {
//public:
//    std::string report_id;
//    std::string report_type;
//    std::string generated_date;
//    std::string data;
//    std::shared_ptr<Employee> generated_by;
//
//    Report(const std::string& id, const std::string& type, const std::string& gen_date,
//        const std::string& dt, std::shared_ptr<Employee> gen_by);
//};
//
//class MaintenanceRecord {
//public:
//    std::string record_id;
//    std::string maintenance_date;
//    std::string maintenance_type;
//    double cost;
//    std::string description;
//    std::shared_ptr<Vehicle> vehicle;
//
//    MaintenanceRecord(const std::string& id, const std::string& date, const std::string& type,
//        double cst, const std::string& desc, std::shared_ptr<Vehicle> vhc);
//};
//
//// ==================== ÑÅĞÂÈÑÛ ====================
//class FinancialService {
//public:
//    std::shared_ptr<Transaction> transferMoneyBetweenAccounts(
//        std::shared_ptr<BankAccount> sourceAccount,
//        std::shared_ptr<BankAccount> destinationAccount,
//        double amount);
//
//    bool processInvoicePayment(std::shared_ptr<Invoice> invoice,
//        const std::string& paymentMethod);
//
//    double calculateShipmentCost(std::shared_ptr<Shipment> shipment,
//        std::shared_ptr<Tariff> tariff);
//};
//
//class SecurityService {
//public:
//    std::shared_ptr<User> authenticateUser(const std::string& username,
//        const std::string& password);
//
//    bool checkPasswordStrength(const std::string& password);
//
//    bool authorizeAction(std::shared_ptr<User> user,
//        const std::string& action,
//        const std::string& resource);
//};
//
//class LogisticsService {
//public:
//    std::shared_ptr<Shipment> createShipment(std::shared_ptr<Customer> customer,
//        const std::vector<std::shared_ptr<Package>>& packages,
//        std::shared_ptr<Address> deliveryAddress);
//
//    std::shared_ptr<Route> optimizeRoute(std::shared_ptr<Route> route);
//
//    bool assignVehicleToDelivery(std::shared_ptr<Delivery> delivery,
//        const std::vector<std::shared_ptr<Vehicle>>& availableVehicles);
//
//    std::string generateTrackingNumber();
//};
//
//class WarehouseService {
//public:
//    std::vector<std::shared_ptr<InventoryItem>> receiveGoods(
//        std::shared_ptr<Shipment> shipment,
//        std::shared_ptr<Warehouse> warehouse,
//        std::shared_ptr<StorageZone> targetZone);
//
//    std::shared_ptr<InventoryItem> findInventoryItem(const std::string& sku,
//        std::shared_ptr<Warehouse> warehouse);
//
//    std::shared_ptr<StockMovement> moveStock(std::shared_ptr<InventoryItem> item,
//        int quantity,
//        std::shared_ptr<Shelf> fromShelf,
//        std::shared_ptr<Shelf> toShelf);
//};
//
//class AnalyticsService {
//public:
//    std::shared_ptr<Report> generateFinancialReport(const std::string& startDate,
//        const std::string& endDate,
//        std::shared_ptr<Employee> employee);
//
//    std::string calculateDeliveryPerformance(std::shared_ptr<Driver> driver,
//        const std::string& startDate,
//        const std::string& endDate);
//};
//
//class VehicleService {
//public:
//    std::shared_ptr<MaintenanceRecord> scheduleMaintenance(
//        std::shared_ptr<Vehicle> vehicle,
//        const std::string& maintenanceType,
//        const std::string& scheduledDate);
//};
//
//// ==================== ÎÑÍÎÂÍÀß ÑÈÑÒÅÌÀ ====================
//class TransportCompany {
//private:
//    std::vector<std::shared_ptr<Customer>> customers;
//    std::vector<std::shared_ptr<Employee>> employees;
//    std::vector<std::shared_ptr<Vehicle>> vehicles;
//    std::vector<std::shared_ptr<Warehouse>> warehouses;
//    std::vector<std::shared_ptr<Shipment>> shipments;
//
//    FinancialService financialService;
//    SecurityService securityService;
//    LogisticsService logisticsService;
//    WarehouseService warehouseService;
//    AnalyticsService analyticsService;
//    VehicleService vehicleService;
//
//public:
//    TransportCompany();
//
//    void initializeSampleData();
//    void demonstrateFinancialOperations();
//    void demonstrateLogisticsOperations();
//    void demonstrateWarehouseOperations();
//    void demonstrateSecurityOperations();
//    void runDemo();
//};
//
//#endif
