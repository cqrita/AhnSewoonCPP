#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


string ReadFile(string filePath)
{
    // 파일을 열기 위한 ifstream 객체 생성
    std::ifstream file(filePath);

    // 파일 내용을 문자열로 읽기
    std::stringstream sbuffer;
    sbuffer << file.rdbuf();

    // 파일 닫기
    file.close();

    std::string str = sbuffer.str();

    return str;
}