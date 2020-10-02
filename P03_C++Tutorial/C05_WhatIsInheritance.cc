//******************************************************************************
// Introduction to C++ for Geant4 Users:  継承(inheritance)とは何か
//******************************************************************************
#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// [演習 1]  Baseクラス'Shape_2P'を作る - 2つのパラメータで表現できる図形クラス
//         (手順)  Hands-onのスライドを参照し、次行の「？」部分を書き換えて、クラスを完成させる
//-----------------------------------------------------------------------------
    
????? Shape_2P {                          // [問] Shape_2Pクラス宣言
  ???????                                 // [問] publicメンバー（データと関数）の定義
    string shape(){ return name; }        // 図形名をstring型で返す関数の定義
    double area(){ return 0.; }           // 面積をdouble型で返す関数の定義

  ??????????                              // [問] protectedメンバー（データと関数)の定義
    double sizeX, sizeY;                  // 図形サイズの二つのパラメター値
    string name = "Shape_2P";             // 図形の名前
    const double pi = 3.14159265;         // pi 定数値
};

//-----------------------------------------------------------------------------
// [演習 2]  Rectangular クラスを作る - Shape_2Pを継承し、constructorとarea()関数を実装する
//         (手順)  sampleコードを参照し、次行の「？」部分を書き換えて、クラスを完成させる
//-----------------------------------------------------------------------------
                    
class Rectangular ? ?????? Shape_2P {     // [問] Shape_2Pクラスを継承しRectangularクラス宣言
  public:                                 // publicメンバー（データと関数）の定義 
    ???????????( double x, double y ) {   // [問] Recutangularのconstructorの定義
      sizeX = x; sizeY = y; name = "Rectangular"; }
    double ????() { return sizeX * sizeY; } // [問] area関数の再定義
};


//-----------------------------------------------------------------------------
// [演習 3]  Ellipse クラスを作る - Shape_2Pを継承し、constructorとarea()関数を実装する
//         (手順)  sampleコードを参照し、次行の「？」部分を書き換えて、クラスを完成させる
//-----------------------------------------------------------------------------

class Ellipse ? ?????? Shape_2P {          // [問] Shape_2Pクラスを継承しEllipseクラス宣言
  public:                                  // publicメンバー（データと関数）の定義 
    ???????( double x, double y ) {        // [問] Ellipseのconstructorの定義
      sizeX = x; sizeY = y; name = "Ellipse"; } 
    double ????(){ return sizeX * sizeY * pi/4.0; } // [問] area関数の再定義
};

//-----------------------------------------------------------------------------
// [演習 4]  Rectangular / Ellipse クラスを使う
//         (手順)  右側のコメントに従い、「？」部分を部分を書き換えて'main()'プログラムを完成させる
//                次に、以下のコマンドでプログラムを実行し結果を見る
//                  % c++ C05_WhatIsInheritance.cc
//-----------------------------------------------------------------------------

int main() {

  Shape_2P aShape{};                    // 'Shape_2P'のオブジェクトを作成
    cout << aShape.shape() << ": "      // 'aShape'が持つshape()関数へアクセス
         << aShape?area() << endl;      // [問] 'aShape'が持つarea()関数へアクセス

  Rectangular aRect{ 2.0, 3.0 };        // 'Rectangular'のオブジェクトを作成
    cout << aRect.shape() << ": "       // 'aRect'が持つshape()関数へアクセス
         << aRect?area() << endl;       // '[問] 'aRect'が持つarea()関数へアクセス

  Ellipse aElli{ 2.0, 3.0 };            // 'Ellipse'のオブジェクトへを作成
    cout << aElli.shape() << ": "       // 'aElli'が持つshape()関数へアクセス
         << aElli?area() << endl;       // [問] 'aElli'が持つarea()関数へアクセス
}
