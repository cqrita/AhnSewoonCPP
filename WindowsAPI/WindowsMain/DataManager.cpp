#include "stdafx.h"
#include "DataManager.h"
static int callback(void* data, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
void DataManager::Init()
{
    char* errMsg = 0;
    int rc;

    //db open
    rc = sqlite3_open("client.db", &_db);

    if (rc != SQLITE_OK) {
        std::cerr << "[DataManager] Can't open database: " << sqlite3_errmsg(_db) << std::endl;
        return;
    }
    else {
        std::cout << "[DataManager] Opened database successfully" << std::endl;
    }
    //table create
    const char* sql = "CREATE TABLE IF NOT EXISTS TblCollisionDatas("
        "_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT"
        ",_left INTEGER NOT NULL"
        ",_top INTEGER NOT NULL"
        ",_right INTEGER NOT NULL"
        ",_bottom INTEGER NOT NULL"
        ");";
    rc = sqlite3_exec(_db, sql,callback,0,&errMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << "[DataManager] Table created successfully" << std::endl;
    }
    GetCollisionData();
}

void DataManager::Release()
{
    sqlite3_close(_db);
}

void DataManager::SaveCollisionData(vector<RECT> rectVec)
{
    char* errMsg = 0;
    int rc;
   
    string str;
    for (int i = 0; i < rectVec.size(); i++)
    {
        RECT rect= rectVec[i];
        str = str + "(" + to_string(rect.left)+", "+ to_string(rect.top) + ", " + to_string(rect.right) + ", " + to_string(rect.bottom) + ")";
        if (i != rectVec.size() - 1)
        {
            str = str + ", ";
        }
    }
    string aa = "INSERT INTO TblCollisionDatas(_left,_top,_right,_bottom) VALUES" + str + ";";
    const char* sql = aa.c_str();
    rc = sqlite3_exec(_db, sql, callback, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << "[DataManager] Data inserted successfully" << std::endl;
    }
    
}

vector<RECT> DataManager::GetCollisionData()
{
    vector<RECT> rv;
    int rc;
    sqlite3_stmt* stmt;
    const char* tail;
    const char* select_sql = "SELECT _left,_top,_right,_bottom  from TblCollisionDatas";


    rc = sqlite3_prepare_v2(_db, select_sql, -1, &stmt, &tail);
    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << sqlite3_errmsg(_db) << std::endl;
    }
    else
    {
        while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
        {
            int columnIndex = 0;
            RECT rect;
            rect.left = sqlite3_column_int(stmt, columnIndex++);
            rect.top = sqlite3_column_int(stmt, columnIndex++);
            rect.right = sqlite3_column_int(stmt, columnIndex++);
            rect.bottom = sqlite3_column_int(stmt, columnIndex++);
            rv.push_back(rect);
        }
    }
	return rv;
}
