#include <iostream>
#include <winsqlite/winsqlite3.h>
#include <string>
#include <vector>
#include <map>
#include "StringUtility.h"
using namespace std;


struct ItemInfoDto
{
    int _id;
    string _name;
    int _price;
    int _type;

    void Print()
    {
        cout << "Id : " << _id << endl;
        cout << "Name : " << _name << endl;
        cout << "Price : " << _price << endl;
        cout << "Type : " << _type << endl;
    }
};

struct ChampionInfoDto
{
    int _id;
    string _name;
    float _attack;
    float _hp;

    void Print()
    {
        cout << "Id : " << _id << endl;
        cout << "Name : " << _name << endl;
        cout << "Attack : " << _attack << endl;
        cout << "Hp : " << _hp << endl;
    }
};

struct ChampionItemMappingDto
{
    int _id;
    int _championInfoId;
    int _itemInfoId;

    void Print()
    {
        cout << "Id : " << _id << endl;
        cout << "ChampionInfoId : " << _championInfoId << endl;
        cout << "ItemInfoId : " << _itemInfoId << endl;
    }
};



map<int, ItemInfoDto*> itemInfos;
map<int, ChampionInfoDto*> championInfos;
map<int, ChampionItemMappingDto*> championItemMappings;




class Champion
{
public:
    ChampionInfoDto* _info = nullptr;
    vector<int> _items;

    void Print()
    {
        cout << "챔피언 정보 : " << endl;
        _info->Print();
        cout << "가진내용 : " << endl;
        for (int index : _items)
        {
            itemInfos[index]->Print();
        }
    }
};


map<int, Champion*> champions;

static int callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

void LoadTblItemInfo(sqlite3* db)
{
    int rc;
    // Select Data
    sqlite3_stmt* stmt;
    const char* tail;
    const char* select_sql = "SELECT _id, _name, _price, _type  from TblItemInfo";


    rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, &tail);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
        {
            int columnIndex = 0;
            ItemInfoDto* dto = new ItemInfoDto();
            dto->_id = sqlite3_column_int(stmt, columnIndex++);
            dto->_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, columnIndex++));
            dto->_price = sqlite3_column_int(stmt, columnIndex++);
            dto->_type = sqlite3_column_int(stmt, columnIndex++);
            itemInfos[dto->_id] = dto;
        }
    }
}


void LoadTblChampionInfo(sqlite3* db)
{
    int rc;
    // Select Data
    sqlite3_stmt* stmt;
    const char* tail;
    const char* select_sql = "SELECT _id, _name, _attack, _hp FROM TblChampionInfo";


    rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, &tail);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
        {
            int columnIndex = 0;
            ChampionInfoDto* dto = new ChampionInfoDto();
            dto->_id = sqlite3_column_int(stmt, columnIndex++);
            dto->_name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, columnIndex++));
            dto->_attack = static_cast<float>(sqlite3_column_double(stmt, columnIndex++));
            dto->_hp = static_cast<float>(sqlite3_column_double(stmt, columnIndex++));
            championInfos[dto->_id] = dto;
        }
    }
}

void LoadTblChampionItemMapping(sqlite3* db)
{
    int rc;
    // Select Data
    sqlite3_stmt* stmt;
    const char* tail;
    const char* select_sql = "SELECT _id, _championInfoId, _itemInfoId FROM TblChampionItemMapping";


    rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, &tail);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
        {
            int columnIndex = 0;
            ChampionItemMappingDto* dto = new ChampionItemMappingDto();
            dto->_id = sqlite3_column_int(stmt, columnIndex++);
            dto->_championInfoId = sqlite3_column_int(stmt, columnIndex++);
            dto->_itemInfoId = sqlite3_column_int(stmt, columnIndex++);
            championItemMappings[dto->_id] = dto;
        }
    }
}


void LoadChampion(sqlite3* db)
{
    int rc;
    // Select Data
    sqlite3_stmt* stmt;
    const char* tail;
    const char* select_sql = "SELECT tci._id, tci._name, tci._attack, tci._hp, tcim._itemInfoId FROM TblChampionInfo tci JOIN TblChampionItemMapping tcim ON tci._id = tcim._championInfoId ";

    rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, &tail);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
        {
            int columnIndex = 0;

            int id = sqlite3_column_int(stmt, columnIndex++);
            string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, columnIndex++));
            float attack = static_cast<float>(sqlite3_column_double(stmt, columnIndex++));
            float hp = static_cast<float>(sqlite3_column_double(stmt, columnIndex++));

            if (champions.count(id) == 0)
            {
                Champion* champion = new Champion();
                champion->_info = new ChampionInfoDto();
                champion->_info->_id = id;
                champion->_info->_name = name;
                champion->_info->_attack = attack;
                champion->_info->_hp = hp;

                champions[champion->_info->_id] = champion;
            }

            int itemInfoId = sqlite3_column_int(stmt, columnIndex++);

            champions[id]->_items.push_back(itemInfoId);
        }
    }
}

void LoadChampion2(sqlite3* db)
{
    int rc;
    // Select Data
    sqlite3_stmt* stmt;
    const char* tail;
    const char* select_sql = "SELECT tci._id, tci._name, tci._attack, tci._hp, GROUP_CONCAT(tcim._itemInfoId) AS itemIds FROM TblChampionInfo tci JOIN TblChampionItemMapping tcim ON tci._id = tcim._championInfoId GROUP BY tci._id, tci._name, tci._attack, tci._hp";

    rc = sqlite3_prepare_v2(db, select_sql, -1, &stmt, &tail);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
        {
            int columnIndex = 0;

            int id = sqlite3_column_int(stmt, columnIndex++);
            string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, columnIndex++));
            float attack = static_cast<float>(sqlite3_column_double(stmt, columnIndex++));
            float hp = static_cast<float>(sqlite3_column_double(stmt, columnIndex++));
            string itemIds = reinterpret_cast<const char*>(sqlite3_column_text(stmt, columnIndex++));
            if (champions.count(id) == 0)
            {
                Champion* champion = new Champion();
                champion->_info = new ChampionInfoDto();
                champion->_info->_id = id;
                champion->_info->_name = name;
                champion->_info->_attack = attack;
                champion->_info->_hp = hp;
                vector<string> itemStrVec = Split(itemIds, ',');
                vector<int> itemVec;
                for (string itemStr : itemStrVec)
                {
                    itemVec.push_back(stoi(itemStr));
                }
                champion->_items = itemVec;
                champions[champion->_info->_id] = champion;

            }
        }
    }
}




int main() {
    sqlite3* db;
    char* errMsg = 0;
    int rc;

    rc = sqlite3_open("study.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return(0);
    }
    else {
        std::cout << "Opened database successfully" << std::endl;
    }


    LoadTblItemInfo(db);
    LoadTblChampionInfo(db);
    LoadTblChampionItemMapping(db);

    /*
    vector<ItemInfoDto*> itemInfos;
    vector<ChapionInfoDto*> chapionInfos;
    vector<Chapion*> chapions;
    */
    for (auto item : itemInfos)
    {
        cout << "-------------------" << endl;
        item.second->Print();
        cout << "-------------------" << endl;
    }

    for (auto champion : championInfos)
    {
        cout << "-------------------" << endl;
        champion.second->Print();
        cout << "-------------------" << endl;
    }

    for (auto cim : championItemMappings)
    {
        cout << "-------------------" << endl;
        cim.second->Print();
        cout << "-------------------" << endl;
    }


    sqlite3_close(db);

    /* for (auto champion : championInfos)
     {
         Champion* c = new Champion();
         c->_info = champion.second;

         for (auto championItemMapping : championItemMappings)
         {
             if (championItemMapping.second->_championInfoId == c->_info->_id)
             {
                 c->_items.push_back(championItemMapping.second->_itemInfoId);
             }
         }
         c->Print();

     }*/

    LoadChampion2(db);

    for (auto champion : champions)
    {
        champion.second->Print();

    }



    return 0;
}
