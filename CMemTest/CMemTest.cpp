﻿// CMemTest.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
/**
* @file CMemTest.cpp
* @brief メモリリークテスト用
* @author 油井俊輔
* @date 2019/05/22
* @details メモリリークのテスト。意図的に起こした
*/
#define _CRTBG_MAP_ALLOC
#include<stdlib.h>
#include<crtdbg.h>

#include "pch.h"
#include <iostream>
#include<malloc.h>

#ifdef _DEBUG
#define DBG_NEW new (_NORMAL_BLOCK,__FILE__,__LINE__)
#else
#define DBG_NEW new
#endif // DEBUG
/**
* @brief ポイントデータクラス
*/
struct PointData {
	int x;
	int y;
	int z;
};
/**
* @brief キャラクターデータクラス
* @details わかんね
*/
struct CharacterData{
	char name[100];
	int hp;
	int mp;
};

/**
* @brief 3を足す関数
* @param[in] a(元の値)計算する元の数値
* @param[out] b(代入先)計算結果を代入する先
* @return bool 常にtrueを返す
* @details 第一引数に 3 を足して、第 2 引数に結果を代入 
*/
bool function(int a, int &b) {
	b = a + 3;
	return true;
}

int main()
{
	//! *cに100のメモリのアドレスを代入
	char *c = (char*)_alloca(100);  
	char y;
	*c = 'a';   //*cのなかの番地にaを代入してくださいという命令
	y = *c;


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 160;  //breakpoint
	PointData*pPointData = DBG_NEW PointData;
	delete pPointData;   //breakpoint



	for (int i = 0; i < 50; i++) {
		pPointData = DBG_NEW PointData;
		delete pPointData;   //breakpoint
	}
	_RPT0(_CRT_WARN, "Set Break Point");  //breakpoint

	CharacterData*pCharacterData = DBG_NEW CharacterData;
	delete pCharacterData;  //beakepoint

	for (int i = 0; i < 50; i++) {
		pCharacterData = DBG_NEW CharacterData;
		delete pCharacterData;  //beakepoint

	}
	
		//delete pPointData;   //breakpoint
		//delete pCharacterData;  //beakepoint
	

	_CrtDumpMemoryLeaks();   //breakpoint

	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

//<ワシ>＜２９２９＞