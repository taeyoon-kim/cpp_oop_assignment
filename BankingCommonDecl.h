/*
*Banking System Ver 0.7
*파일이름: BankingCommonDecl.h
*작성자: 김태윤
*내용: 파일 분할
*/

#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

#endif __BANKING_COMMON_H__