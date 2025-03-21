# ST8G_ProMini

<img src="https://github.com/akita11/STC8G_ProMini/blob/main/STC8G_ProMini.jpg" width="240px">

<img src="https://github.com/akita11/STC8G_ProMini/blob/main/STC8G_ProMini2.jpg" width="240px">

中国[STCmicro(宏晶科技)](https://www.stcmicro.com/)の8ビットマイコンSTC8G2K322を使った、Arduino Pro Mini型のマイコンボードです。
主な特徴は以下のとおりです。

- Arduino Pro Mini型（プログラム書き込みは、FTDI-Basicまたはその互換のUSB-シリアル変換器が必要です→[例](https://www.switch-science.com/catalog/1032/)）
- 電源電圧5V
- 全ピンアナログ入力・PWM出力可能
- RAM=2KB, フラッシュ=32KB
- 通信機能: UARTx4、SPI、I2C

またArduino Pro Miniとは、以下のような違いがあります。
- 現時点ではArduinoIDEでのプログラム開発環境はありませんが、[それを実現する進行中のプロジェクト](https://github.com/akita11/nulllab_stc51duino)があります。
- RAW端子に、外部電源から+7V以上を供給可能で、ボード上のレギュレータで+5Vを生成します。


## ピン配置

ボード上のArduino Pro Miniのピン位置とSTC8G2K32のピン名称との対応は以下の通りです。

- D0 - D7 : P3.0 - P3.7
- D8 - D13 : P2.0 - P2.5
- A0 - A7 : P1.0 - P1.7

基板上の"LED"（オレンジ）はP2.5（D13の位置）で駆動できます。詳細は[回路図](https://github.com/akita11/STC8G_ProMini/blob/main/STC8G_ProMini_sch.pdf)を参照してください。


## プログラムのコンパイルと書き込み

現時点では、ArduinoIDEは使えませんので、プログラムのコンパイルと書き込みは、それぞれ別のツールを使うことになります。（[使い方のメモ](https://note.com/akita11/n/n41316faaaf19)も参照してください）

### プログラムのコンパイル

STC8Gマイコンは8051コアですので、フリーから商用のものまでいろいろなコンパイラがあります。動作確認をしたものを照会しておきます。またsourceフォルダ以下に、プログラム例があります（ビルド方法は、以下のKsylitoliの手順を参照）。

- SDCC（オープンソースなコンパイラ）。Macでの使用例は[Ksylitoli](https://github.com/creeper0723/Ksylitoli)の説明がわかりやすいです。またWindows用やLinux用もあります（SDCC公式サイトからダウンロードできる）
- [FwLib_STC8](https://note.com/akita11/n/n41316faaaf19)。簡易ライブラリですが、レジスタ定義ファイルを流用できます。


### プログラムの書き込み

[STCmicro](https://www.stcmicro.com/rjxz.html)のWebページから、書き込みツールSTC-ISPをダウロードします。

<img src="https://github.com/akita11/STC8G_ProMini/blob/main/STC-ISP.png" width="240px">

USB-シリアル変換器をPCに接続し（初回時は、ここではまだSTC8G_ProMiniは接続しない）、STC-ISPを起動し、以下の設定をします。
- "MCU Type"で、**STC8G2K32S4**を選択
- "Scan Port"には、接続しているUSB-シリアル変換器のCOMポートを選択
- "Open Code File"で、コンパイルで得られた*.binを指定
- "H/W Option"で、**RESET pin used as I/O port**のチェックを**はずす**（これのチェックが入っていると、RSTピンが通常のI/Oピン(P5.4)となり、リセットSWやFTDI-Basicからのリセットがかけられません。それでもよいのでP5.4を通常のI/Oとして使用する場合はチェックを入れる）
- 内部フラッシュ内のキャリブレーション情報を使う場合は、**Add a reset code in front of ID**をチェックする

設定が済んだら、"Download/Program"ボタンを押します。

<img src="https://github.com/akita11/STC8G_ProMini/blob/main/connection.jpg" width="240px">

初回時のみ、その後で、FTDI-BasicにSTC8G_ProMiniを、向きに注意して接続します。（FTDI-BasicのGNDと、STC8G_ProMiniの"BLK"が揃う向き）すぐに書き込みが始まります。終了したらRSTスイッチでリセットするとプログラムが実行されます。
STC-ISPの設定で、RSTピンを使うように指定してあれば、2回目以降は、FTDI-Basicに接続したままで、Download/Promramを押すだけで自動でリセットがかかり、書き込みができます。


## Author

Junichi Akita (@akita11) / akita@ifdl.jp

