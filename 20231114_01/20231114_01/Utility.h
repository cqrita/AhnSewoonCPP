#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


string ReadFile(string filePath)
{
    // ������ ���� ���� ifstream ��ü ����
    std::ifstream file(filePath);

    // ���� ������ ���ڿ��� �б�
    std::stringstream sbuffer;
    sbuffer << file.rdbuf();

    // ���� �ݱ�
    file.close();

    std::string str = sbuffer.str();

    return str;
}