#ifndef STRUCT_TYPE_PROJECT_3_H_INCLUDED
#define STRUCT_TYPE_PROJECT_3_H_INCLUDED

#define Size_Num_Rase 4
#define Size_Name_Rase 40
#define Size_Name_Station 25
#define Size_Days_Rase 35
#define Amount_Time 15
#define Time 6

struct BusStation
{
    char num_rase[Size_Num_Rase];
    char name_rase[Size_Name_Rase];
    char name_station[Size_Name_Station];
    char days_rase[Size_Days_Rase];
    char** time_rase = new char*[Amount_Time];
    BusStation* next;
};

#endif // STRUCT_TYPE_PROJECT_3_H_INCLUDED
