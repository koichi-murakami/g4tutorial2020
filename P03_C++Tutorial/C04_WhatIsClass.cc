//******************************************************************************
// Introduction to C++ for Geant4 Users: クラスとは何か
//******************************************************************************
#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// [演習 1] Rectangularクラスを作る
//         (手順)  Hands-onのスライドを参照し、以下の「？」部分を書き換えて、クラスを完成させる
//-----------------------------------------------------------------------------

????? Rectangular {                       // [問] classの宣言
  ???????                                 // [問] publicメンバー定義 （データと関数）
    ???????????( double x, double y ) {   // [問] constructor(classと同名の関数)の定義
      sizeX = x; sizeY = y; }          
    string shape() { return "Rectangular"; }  // 図形名をstring型で返す関数の定義
    double area() { return sizeX*sizeY; }     // 面積をdouble型で返す関数の定義
  ????????                                // [問] privateメンバーの定義 （データと関数）
    double sizeX, sizeY;                          
};

//-----------------------------------------------------------------------------
// [演習 2] Rectangularクラスを使う
//   * 以下の「？」部分を部分を書き換えて'main()'プログラムを完成させる
//   * 次に、以下のコマンドでプログラムを実行し結果を見る
//      % c++ C02_WhatIsClass.cc
//-----------------------------------------------------------------------------

int main() {
  ??????????? rc{ 3.0, 4.0 };               // [問] Rectangular オブジェクト(rc)の生成
  cout << "Shape: " << rc?shape() << endl;  // [問] rcの'shape()'関数を使う
  cout << "Area:  " << rc?area()  << endl;  // [問] rcの'area()'関数を使う
}
