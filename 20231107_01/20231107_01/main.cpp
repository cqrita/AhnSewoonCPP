#include <iostream>
#include <winsqlite/winsqlite3.h>
#include <string>
#include <vector>
using namespace std;
struct ItemInfoDTO
{
    int _id;
    string _name;
    int _price;
    int _type;
};
struct ChampionInfoDTO
{
    int _id;
    string _name;
    float _attack;
    float _hp;
    vector<ItemInfoDTO> _items;
};
struct ChampionItemMappingDTO
{

};
static int callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

int main() {
    sqlite3* db;
    sqlite3_stmt* stmt;
    
    char* errMsg = 0;
    int rc;

    rc = sqlite3_open("Study.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return(0);
    }
    else {
        std::cout << "Opened database successfully" << std::endl;
    }


    // Select Data
    const char* select_sql = "SELECT _id,_name,_price,_type from TblItemInfo";

    const char* tail;
    rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, &tail);

    //rc = sqlite3_exec(db, select_sql, callback, 0, &errMsg);
    vector<ItemInfoDTO> ItemInfos;
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        while (rc = sqlite3_step(stmt) == SQLITE_ROW)
        {
            ItemInfoDTO dto;
            dto._id = sqlite3_column_int(stmt, 0);
            dto._name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            dto._price = sqlite3_column_int(stmt, 2);
            dto._type = sqlite3_column_int(stmt, 3);
            ItemInfos.push_back(dto);
        }
    }

    select_sql = "SELECT _id,_name,_attack,_hp from TblChampionInfo";

    rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, &tail);

    //rc = sqlite3_exec(db, select_sql, callback, 0, &errMsg);
    vector<ChampionInfoDTO> ChampionInfos;
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        while (rc = sqlite3_step(stmt) == SQLITE_ROW)
        {
            ChampionInfoDTO dto;
            dto._id = sqlite3_column_int(stmt, 0);
            dto._name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            dto._attack = sqlite3_column_double(stmt, 2);
            dto._hp = sqlite3_column_double(stmt, 3);
            ChampionInfos.push_back(dto);
        }
    }

    select_sql = "SELECT _id, _championInfoId, _itemInfoId  from TblChampionItemMapping";

    rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, &tail);

    //rc = sqlite3_exec(db, select_sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        while (rc = sqlite3_step(stmt) == SQLITE_ROW)
        {
            for (ItemInfoDTO items : ItemInfos)
            {
                if (items._id == sqlite3_column_int(stmt, 2))
                {
                    for (ChampionInfoDTO& champs : ChampionInfos)
                    {
                        if (champs._id == sqlite3_column_int(stmt, 1))
                        {
                            champs._items.push_back(items);
                        }
                    }
                }
            }
        }
    }
    for (ChampionInfoDTO champs : ChampionInfos)
    {
        cout << champs._id << endl;
        cout << champs._name << endl;
        cout << champs._attack << endl;
        cout << champs._hp << endl;
        cout << champs._items.size() << endl;
        cout << endl;
    }
    sqlite3_close(db);
    return 0;
}
