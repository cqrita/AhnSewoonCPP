#pragma once
#include <winsqlite/winsqlite3.h>
class DataManager
{
	DECLARE_SINGLE(DataManager);

private:
	vector<RECT> _collisionDatas;
	sqlite3* _db;
public:
	void Init();
	void Release();
public:
	void SaveCollisionData(vector<RECT> rectVec);
	void ClearCollisionData();

	vector<RECT>GetCollisionData();
};

