//******************************************************************************
// Introduction to C++ for Geant4 Users:  PolymorphismとVirtual Functionとは何か
//******************************************************************************
#include <iostream>
#include <string>
using namespace std;

//-----------------------------------------------------------------------------
// 以下の'Shape_2P','Rectangular','Ellispe'のクラス定義は直前のhands-onのコードと全く同じ
//-----------------------------------------------------------------------------

class Shape_2P {                          // classの宣言
  public:                                 // publicメンバー（データと関数）の定義
    string shape(){ return name; }        // 図形名をstring型で返す関数の定義
    double area(){ return 0.; }           // 面積をdouble型で返す関数の定義
  protected:                              // protectedメンバー（データと関数)の定義
    double sizeX, sizeY;                  // 図形サイズの二つのパラメター値
    string name = "Shape_2P";             // 図形の名前
    const double pi = 3.14159265;         // pi 定数値
};

class Rectangular : public Shape_2P {     // Shape_2Pクラスを継承しRectangularクラス宣言
  public:                                 // publicメンバー（データと関数）の定義 
    Rectangular( double x, double y ) {   // Recutangularのconstructorの定義
      sizeX = x; sizeY = y; name = "Rectangular"; }
    double area() { return sizeX * sizeY; } // area関数の再定義
};

class Ellipse : public Shape_2P {          // Shape_2Pクラスを継承しEllipseクラス宣言
  public:                                  // publicメンバー（データと関数）の定義 
    Ellipse( double x, double y ) {        // Ellipseのconstructorの定義
      sizeX = x; sizeY = y; name = "Ellipse"; } 
    double area(){ return sizeX * sizeY * pi/4.0; } // area関数の再定義
};

//-----------------------------------------------------------------------------
// [演習 1]  'Rectangular','Ellispe'のオブジェクトに'Shape_2P'のポインタを経由してアクセスする
//         (手順)  右側のコメントに従い、「？」部分を部分を書き換えて'main()'プログラムを完成させる
//                次に、以下のコマンドでプログラムを実行し結果を見る
//                  % c++ C06_WhatIsVirtualFunction.cc
//-----------------------------------------------------------------------------

int main() {
  Shape_2P aShape{};                   // 'Shape_2P'のオブジェクトを作成
  Rectangular aRect{ 2.0, 3.0 };       // 'Rectangular'のオブジェクトを作成
  Ellipse aElli{ 2.0, 3.0 };           // 'Ellipse'のオブジェクトへを作成 

  Shape_2P* pShape;                    // 'Shape_2P'のオブジェクトへのポインタ(pShape)を作成

  pShape = &aShape;                    // 'pShape'に'Shape_2P'のオブジェクトへのポインタを設定
    cout << pShape->shape() << ": "    // 'pShape'が持つshape()関数へアクセス
         << pShape??area() << endl;    // [問] 'pShape'が持つaread()関数へアクセス
 
 pShape = &aRect;                      // 'pShape'に'Rectangluar'のオブジェクトへのポインタを設定
    cout << pShape->shape() << ": "    // 'pShape'が持つshape()関数へアクセス
         << pShape??area() << endl;    // [問] 'pShape'が持つarea()関数へアクセス

  pShape = &aElli;                     // 'pShape'に'Ellipse'のオブジェクトへのポインタを設定
    cout << pShape->shape() << ": "    // 'pShape'が持つshape()関数へアクセス 
         << pShape??area() << endl;    // [問] 'pShape'が持つarea()関数へアクセス


//-----------------------------------------------------------------------------
// [演習 2]  virtual関数の定義
//         (手順) 'Shape_2P'定義の15行目を以下の様に変更した後、main()を実行し、[演習１]の結果と比べよ
//                15行目：   double area(){ return 0.; } 
//                            ---> virtual double area(){ return 0.; }
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// [演習 3]  pure virtual関数の定義
//         (手順) 'Shape_2P'定義の15行目を以下の様に変更した後、main()を実行し、[演習１]の結果と比べよ
//                15行目：   virtual double area(){ return 0.; } 
//                            ---> virtual double area() = 0;
//          [注] 実行すると'compile error'となる。その理由は、Shape_2Parea()関数がpure vartualに
//               なったため、main()の44行目のShape_2Pオブジェクト作成が不当となった。
//               'error'修正には、44行目と50から52行目をコメントアウトする
//-----------------------------------------------------------------------------

}

