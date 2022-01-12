class ParkingSystem {
public:
int a[4]={0,0,0,0};
ParkingSystem(int big, int medium, int small) {
a[1]=big;
a[2]=medium;
a[3]=small;
}

bool addCar(int carType) {
    if(a[carType]==0)
        return 0;
    else {
        a[carType]--;
        return 1;

    }
}
};