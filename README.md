# LibFromfile
倍精度浮動小数点数のバイナリデータを読み込む(書き込む)ライブラリ。

## 使い方
`DFloat` 構造体を用いて倍精度浮動小数点数の配列を扱う。構造体の定義は以下の通り。 
`.data` が配列のポインタで、`.size` が倍精度浮動小数点数の配列サイズ。

```c
typedef struct __DFloat{
    double* data;
    long size;
} DFloat;
```

### データを読み込む場合(fromfile)
データを読み込む場合は、動的にメモリーが確保されるため `free()` する必要がある。
予め、動的にメモリーを確保する必要はない。

```c
DFloat dFloatFromFile(const char* filename);
```

filename: ファイル名
戻り値: データ

### データを書き込む場合(tofile)
`DFloat` 構造体の `.data` に配列のポインタを設定、配列のサイズを `.size` に設定する。

```c
DFloat dFloat2file(const char* filename, DFloat data);
```

filename: ファイル名
data: データ
戻り値: データ (data と同じ)

## サンプル
```c
#include <fromfile.h>

int main(void){
    DFloat data;

    double d[100];
    data.data = d;
    data.size = 100;
    for(int i = 0; i < 100; i++) d[i] = i / 10.0;

    dFloat2file("data.bin", data);

    DFloat data2 = dFloatFromFile("data.bin");
    dFloatPrint(data2);
    dFloatFree(data2);

    return 0;
}
```

## インストール方法

### Ubuntu
```sh
wget https://github.com/Himeyama/libfromfile/releases/download/2.0/libfromfile.deb
sudo apt install ./libfromfile.deb
```

```sh
curl -s https://raw.githubusercontent.com/Himeyama/libfromfile/main/install.sh | bash
```
