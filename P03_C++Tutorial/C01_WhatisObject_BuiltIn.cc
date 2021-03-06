//******************************************************************************
// Introduction to C++ for Geant4 Users: オブジェクトとは何か - 1
//******************************************************************************

//------------------------------------------------------------------------------
// [演習 1]  built-inタイプ(int, double, char, 等）のオブジェクトの作成方法の習得
//          (手順)  sampleコードを参照し、次行の「？」部分を完成させ、プログラムを実行する
//------------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main() {

// intタイプの変数を作り初期化する - c-styleを使う
  int eVar = 5;                      // example コード
  ??? mVar ? 7;                      // [問] 上と同じタイプの変数を作り初期化

// intタイプのオブジェクトを作り初期化する - ()の代わりに{}でもOK
  int eOb1( 5 );                     // example コード
  ??? mOb1? 7 ?;                     // [問] 上と同じタイプのオブジェクトを作り初期化

// doubleタイプのオブジェクトを作り初期化する - ()の代わりに{}でもOK
  double eOb2{ 3.14 };               // example コード
  ?????? mOb2? 2.71 ?;               // [問] 上と同じタイプのオブジェクトを作り初期化

// c-style arrayイプのオブジェクトを作り初期化する - {}必須 （C言語の時からこのスタイル）
  double eOb3[] = { 1.23, 4.56 };    // example コード
  ?????? mOb3[] = ? 6.78, 9.01 ?;    // [問] 上と同じタイプのオブジェクトを作り初期化


//------------------------------------------------------------------------------
// [演習 2]  上で作ったオブジェクトが持つ情報を書き出す
//    * 以下のコマンドでプログラムを実行し結果を見る
//       % c++ C01_WhatIsObject_BuiltIn.cc        
//------------------------------------------------------------------------------
 
  cout << "mVar: " << mVar << endl; 
  cout << "mOb1: " << mOb1 << ", mOb2: " << mOb2 << endl; 
  for( int i; i<2; i++ ){ cout << "mObj[]: " << mOb3[i] << endl; }
}
