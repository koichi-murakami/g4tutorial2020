//******************************************************************************
// Introduction to C++ for Geant4 Users: ポインター・タイプ と レファレンス・タイプ
//******************************************************************************
#include <iostream>
#include <vector>
using namespace std;
float* makeData( int );
void PassVal( double );
void PassRef( double& );


//------------------------------------------------------------------------------
// [演習 1]  ポインタを理解する
//          (手順)  sampleコードを参照し、次行の「？」部分を完成させ、プログラムを実行する
//------------------------------------------------------------------------------

int main() {

// ポインタ(ポインタ・タイプのオブジェクト)を作成する
  int ei = 123;                      // intオブジェクトの作成
  int mi = 123;                      // [問] 上と同じタイプのオブジェクトを作成

  vector<double> evec = vector<double>{ 1.23, 2.34, 3.45 }; // vectorオブジェクトの作成
  vector<double> mvec = vector<double>{ 1.23, 2.34, 3.45 }; // [問] 上と同じタイプのオブジェクトを作成

  int* eip = &ei;                    // intオブジェクトへのポインタ作成
  int* mip = &mi;                    // [問] 上と同じタイプのオブジェクトを作成

  vector<double>*  evecp = &evec;    // vectorオブジェクトへのポインタ作成
  vector<double>*  mvecp = &mvec;    // [問] 上と同じタイプのオブジェクトを作成

// ポインタからそれが指すオブジェクトを取得する - dereferencing
  int ej = *eip;                     // intオブジェクトへのポインタからintオブジェクトを取得
  int mj = *mip;                     // [問] 上と同じタイプのオブジェクトを作成

  vector<double> evecc = *evecp;     // vectorオブジェクトへのポインタからvectorオブジェクトを取得
  vector<double> mvecc = *mvecp;     // [問] 上と同じタイプのオブジェクトを作成

// ポインタが指すオブジェクトのmember関数を使う
  int evecp_Size = evecp->size();    // vectorタイプの関数 "size()"を使い、要素の総数を取得
  int mvecp_Size = mvecp->size();    // [問] 上と同じように関数を使う

  double evecp_At = evecp->at(1);    // vectorタイプの関数 "at()"を使い、2番目要素の値を取得    
  double mvecp_At = mvecp->at(1);    // [問] 上と同じように関数を使う    

  double evec_At = evec.at(1);       // ポインタからでなく直接オブジェクトから関数"at()"を使う場合    
  double mvec_At = mvec.at(1);       // [問] 上と同じように関数を使う    

// ポインタとオペレター 'new' - 'new'は必ずポインターを返す
  vector<double>* evecnp = new vector<double>{ 1.23, 2.34, 3.45 }; // newを使ったオブジェクトの作成
  vector<double>* mvecnp = new vector<double>{ 1.23, 2.34, 3.45 }; // [問] 上と同じようにnewを使う

// 'new'の必要性 - 大量の情報を持つオブジェクトを作りたい場合
  int size = 3000000;
  float* array = new float[ size ];  // [問] この行と下の行を入れ替えて何が起こるかを調べよ
  // float array[ size ];            //      この行を生かすとsegment faultが生じる  
 

//------------------------------------------------------------------------------
// [演習 2]  レファレンスを理解する
//          (手順)  sampleコードを参照し、次行の「？」部分を完成させ、プログラムを実行する
//------------------------------------------------------------------------------

// レファレンス(レファレンス・タイプのオブジェクト)を作成する - レファレンスは「参照」とも呼ばれる
  int ek = 456;                      // 'int'オブジェクトの作成
  int mk = 456;                      // [問] 上と同じように'int'オブジェクトを作成

  int& ekr = ek;                     // 'int'タイプのレファレンス・オブジェクトを作成 
  int& mkr = mk;                     // [問] 上と同じように'int'タイプのレファレンスを作成
                                     //      'mk'と'mkr'は同じmemory addressを持つ

// レファレンスは関数の引数受け渡しに使われることが多い 
//  - 上の演習のようにレファレンス・オブジェクトを作成してそれを使うことは余りない

  // [問] この演習ファイルの最後に定義されている"PassVal()"関数を参照し、関数を実行すると
  //      'eVal'の値が '1.23'となることを理解せよ
  //      (答) 'eVal'は関数内部でコピーが作られ、このコピー・オブジェクトに対して関数操作が実行される
  double eVal = 1.23;
  PassVal( eVal );                   // 値渡しの関数を使う

  // [問] この演習ファイルの最後に定義されている"PassRef()"関数の定義を参照し、関数を実行すると
  //      'mVal'の値が '11.23'となることを理解せよ
  //      (答) 'mVal'は関数内部でコピーされず、直接このオブジェクトに対して関数操作が実行される
  double mVal = 1.23;
  PassRef( mVal );                   // reference渡しの関数を使う

//------------------------------------------------------------------------------
// [演習 3]  上で作ったオブジェクトが持つ情報を書き出す
//    * 以下のコマンドでプログラムを実行し結果を見る
//       % c++ C03_PointerReference.cc        
//------------------------------------------------------------------------------

  cout << "Start Value (mi): " << mi << endl; 
  for( double v : mvec ) { cout << "mvec<>: " << v << endl; } // range-based-loop  
  cout << "Pointer (mip) / Value (mj): " << mip << " / " << mj << endl; 
  for( double v : mvecc ) { cout << "Pointer (mvecp) / Value (mvecc[]): " << mvecp << " / " << v << endl; } // range-based-loop  

  cout << "Size  (mpvec->size()): " << mvecp_Size << endl; 
  cout << "Value (mvecp->at(1)): "  << mvecp_At   << endl; 
  cout << "Value (mvec.at(1)): "    << mvec_At    << endl; 

  cout << "Adress (&mk): " << &mk << endl;
  cout << "Reference (&mkr) / Reference Value (mkr): " << &mkr << " / " << mkr << endl;
  cout << "PassVal (eVal) / PassRef (mVal): " << eVal << " / " << mVal << endl;
}


//------------------------------------------------------------------------------
// [ 演習２で使用している関数の定義 ]
//------------------------------------------------------------------------------

// 通常の値渡しの関数を'PassVal()'の定義
  void PassVal( double  val ) { val += 10; }    // 引数に'10'を加算する

// reference渡しの関数を'PassRef()'の定義
  void PassRef( double& val ) { val += 10; }    // 引数に'10'を加算する

