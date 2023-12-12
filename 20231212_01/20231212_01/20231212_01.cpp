// 20231212_01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "httplib.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;

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

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;

    // HTTP
    httplib::Client cli("http://localhost:5070");


    auto res = cli.Get("/SBSStudy/GetUser?Name=User1");
    res->status;
    std::cout<<res->body<<std::endl;
    

}
