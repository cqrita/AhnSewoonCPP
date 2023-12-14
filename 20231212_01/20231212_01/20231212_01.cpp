// 20231212_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "httplib.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/prettywriter.h"

#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;
using namespace std;
struct RequestInserUserScoreDTO
{
    string Name;

    int Score;
public:
    static string ToJson(RequestInserUserScoreDTO dto,bool isPretty=false)
    {
        Document d(kObjectType);
        Document::AllocatorType& allocator = d.GetAllocator();
        d.AddMember("Name", Value().SetString(dto.Name.c_str(), allocator), allocator);
        d.AddMember("Value", Value().SetInt(dto.Score), allocator);
        StringBuffer buffer;
        if (isPretty == false)
        {
            Writer<StringBuffer> writer(buffer);
            d.Accept(writer);
        }
        else
        {
            PrettyWriter<StringBuffer> writer(buffer);
            d.Accept(writer);
        }
        return buffer.GetString();
    }
};
int main()
{
    
    Document d(kObjectType);
    Document::AllocatorType& allocator = d.GetAllocator();
    d.AddMember("Name", Value().SetString("User3",allocator), allocator);
    d.AddMember("Value", Value().SetInt(27), allocator);
    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    
    RequestInserUserScoreDTO dto = { string("User3"),3 };
    // HTTP
    httplib::Client cli("http://localhost:5070");


    auto res = cli.Post("/SBSStudy/InsertUserScore", RequestInserUserScoreDTO::ToJson(dto), "application/json");
    res->status;
    std::cout<<res->body<<std::endl;
    

}
