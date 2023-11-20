// rapidjson/example/simpledom/simpledom.cpp`
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <iostream>
#include "Utility.h"
using namespace rapidjson;
using namespace std;
struct Player
{
    int hp;
    int level;
};
int main() {
    errno_t err;
    FILE* fp;
    // 1. Parse a JSON string into DOM.
    err = fopen_s(&fp,"myData.json", "rb"); // non-Windows use "r"

    char readBuffer[16384];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));
    Document d;
    d.ParseStream(is);

    // 2. Modify it by DOM.
    Value& hp = d["hp"];
    Player p;
    p.hp = hp.GetInt();
    Value& level = d["hp"];
    p.level = level.GetInt();
    cout << "hp :" << p.hp << endl;
    cout << "level :" << p.level << endl;
    err = fclose(fp);

    return 0;
}