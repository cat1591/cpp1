#include <iostream>
#include <string>
using namespace std;

// 基类：飞船
class Spaceship {
public:
    string model;
    double speed;
    double energy;
    
    Spaceship(string m, double s, double e) {
        model = m;
        speed = s;
        energy = e;
    }
    
    virtual void action() = 0;
};

// 运输飞船
class CargoShip : public Spaceship {
public:
    double cargoCapacity;
    
    CargoShip(string m, double s, double e, double cap) 
        : Spaceship(m, s, e) {
        cargoCapacity = cap;
    }
    
    void action() {
        cout << model << " 正在装载货物" << endl;
    }
    
    void loadCargo() {
        int cargo;
        cout << "输入货物数量: ";
        cin >> cargo;
        energy -= 5;
        cout << "装载完成！剩余能量: " << energy << endl;
    }
};

// 战斗飞船
class BattleShip : public Spaceship {
public:
    double weaponPower;
    
    BattleShip(string m, double s, double e, double power) 
        : Spaceship(m, s, e) {
        weaponPower = power;
    }
    
    void action() {
        cout << model << " 准备发射激光" << endl;
    }
    
    void fireLaser() {
        energy -= 10;
        cout << "发射激光！剩余能量: " << energy << endl;
    }
};

// 探索飞船
class ExplorerShip : public Spaceship {
public:
    double scanRange;
    
    ExplorerShip(string m, double s, double e, double range) 
        : Spaceship(m, s, e) {
        scanRange = range;
    }
    
    void action() {
        cout << model << " 正在扫描星球" << endl;
    }
    
    void scanPlanet() {
        energy -= 8;
        cout << "扫描完成！剩余能量: " << energy << endl;
    }
};

// 飞船库
class SpaceshipFleet {
public:
    int cargoCount = 0;
    int battleCount = 0;
    int explorerCount = 0;
    
    void addShip() {
        int type;
        cout << "1.运输 2.战斗 3.探索: ";
        cin >> type;
        
        if (type == 1) cargoCount++;
        else if (type == 2) battleCount++;
        else if (type == 3) explorerCount++;
        
        cout << "添加成功！" << endl;
    }
    
    void rentShip() {
        int type;
        cout << "1.运输 2.战斗 3.探索: ";
        cin >> type;
        
        if (type == 1 && cargoCount > 0) {
            cargoCount--;
            CargoShip ship("货运01", 100, 200, 500);
            ship.action();
            ship.loadCargo();
        }
        else if (type == 2 && battleCount > 0) {
            battleCount--;
            BattleShip ship("战斗01", 150, 180, 300);
            ship.action();
            ship.fireLaser();
        }
        else if (type == 3 && explorerCount > 0) {
            explorerCount--;
            ExplorerShip ship("探索01", 120, 160, 1000);
            ship.action();
            ship.scanPlanet();
        }
        else {
            cout << "库存不足！" << endl;
        }
    }
    
    void showStats() {
        cout << "运输船:" << cargoCount << " 战斗船:" << battleCount 
             << " 探索船:" << explorerCount << endl;
    }
};

int main() {
    SpaceshipFleet fleet;
    int choice;
    
    while (true) {
        cout << "\n1.租船 2.加船 3.查看 4.退出: ";
        cin >> choice;
        
        if (choice == 1) fleet.rentShip();
        else if (choice == 2) fleet.addShip();
        else if (choice == 3) fleet.showStats();
        else if (choice == 4) break;
    }
    
    return 0;
}