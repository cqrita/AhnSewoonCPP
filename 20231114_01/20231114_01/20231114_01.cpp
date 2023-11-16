#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <iostream>
#include "Utility.h"
#include <vector>
#include <Windows.h>
using namespace rapidjson;
using namespace std;
void Assert(bool expression, string title, string message)
{
    if (expression == false)
    {
        MessageBoxA(NULL, title.c_str(), message.c_str(), 0);
    }
}
class GameOption
{
private:
    int _difficulty;
    int _sound;
    int _graphics;
    vector<int> _customArray;
public:
    void LoadData(char* json)
    {
        Document d;
        d.Parse(json);
        Assert(d.IsObject(), "assert", "assert");
        Assert(d["difficulty"].IsInt(), "assert", "assert");
        Assert(d["sound"].IsInt(), "assert", "assert");
        Assert(d["graphics"].IsInt(), "assert", "assert");
        Assert(d["customArrays"].IsArray(), "assert", "assert");

        _difficulty = d["difficulty"].GetInt();
        _sound = d["sound"].GetInt();
        _graphics = d["graphics"].GetInt();
        for (auto& value : d["customArrays"].GetArray())
        {
            _customArray.push_back(value.GetInt());
        }
    }
    void PrintData()
    {
        cout << "difficulty : " << _difficulty << endl;
        cout << "sound : " << _sound << endl;

        cout << "graphics : " << _graphics << endl;
        cout << "customArray : ";

        for (auto& value : _customArray)
        {
            cout << value << ' ';
        }

    }
};

int main() {
    // 1. Parse a JSON string into DOM.
    FILE* f;
    fopen_s(&f, "myData.json", "rb");
    char json[1666];
    FileReadStream(f, json, sizeof(json));
    GameOption GO;
    GO.LoadData(json);
    GO.PrintData();
    if (f != 0)
    {
        fclose(f);
    }
    return 0;
}