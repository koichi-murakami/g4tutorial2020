//******************************************************************************
// Introduction to C++ for Geant4 Users: オブジェクトとは何か - 2
//******************************************************************************

//------------------------------------------------------------------------------
// [演習 1]  標準ライブラリ(C++ Standard Library)が提供するタイプのオブジェクト作成方法の習得
//          (手順)  sampleコードを参照し、次行の「？」部分を完成させ、プログラムを実行する
//------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <complex>
using namespace std;

int main() {
 
// stringタイプのオブジェクトを作り初期化
  string eOb1{ "Hello World!" };      // example コード
  ?????? mOb1? "Hello Geant4" ?;      // [問] 上と同じタイプのオブジェクトを作り初期化

  //--- stringタイプが持つmember関数 "length()"を使用し、データの文字数を取得する
  int eOb1_Leng = eOb1.length();      // example コード
  ??? mOb1_Leng = mOb1?length();      // [問] 上と同じタイプのオブジェクトを作り初期化

// vectorタイプのオブジェクトを作り初期化 (doubleの要素を持つ)
  vector<double> eOb2{ 1.23, 4.56 };  // example コード
  ??????<double> mOb2? 9.87, 6.54 ?;  // [問] 上と同じタイプのオブジェクトを作り初期化

  //--- vectorタイプが持つmember関数 "size()"を使用し、全要素の数を取得する
  int eOb2_Size = eOb2.size();        // example コード
  ??? mOb2_Size = mOb2?size();        // [問] 上と同じタイプのオブジェクトを作り初期化

  //--- vectorタイプが持つmember関数 "at()"を使用し、２番目の要素のデータを取得
  double eVal_2 = eOb2.at(1);         // example コード
  ?????? mVal_2 = mOb2?at(1);         // [問] 上と同じ情報を取得する


///------------------------------------------------------------------------------
// [演習 2]  上で作ったオブジェクトが持つ情報を書き出す
//    * 以下のコマンドでプログラムを実行し結果を見る
//       % c++ C02_WhatIsObject_SDLibrary.cc        
//------------------------------------------------------------------------------
 
//--- stringタイプ
  cout << "mOb1: " << mOb1 << endl;
  cout << "mOb1 (Length): " << mOb1_Leng << endl; 
//--- vectorタイプ
  for( float v : mOb2 ) { cout << "mOb2<>: " << v << endl; } // range-based-loop
  cout << "mOb2 (Size): " << mOb2_Size << endl;
  cout << "mOb2(1): " << mVal_2 << endl;
}
